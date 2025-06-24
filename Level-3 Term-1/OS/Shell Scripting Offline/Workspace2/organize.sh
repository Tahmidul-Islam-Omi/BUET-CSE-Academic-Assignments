#! /usr/bin/bash

# Initialize flags with default values
verbose=false
execute=true
include_line_count=true
include_comment_count=true
include_function_count=true

# Function to display usage information
usage() {
    echo "Usage: $0 <submissions_dir> <targets_dir> <tests_dir> <answers_dir> [options]"
    echo "Options:"
    echo "  -v            Verbose mode. Print information about processing."
    echo "  -noexecute    Skip execution tasks and output file generation."
    echo "  -nolc         Do not calculate line count in code metrics."
    echo "  -nocc         Do not calculate comment count in code metrics."
    echo "  -nofc         Do not calculate function count in code metrics."
    exit 1
}

# Parse command-line arguments
required_args=()
for arg in "$@"; do
    case $arg in
        -v)
            verbose=true
            ;;
        -noexecute)
            execute=false
            ;;
        -nolc)
            include_line_count=false
            ;;
        -nocc)
            include_comment_count=false
            ;;
        -nofc)
            include_function_count=false
            ;;
        -*)
            echo "Unknown option: $arg"
            usage
            ;;
        *)
            required_args+=("$arg")
            ;;
    esac
done

# Check if the correct number of required arguments is provided
if [ ${#required_args[@]} -ne 4 ]; then
    echo "Error: Missing required arguments."
    usage
fi

# Assign required arguments to variables
submissions_dir="${required_args[0]}"
targets_dir="${required_args[1]}"
tests_dir="${required_args[2]}"
answers_dir="${required_args[3]}"

# Store the base directory for easier navigation
BASEDIR=$(pwd)

# Define function to process each file (count metrics and run tests)
function process_file() {
    local file=$1
    local language=$2
    local student_id=$3
    local student_name=$4
    
    # Display processing information if verbose mode is enabled
    if $verbose; then
        echo "Organizing files of ${student_id}"
    fi
    
    if $execute; then
        echo "Executing files of ${student_id}"
    fi
    # Initialize variables for metrics
    line_count=0
    comment_count=0
    function_count=0
    matched_count=0
    unmatched_count=0
    file_extension="${file##*.}"
    
    # Calculate line count if enabled
    if $include_line_count; then
        line_count=$(wc -l < "$file")
    fi
    
    # Count functions and comments based on file type
    if [[ "${file_extension}" == "c" ]]; then
        if $include_function_count; then
            function_count=$(grep -c -E '(\w+\s+)+\w+\s*\([^;]*\)\s*(\{|$)' "$file")
        fi
        if $include_comment_count; then
            single_comments=$(grep -c '//' "$file")
            multi_comments=$(grep -c '/\*' "$file")
            comment_count=$((single_comments + multi_comments))
        fi
    elif [[ "${file_extension}" == "cpp" ]]; then
        if $include_function_count; then
            function_count=$(grep -c -E '(\w+\s+)+\w+::\w+\s*\([^;]*\)\s*(\{|$)|(\w+\s+)+\w+\s*\([^;]*\)\s*(\{|$)' "$file")
        fi
        if $include_comment_count; then
            single_comments=$(grep -c '//' "$file")
            multi_comments=$(grep -c '/\*' "$file")
            comment_count=$((single_comments + multi_comments))
        fi
    elif [[ "${file_extension}" == "py" ]]; then    
        if $include_function_count; then
            function_count=$(grep -c -E '^\s*def\s+' "$file")
        fi
        if $include_comment_count; then
            single_comments=$(grep -c '#' "$file")
            triple_quotes=$(grep -c '"""' "$file")
            multi_comments=$((triple_quotes / 2))
            comment_count=$((single_comments + multi_comments))
        fi
    elif [[ "${file_extension}" == "java" ]]; then
        if $include_function_count; then
            function_count=$(grep -c -E '^(public|private|protected|static|[[:space:]])+[a-zA-Z_][a-zA-Z0-9_<>]*[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\([^)]*\)[[:space:]]*\{?' "$file")
        fi
        if $include_comment_count; then
            single_comments=$(grep -c '//' "$file")
            multi_comments=$(grep -c '/\*' "$file")
            comment_count=$((single_comments + multi_comments))
        fi
    fi
    
    # Run tests if execution is enabled
    if $execute; then
        
        for testfile in "$BASEDIR/$tests_dir"/*; do
            testfile_name=$(basename "$testfile")
            filenumber="${testfile_name:4:1}" 
            
            output_file="out${filenumber}.txt"
            answer_file="$BASEDIR/$answers_dir/ans${filenumber}.txt"
            
            # Compile and run the code
            if [[ "${file_extension}" == "c" ]]; then
                gcc "$file" -o "${file%.c}"
                ./"${file%.c}" < "$testfile" > "$output_file"
                
            elif [[ "${file_extension}" == "cpp" ]]; then
                g++ "$file" -o "${file%.cpp}"
                ./"${file%.cpp}" < "$testfile" > "$output_file"
                
            elif [[ "${file_extension}" == "py" ]]; then
                python3 "$file" < "$testfile" > "$output_file"
                
            elif [[ "${file_extension}" == "java" ]]; then
                javac "$file"
                java Main < "$testfile" > "$output_file"
            fi
            
            # Compare output with answer file
            if diff "$output_file" "$answer_file" > /dev/null; then
                ((matched_count++))
            else
                ((unmatched_count++))
            fi
        done
    fi
    
    # Prepare CSV header and row dynamically based on enabled metrics
    local csv_row="$student_id,$student_name,$language"
    
    # Add execution results if enabled
    if $execute; then
        csv_row="$csv_row,$matched_count,$unmatched_count"
    fi
    
    # Add metrics if enabled
    if $include_line_count; then
        csv_row="$csv_row,$line_count"
    fi
    if $include_comment_count; then
        csv_row="$csv_row,$comment_count"
    fi
    if $include_function_count; then
        csv_row="$csv_row,$function_count"
    fi
    
    # Write results to CSV
    echo "$csv_row" >> "$BASEDIR/$targets_dir/result.csv"
}

# Create target directories
mkdir -p "$targets_dir"
mkdir -p "$targets_dir/C" "$targets_dir/C++" "$targets_dir/Python" "$targets_dir/Java"

# Create CSV header dynamically based on enabled metrics
csv_header="student_id,student_name,language"
if $execute; then
    csv_header="$csv_header,matched,not_matched"
fi
if $include_line_count; then
    csv_header="$csv_header,line_count"
fi
if $include_comment_count; then
    csv_header="$csv_header,comment_count"
fi
if $include_function_count; then
    csv_header="$csv_header,function_count"
fi

# Write CSV header
echo "$csv_header" > "$targets_dir/result.csv"


cd "$submissions_dir"

for zipfile in *.zip; do
    unzip -o "$zipfile" > /dev/null
done

# Delete the student_mapping.txt if it exists, to avoid duplicate entries
rm -f "$BASEDIR/student_mapping.txt"

# Process each student submission
for folder in */; do
    foldername="${folder%/}"
    
    student_name="${foldername%%_*}"
    student_id="${foldername: -7}"

    echo "${student_name}:${student_id}" >> "$BASEDIR/student_mapping.txt"

    # Find and copy source files to their appropriate target directories
    find "$foldername" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.py" -o -name "*.java" \) | while read -r file; do
        if [[ "${file}" == *.c ]]; then
            mkdir -p "$BASEDIR/$targets_dir/C/${student_id}"
            cp "${file}" "$BASEDIR/$targets_dir/C/${student_id}/main.c"
            
            # Process C file immediately
            cd "$BASEDIR/$targets_dir/C/${student_id}"
            process_file "main.c" "C" "${student_id}" "${student_name}"
            cd "$BASEDIR/$submissions_dir"

        elif [[ "${file}" == *.cpp ]]; then
            mkdir -p "$BASEDIR/$targets_dir/C++/${student_id}"
            cp "${file}" "$BASEDIR/$targets_dir/C++/${student_id}/main.cpp"
            
            # Process C++ file immediately
            cd "$BASEDIR/$targets_dir/C++/${student_id}"
            process_file "main.cpp" "C++" "${student_id}" "${student_name}"
            cd "$BASEDIR/$submissions_dir"

        elif [[ "${file}" == *.py ]]; then
            mkdir -p "$BASEDIR/$targets_dir/Python/${student_id}"
            cp "${file}" "$BASEDIR/$targets_dir/Python/${student_id}/main.py"
            
            # Process Python file immediately
            cd "$BASEDIR/$targets_dir/Python/${student_id}"
            process_file "main.py" "Python" "${student_id}" "${student_name}"
            cd "$BASEDIR/$submissions_dir"

        elif [[ "${file}" == *.java ]]; then
            mkdir -p "$BASEDIR/$targets_dir/Java/${student_id}"
            cp "${file}" "$BASEDIR/$targets_dir/Java/${student_id}/Main.java"
            
            # Process Java file immediately
            cd "$BASEDIR/$targets_dir/Java/${student_id}"
            process_file "Main.java" "Java" "${student_id}" "${student_name}"
            cd "$BASEDIR/$submissions_dir"
        fi
    done
done

cd "$BASEDIR"
echo "All submissions processed successfully."


