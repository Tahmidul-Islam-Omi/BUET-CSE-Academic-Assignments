#include "SymbolTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_TOKENS = 100; // Define a maximum number of tokens

// Structure to hold hash function performance metrics
struct HashPerformanceMetrics {
    string name;
    int totalCollisions;
    int scopeCount;
    int bucketSize;
    double collisionRatio;
};


int splitString(const string& str, string tokens[MAX_TOKENS]) {
    int count = 0;
    size_t start = 0;
    // Find the first space
    size_t end = str.find(' ');

    // Split the string into tokens
    // loop continues as long as a space is found in the stridjng.
    while (end != string::npos) {
        if (count < MAX_TOKENS) {
            tokens[count++] = str.substr(start, end - start);
        }
        start = end + 1;
        end = str.find(' ', start);
    }

    // Add the last token when there is no space after the last string
    if (count < MAX_TOKENS) {
        tokens[count++] = str.substr(start);
    }

    return count; // Return the number of tokens found
}

// Process input file using specified hash function and return performance metrics
HashPerformanceMetrics processWithHashFunction(const string& inputFileName, HashFunction hashFunc, const string& hashFuncName) {
    ifstream inFile(inputFileName);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file " << inputFileName << endl;
        exit(1);
    }
    
    // Read number of buckets
    int numBuckets;
    inFile >> numBuckets;
    inFile.ignore(); // Skip the newline after the number
    
    // Create symbol table with selected hash function
    SymbolTable symbolTable(numBuckets, hashFunc);
    
    // Process commands
    string line;
    
    while (getline(inFile, line)) {

        if (line[0] == 'Q') {
            break;
        }
        
        string tokens[MAX_TOKENS];
        int tokenCount = splitString(line, tokens);
        
        // Skip empty lines 
        if (tokenCount == 0) continue;
        
        // For switch statement, tokens[0][0] have to be used because switch wants a character, not a string.
        char command = tokens[0][0];
        
        switch (command) {

            // Insert
            case 'I': {

                if (tokenCount < 3) {
                    break;
                }
                
                string name = tokens[1];
                string type = tokens[2];
                
                // Special handling for complex types
                if (type == "FUNCTION" && tokenCount > 3) {
                    // For functions, combine all types into a formatted string
                    string functionType = type + ",";
                    functionType += tokens[3] + "<=="; // Return type
                    
                    // Add parameters types
                    if (tokenCount > 4) {
                        functionType += "(";
                        for (int i = 4; i < tokenCount; i++) {
                            functionType += tokens[i];
                            if (i < tokenCount - 1) {
                                functionType += ",";
                            }
                        }
                        functionType += ")";
                    }
                    
                    symbolTable.insert(name, functionType);
                } 

                else if ((type == "STRUCT" || type == "UNION") && tokenCount > 3) {
                    // For struct/union, combine fields into formatted string
                    string structType = type + ",{";
                    
                    for (int i = 3; i < tokenCount; i += 2) {
                        if (i + 1 < tokenCount) {
                            structType += "(" + tokens[i] + "," + tokens[i+1] + ")";
                            if (i + 2 < tokenCount) {
                                structType += ",";
                            }
                        }
                    }
                    
                    structType += "}";
                    symbolTable.insert(name, structType);
                } 

                else {
                    symbolTable.insert(name, type);
                }

                break;
            }
            
            case 'D': { // Delete

                if (tokenCount != 2) {
                    // Number of parameters mismatch for the command D
                    break;
                }
                
                symbolTable.remove(tokens[1]);
                break;
            }
            case 'S': { // Enter Scope
                symbolTable.enterScope();
                break;
            }
            case 'E': { // Exit Scope
                symbolTable.exitScope();
                break;
            }
            default:
                // Invalid command or not necessary for the report generation
                break;
        }
    }
    
    // Collect statistics
    HashPerformanceMetrics metrics;
    metrics.name = hashFuncName;
    metrics.totalCollisions = symbolTable.getTotalCollisionCount();
    metrics.scopeCount = symbolTable.getScopeCount();
    metrics.bucketSize = symbolTable.getNumBuckets();
    metrics.collisionRatio = static_cast<double>(metrics.totalCollisions) / (metrics.scopeCount * metrics.bucketSize);

    
    inFile.close();
    
    return metrics;
}
// Code running Command
//    g++ -o report_generator report_generator.cpp SymbolTable.cpp ScopeTable.cpp SymbolInfo.cpp
//    ./report_generator sample_input.txt


int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    
    string inputFileName = argv[1];
    
    // Define hash functions to test
    map<string, HashFunction> hashFunctions;
    hashFunctions["sdbm"] = sdbmHash;
    hashFunctions["djb2"] = djb2Hash;
    hashFunctions["fnv"] = fnvHash;
    hashFunctions["additive"] = additiveHash;
    
    vector<HashPerformanceMetrics> results;
    
    // Process input with each hash function
    for (const auto& pair : hashFunctions) {
        string name = pair.first;
        HashFunction func = pair.second;
        HashPerformanceMetrics metrics = processWithHashFunction(inputFileName, func, name);
        results.push_back(metrics);
    }
    
    // Write results to report.txt
    ofstream reportFile("report.txt");
    if (!reportFile.is_open()) {
        cerr << "Error: Unable to open report.txt for writing" << endl;
        return 1;
    }
    
    reportFile << "========= Hash Function Performance Report =========" << endl;
    reportFile << "\nInput file: " << inputFileName << endl;
    reportFile << "\nPerformance Metrics:" << endl;
    reportFile << "---------------------------------------------------------" << endl;
    reportFile << "| Hash Function | Collisions | Scopes | Bucket Size | Collision Ratio |" << endl;
    reportFile << "---------------------------------------------------------" << endl;
    
    for (const auto& metric : results) {
        reportFile << "| " << std::left << std::setw(14) << metric.name 
                  << "| " << std::setw(11) << metric.totalCollisions 
                  << "| " << std::setw(7) << metric.scopeCount 
                  << "| " << std::setw(12) << metric.bucketSize 
                  << "| " << std::setw(15) << std::fixed << std::setprecision(6) << metric.collisionRatio << " |" << endl;
    }
    
    reportFile << "---------------------------------------------------------" << endl;
    reportFile << "\nCollision Ratio = Total Collisions / (Scope Count * Bucket Size)" << endl;
    reportFile << "\nLower ratio indicates better performance (fewer collisions)." << endl;
    
    reportFile.close();
    
    cout << "Report generated successfully in report.txt" << endl;
    
    return 0;
}
