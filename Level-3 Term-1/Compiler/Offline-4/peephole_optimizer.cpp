#include "peephole_optimizer.h"
#include <algorithm>
#include <sstream>

using namespace std;

peephole_optimizer::peephole_optimizer() {}

peephole_optimizer::~peephole_optimizer() {}

string peephole_optimizer::trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool peephole_optimizer::isLabel(const string& line) {
    string trimmed = trim(line);
    return !trimmed.empty() && trimmed.back() == ':' && trimmed.find('\t') == string::npos;
}

bool peephole_optimizer::isInstruction(const string& line) {
    string trimmed = trim(line);
    return !trimmed.empty() && trimmed[0] == '\t' && trimmed.find(':') == string::npos;
}

string peephole_optimizer::extract_label(const string& line) {
    string trimmed = trim(line);
    if (isLabel(trimmed)) {
        return trimmed.substr(0, trimmed.length() - 1);
    }
    return "";
}

string peephole_optimizer::get_reg_from_mov(const string& line) {
    regex movRegex(R"(\s*MOV\s+([^,]+)\s*,\s*(.+))");
    smatch match;
    if (regex_match(line, match, movRegex)) {
        return trim(match[1].str());
    }
    return "";
}

string peephole_optimizer::get_dest_from_mov(const string& line) {
    return get_reg_from_mov(line);
}

string peephole_optimizer::get_src_from_mov(const string& line) {
    regex movRegex(R"(\s*MOV\s+([^,]+)\s*,\s*(.+))");
    smatch match;
    if (regex_match(line, match, movRegex)) {
        return trim(match[2].str());
    }
    return "";
}

bool peephole_optimizer::is_redundant_mov(const string& line1, const string& line2) {
    // Check for pattern: MOV AX, a followed by MOV a, AX
    string dest1 = get_dest_from_mov(line1);
    string src1 = get_src_from_mov(line1);
    string dest2 = get_dest_from_mov(line2);
    string src2 = get_src_from_mov(line2);
    
    return !dest1.empty() && !src1.empty() && !dest2.empty() && !src2.empty() &&
           dest1 == src2 && src1 == dest2;
}

bool peephole_optimizer::is_redundant_push_pop(const string& line1, const string& line2) {
    // Check for pattern: PUSH reg followed by POP reg
    regex pushRegex(R"(\s*PUSH\s+(.+))");
    regex popRegex(R"(\s*POP\s+(.+))");
    smatch pushMatch, popMatch;
    
    if (regex_match(line1, pushMatch, pushRegex) && 
        regex_match(line2, popMatch, popRegex)) {
        return trim(pushMatch[1].str()) == trim(popMatch[1].str());
    }
    return false;
}

bool peephole_optimizer::is_redundant_arithmetic(const string& line) {
    string trimmed = trim(line);
    
    // Check for ADD reg, 0
    if (regex_match(trimmed, regex(R"(\s*ADD\s+\w+\s*,\s*0\s*)"))) {
        return true;
    }
    
    // Check for SUB reg, 0  
    if (regex_match(trimmed, regex(R"(\s*SUB\s+\w+\s*,\s*0\s*)"))) {
        return true;
    }
    
    // Check for MUL reg with 1 
    if (regex_match(trimmed, regex(R"(\s*MUL\s+.*)"))) {
  
        return false;
    }
    
    return false;
}

void peephole_optimizer::find_used_label() {
    used_labels.clear();
    
    for (const string& line : asm_code_line) {
        string trimmed = trim(line);
        
        // Find jump instructions that reference labels
        regex jumpRegex(R"(\s*(JMP|JE|JNE|JL|JLE|JG|JGE|JZ|JNZ|CALL)\s+([A-Za-z_][A-Za-z0-9_]*)\s*)");
        smatch match;
        if (regex_match(trimmed, match, jumpRegex)) {
            used_labels.insert(match[2].str());
        }
    }
}

void peephole_optimizer::optimized_redundant_label() {
    find_used_label();
    
    vector<string> optimizedLines;
    string lastLabel = "";
    
    for (size_t i = 0; i < asm_code_line.size(); i++) {
        string line = asm_code_line[i];
        
        if (isLabel(line)) {
            string currentLabel = extract_label(line);
            
            if (lastLabel.empty()) {
                // First label
                lastLabel = currentLabel;
                optimizedLines.push_back(line);
            } else {
        
                label_mapping[currentLabel] = lastLabel;
               
            }
        } else if (isInstruction(line) || !trim(line).empty()) {
           
            lastLabel = "";
            optimizedLines.push_back(line);
        } else {
            // Empty line or comment
            optimizedLines.push_back(line);
        }
    }
    
    // Update jump targets based on label mapping
    for (string& line : optimizedLines) {
        for (const auto& mapping : label_mapping) {
            string oldLabel = mapping.first;
            string newLabel = mapping.second;
            
            // Replace jump targets
            regex jumpRegex(R"(\b)" + oldLabel + R"(\b)");
            line = regex_replace(line, jumpRegex, newLabel);
        }
    }
    
    asm_code_line = optimizedLines;
}

void peephole_optimizer::remove_redundant_mov() {
    vector<string> optimizedLines;
    
    for (size_t i = 0; i < asm_code_line.size(); i++) {
        bool skip = false;
        
        if (i < asm_code_line.size() - 1) {
            string line1 = trim(asm_code_line[i]);
            string line2 = trim(asm_code_line[i + 1]);
            
            if (line1.find("MOV") == 1 && line2.find("MOV") == 1) { 
                if (is_redundant_mov(line1, line2)) {
                    optimizedLines.push_back(asm_code_line[i]); 
                    i++; 
                    skip = true;
                }
            }
        }
        
        if (!skip) {
            optimizedLines.push_back(asm_code_line[i]);
        }
    }
    
    asm_code_line = optimizedLines;
}

void peephole_optimizer::remove_redundant_push_pop() {
    vector<string> optimizedLines;
    
    for (size_t i = 0; i < asm_code_line.size(); i++) {
        bool skip = false;
        
        if (i < asm_code_line.size() - 1) {
            string line1 = trim(asm_code_line[i]);
            string line2 = trim(asm_code_line[i + 1]);
            
            if (is_redundant_push_pop(line1, line2)) {
                // Skip both PUSH and POP
                i++; // Skip next line too
                skip = true;
            }
        }
        
        if (!skip) {
            optimizedLines.push_back(asm_code_line[i]);
        }
    }
    
    asm_code_line = optimizedLines;
}

void peephole_optimizer::remove_redundant_arithmetic() {
    vector<string> optimizedLines;
    
    for (size_t i = 0; i < asm_code_line.size(); i++) {
        string line = asm_code_line[i];
        string trimmed = trim(line);
        
        bool skip = false;
        
        // Handle MUL with 1
        if (i < asm_code_line.size() - 2) {
            string line1 = trim(asm_code_line[i]);
            string line2 = trim(asm_code_line[i + 1]);
            string line3 = trim(asm_code_line[i + 2]);
            
            // Pattern: MOV CX, 1; CWD; MUL CX
            if (regex_match(line1, regex(R"(\s*MOV\s+CX\s*,\s*1\s*)")) &&
                regex_match(line2, regex(R"(\s*CWD\s*)")) &&
                regex_match(line3, regex(R"(\s*MUL\s+CX\s*)"))) {
            
                i += 2; 
                skip = true;
            }
        }
        
        // Handle ADD/SUB with 0
        if (!skip && is_redundant_arithmetic(trimmed)) {
            skip = true;
        }
        
        if (!skip) {
            optimizedLines.push_back(line);
        }
    }
    
    asm_code_line = optimizedLines;
}

bool peephole_optimizer::load_asm_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }
    
    asm_code_line.clear();
    string line;
    while (getline(file, line)) {
        asm_code_line.push_back(line);
    }
    
    file.close();
    return true;
}

void peephole_optimizer::remove_redundant_label() {
    optimized_redundant_label();
}
    
void peephole_optimizer::optimize() {
    cout << "Starting peephole optimization..." << endl;
    
    size_t originalSize = asm_code_line.size();
    
    // Apply optimizations in order
    remove_redundant_push_pop();
    remove_redundant_mov();
    remove_redundant_arithmetic();
    remove_redundant_label(); 
    
    size_t optimizedSize = asm_code_line.size();
    
    cout << "Optimization complete. Removed " << (originalSize - optimizedSize) 
              << " lines." << endl;
}

bool peephole_optimizer::save_optimize_file(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not create output file " << filename << endl;
        return false;
    }
    
    for (const string& line : asm_code_line) {
        file << line << endl;
    }
    
    file.close();
    return true;
}

void peephole_optimizer::printStatistics() {
    cout << "Assembly file contains " << asm_code_line.size() << " lines after optimization." << endl;
}

int main() {
    const string INPUT_FILE = "output/code.asm";
    const string OUTPUT_FILE = "output/optimized_code.asm";
    
    cout << "==================================================" << endl;
    cout << "           PEEPHOLE OPTIMIZER" << endl;
    cout << "==================================================" << endl;
    cout << "Input file:  " << INPUT_FILE << endl;
    cout << "Output file: " << OUTPUT_FILE << endl;
    cout << "==================================================" << endl;
    
    peephole_optimizer optimizer;
    
    // Load the assembly file
    if (!optimizer.load_asm_file(INPUT_FILE)) {
        cerr << "Failed to load input file: " << INPUT_FILE << endl;
        return 1;
    }
    
    cout << "Successfully loaded input file." << endl;
    
    // Perform optimization
    optimizer.optimize();
    
    // Save the optimized code
    if (!optimizer.save_optimize_file(OUTPUT_FILE)) {
        cerr << "Failed to save output file: " << OUTPUT_FILE << endl;
        return 1;
    }
    
    cout << "Successfully generated optimized code at: " << OUTPUT_FILE << endl;
    
    // Print statistics
    optimizer.printStatistics();
    
    return 0;
}
