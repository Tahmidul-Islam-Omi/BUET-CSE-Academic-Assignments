#! /usr/bin/bash

# Create target directories

mkdir targets
cd "targets"
mkdir C C++ Python Java
cd ..

# Create a temporary file for student mapping
student_mapping="/tmp/student_mapping.txt"
touch "$student_mapping"

cd "submissions"

# Unzip all zip files in the submissions folder
for zipfile in *.zip
do
    unzip -o "$zipfile"
done

# Traverse each unzipped folder in submissions
for folder in */ 
do
    # Remove trailing slash for folder name
    foldername="${folder%/}"
    
    # Extract last 7 characters from folder name
    subfolder="${foldername: -7}"  # student id folder

    # Extract student name from subfolder (part before the first underscore)
    student_name="${subfolder%%_*}"
    
    # Store the mapping in a temporary file
    echo "$subfolder:$student_name" >> "$student_mapping"
  

    # Find files and copy to targets
    find "$foldername" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.py" -o -name "*.java" \) | while read file
    do
        if [[ "$file" == *.c ]]; then
            lang_dir="../targets/C"
            mkdir -p "$lang_dir/$subfolder"  # Ensure the directory exists
            cp "$file" "$lang_dir/$subfolder/main.c"
        elif [[ "$file" == *.cpp ]]; then
            lang_dir="../targets/C++"
            mkdir -p "$lang_dir/$subfolder"  # Ensure the directory exists
            cp "$file" "$lang_dir/$subfolder/main.cpp"
        elif [[ "$file" == *.py ]]; then
            lang_dir="../targets/Python"
            mkdir -p "$lang_dir/$subfolder"  # Ensure the directory exists
            cp "$file" "$lang_dir/$subfolder/main.py"
        elif [[ "$file" == *.java ]]; then
            lang_dir="../targets/Java"
            mkdir -p "$lang_dir/$subfolder"  # Ensure the directory exists
            cp "$file" "$lang_dir/$subfolder/Main.java"
        else
            continue
        fi
    done
done

targets_dir="../targets"
output_csv="$targets_dir/result.csv"


# Write CSV header
echo "student_id,student_name,language,matched,not_matched,line_count,comment_count,function_count" > "$output_csv"

# Create a temp directory for outputs
mkdir -p "../temp_outputs"

# Loop through each language folder in targets
for language_folder in "$targets_dir"/*/
do
    language=$(basename "$language_folder")
    # Skip if not a directory or is the result.csv file
    [ -d "$language_folder" ] || continue
    [ "$language" == "result.csv" ] && continue
    
    # Loop through each student folder in the language folder
    for student_folder in "$language_folder"*/; do
        [ -d "$student_folder" ] || continue
        
        student_id=$(basename "$student_folder")
        matched_count=0
        not_matched_count=0
        
        # Loop through each file in the student folder
        for file in "$student_folder"*; do
            [ -f "$file" ] || continue
            filename=$(basename -- "$file")
            extension="${filename##*.}"
            line_count=$(wc -l < "$file")
            comment_count=0
            function_count=0

            case "$extension" in
                py)
                    comment_count=$(grep -c '^\s*#' "$file")
                    function_count=$(grep -c '^\s*def ' "$file")
                    ;;
                c|h)
                    comment_count=$(grep -c '^\s*//' "$file")
                    function_count=$(grep -c '^\s*\w\+\s\+\w\+\s*(' "$file")
                    ;;
                cpp|hpp)
                    comment_count=$(grep -c '^\s*//' "$file")
                    function_count=$(grep -c '^\s*\w\+\s\+\w\+\s*(' "$file")
                    ;;
                java)
                    comment_count=$(grep -c '^\s*//' "$file")
                    function_count=$(grep -c '^\s*\(public\|private\|protected\)\s\+\w\+\s\+\w\+\s*(' "$file")
                    ;;
                *)
                    ;;
            esac
            
            # Compile and run the code for each test file
            for test_file in "../tests/test"*.txt; do
                test_num=$(echo "$test_file" | grep -o '[0-9]\+' | head -1)
                output_file="../temp_outputs/out${test_num}.txt"
                answer_file="../answers/ans${test_num}.txt"
                
                case "$extension" in
                    c)
                        gcc "$file" -o "${file%.c}"
                        if [ $? -eq 0 ]; then
                            cat "$test_file" | "${file%.c}" > "$output_file" 2>/dev/null
                        else
                            echo "Compilation error" > "$output_file"
                        fi
                        # Clean up executable
                        [ -f "${file%.c}" ] && rm "${file%.c}"
                        ;;
                    cpp)
                        g++ "$file" -o "${file%.cpp}"
                        if [ $? -eq 0 ]; then
                            cat "$test_file" | "${file%.cpp}" > "$output_file" 2>/dev/null
                        else
                            echo "Compilation error" > "$output_file"
                        fi
                        # Clean up executable
                        [ -f "${file%.cpp}" ] && rm "${file%.cpp}"
                        ;;
                    py)
                        cat "$test_file" | python3 "$file" > "$output_file" 2>/dev/null
                        ;;
                    java)
                        javac "$file"
                        if [ $? -eq 0 ]; then
                            class_name=$(basename "${file%.java}")
                            cd "$(dirname "$file")"
                            cat "$(realpath "$test_file")" | java "$class_name" > "$(realpath "$output_file")" 2>/dev/null
                            cd - > /dev/null
                        else
                            echo "Compilation error" > "$output_file"
                        fi
                        # Clean up class files
                        find "$(dirname "$file")" -name "*.class" -delete
                        ;;
                esac
                
                # Compare output with answer
                if [ -f "$answer_file" ] && [ -f "$output_file" ]; then
                    if diff -wB "$output_file" "$answer_file" > /dev/null; then
                        matched_count=$((matched_count + 1))
                    else
                        not_matched_count=$((not_matched_count + 1))
                    fi
                else
                    not_matched_count=$((not_matched_count + 1))
                fi
            done
            
            # Add to CSV with matched and not_matched counts
            echo "$student_id,,${language},$matched_count,$not_matched_count,$line_count,$comment_count,$function_count" >> "$output_csv"
        done
    done
done

# Clean up temporary output directory
rm -rf "../temp_outputs"
