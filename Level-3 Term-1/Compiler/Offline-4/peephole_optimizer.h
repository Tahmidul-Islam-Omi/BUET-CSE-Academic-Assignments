#ifndef PEEPHOLE_OPTIMIZER_H
#define PEEPHOLE_OPTIMIZER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>
#include <map>
#include <set>
using namespace std;

class peephole_optimizer {
private:
    vector<string> asm_code_line;
    map<string, string> label_mapping;
    set<string> used_labels;

    // Helper functions
    string trim(const string& str);
    bool isLabel(const string& line);
    bool isInstruction(const string& line);
    string extract_label(const string& line);
    string get_reg_from_mov(const string& line);
    string get_dest_from_mov(const string& line);
    string get_src_from_mov(const string& line);
    bool is_redundant_mov(const string& line1, const string& line2);
    bool is_redundant_push_pop(const string& line1, const string& line2);
    bool is_redundant_arithmetic(const string& line);
    void find_used_label();
    void optimized_redundant_label();
    
    // Optimization methods
    void remove_redundant_mov();
    void remove_redundant_push_pop();
    void remove_redundant_arithmetic();
    void remove_redundant_label();
    
public:
    peephole_optimizer();
    ~peephole_optimizer();
    
    bool load_asm_file(const string& filename);
    void optimize();
    bool save_optimize_file(const string& filename);
    void printStatistics();
};

#endif // PEEPHOLE_OPTIMIZER_H
