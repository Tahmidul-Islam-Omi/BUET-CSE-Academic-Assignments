#! /usr/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <submissions_dir> <targets_dir> <tests_dir> <answers_dir>"
    exit 1
fi

# Assign command-line arguments to variables
submissions_dir="$1"
targets_dir="$2"
tests_dir="$3"
answers_dir="$4"

mkdir -p "$targets_dir"
cd "$targets_dir"
mkdir -p C C++ Python Java
cd ..

cd "$submissions_dir"

for zipfile in *.zip; do
    unzip -o "$zipfile" > /dev/null
done

for folder in */; do
    foldername="${folder%/}"
    
    student_name="${foldername%%_*}"
    student_id="${foldername: -7}"

    echo "${student_name}":"${student_id}" >> "../student_mapping.txt"

    find "$foldername" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.py" -o -name "*.java" \) | while read -r file; do
        if [[ "${file}" == *.c ]]; then
            mkdir -p "../$targets_dir/C/${student_id}"
            cp "${file}" "../$targets_dir/C/${student_id}/main.c"

        elif [[ "${file}" == *.cpp ]]; then
            mkdir -p "../$targets_dir/C++/${student_id}"
            cp "${file}" "../$targets_dir/C++/${student_id}/main.cpp"

        elif [[ "${file}" == *.py ]]; then
            mkdir -p "../$targets_dir/Python/${student_id}"
            cp "${file}" "../$targets_dir/Python/${student_id}/main.py"

        elif [[ "${file}" == *.java ]]; then
            mkdir -p "../$targets_dir/Java/${student_id}"
            cp "${file}" "../$targets_dir/Java/${student_id}/Main.java"
        fi
    done
done

echo "student_id,student_name,language,matched,not_matched,line_count,comment_count,function_count" >> "../$targets_dir/result.csv"

cd "../$targets_dir"

for language_folder in */; do
    for student_id_folder in "${language_folder}"*/; do
        for file in "${student_id_folder}"*; do
            line_count=$(wc -l < "$file")
            comment_count=0
            function_count=0
            file_extension="${file##*.}"
            matched_count=0
            unmatched_count=0
            language=""
            
            if [[ "${file_extension}" == "c" ]]; then
                language="C"
            elif [[ "${file_extension}" == "cpp" ]]; then
                language="C++"
            elif [[ "${file_extension}" == "py" ]]; then
                language="Python"
            elif [[ "${file_extension}" == "java" ]]; then
                language="Java"
            fi
            

            if [[ "${file_extension}" == "c" ]]; then
                function_count=$(grep -c -E '(\w+\s+)+\w+\s*\([^;]*\)\s*(\{|$)' "$file")
                # Count both single-line and multi-line comments
                single_comments=$(grep -c '//' "$file")
                multi_comments=$(grep -c '/\*' "$file")
                comment_count=$((single_comments + multi_comments))
            elif [[ "${file_extension}" == "cpp" ]]; then
                # Count both regular functions and class methods
                function_count=$(grep -c -E '(\w+\s+)+\w+::\w+\s*\([^;]*\)\s*(\{|$)|(\w+\s+)+\w+\s*\([^;]*\)\s*(\{|$)' "$file")
                # Count both single-line and multi-line comments
                single_comments=$(grep -c '//' "$file")
                multi_comments=$(grep -c '/\*' "$file")
                comment_count=$((single_comments + multi_comments))
            elif [[ "${file_extension}" == "py" ]]; then    
                function_count=$(grep -c -E '^\s*def\s+' "$file")
                # Count both single-line and docstring comments
                single_comments=$(grep -c '#' "$file")
                triple_quotes=$(grep -c '"""' "$file")
                # Each pair of triple quotes counts as one multi-line comment
                multi_comments=$((triple_quotes / 2))
                comment_count=$((single_comments + multi_comments))
            elif [[ "${file_extension}" == "java" ]]; then
                function_count=$(grep -c -E '^(public|private|protected|static|[[:space:]])+[a-zA-Z_][a-zA-Z0-9_<>]*[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\([^)]*\)[[:space:]]*\{?' "$file")
                # Count both single-line and multi-line comments
                single_comments=$(grep -c '//' "$file")
                multi_comments=$(grep -c '/\*' "$file")
                comment_count=$((single_comments + multi_comments))
            fi

            for testfile in ../$tests_dir/*; do
                testfile_name=$(basename "$testfile")
                filenumber="${testfile_name:4:1}" 

                output_file="$(dirname "$file")/out${filenumber}.txt"
                answer_file="../$answers_dir/ans${filenumber}.txt"
                
                if [[ "${file_extension}" == "c" ]]; then
                    gcc "${file}" -o "${file%.c}"
                    "${file%.c}" < "${testfile}" > "${output_file}"
                    
                elif [[ "${file_extension}" == "cpp" ]]; then
                    g++ "${file}" -o "${file%.cpp}"
                    "${file%.cpp}" < "${testfile}" > "${output_file}"
                    
                elif [[ "${file_extension}" == "py" ]]; then
                    python3 "${file}" < "${testfile}" > "${output_file}"

                elif [[ "${file_extension}" == "java" ]]; then
                    javac "${file}"
                    java -cp "${student_id_folder}" Main < "${testfile}" > "${output_file}"
                fi

                # Compare output with answer file
                if diff "${output_file}" "${answer_file}" > /dev/null; then
                    ((matched_count++))
                else
                    ((unmatched_count++))
                fi
            done
            

            # Extract the digits from student_id_folder
            student_id_digits=$(echo "${student_id_folder}" | grep -o '[0-9]\+')

            # Fetch the student name from student_mapping.txt
            student_name=$(grep "${student_id_digits}" "../student_mapping.txt" | cut -d':' -f1)
            
            echo "${student_id_digits}","${student_name}","${language}","${matched_count}","${unmatched_count}","${line_count}","${comment_count}","${function_count}" >> "result.csv"    
        done
    done
done


