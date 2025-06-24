#include "SymbolTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

const int MAX_TOKENS = 100; // Define a maximum number of tokens

// Function to map hash function names to function pointers
map<string, HashFunction> initializeHashFunctionMap() {
    map<string, HashFunction> hashFunctionMap;
    hashFunctionMap["sdbm"] = sdbmHash;
    hashFunctionMap["djb2"] = djb2Hash;
    hashFunctionMap["fnv"] = fnvHash;
    hashFunctionMap["additive"] = additiveHash;
    return hashFunctionMap;
}

// Function to display available hash functions
void displayAvailableHashFunctions() {
    cout << "Available hash functions:" << endl;
    cout << "  sdbm      - SDBM hash (default)" << endl;
    cout << "  djb2      - DJB2 hash" << endl;
    cout << "  fnv       - FNV-1a hash" << endl;
    cout << "  additive  - Simple additive hash" << endl;
}

int splitString(const string& str, string tokens[MAX_TOKENS]) {
    int count = 0;
    size_t start = 0;
    
    // Skip leading spaces
    while (start < str.length() && str[start] == ' ') {
        start++;
    }
    
    // Find the first space
    size_t end = str.find(' ', start);

    // Split the string into tokens
    while (end != string::npos && count < MAX_TOKENS) {
        // Only add non-empty tokens
        if (end > start) {
            tokens[count++] = str.substr(start, end - start);
        }
        
        // Move to the next non-space character
        start = end + 1;
        while (start < str.length() && str[start] == ' ') {
            start++;
        }
        
        end = str.find(' ', start);
    }

    // Add the last token when there is no space after the last string
    if (start < str.length() && count < MAX_TOKENS) {
        tokens[count++] = str.substr(start);
    }

    return count; // Return the number of tokens found
}

// Run Command Line 
// g++ -o myprogram main.cpp SymbolTable.cpp ScopeTable.cpp SymbolInfo.cpp & ./myprogram sample_input.txt output.txt [hash_function]

int main(int argc, char* argv[]) {
    // Create hash function map
    map<string, HashFunction> hashFunctionMap = initializeHashFunctionMap();
    
    // Default to SDBM hash
    HashFunction selectedHashFunc = sdbmHash;
    string hashFuncName = "sdbm";

    // Check command line arguments
    if (argc < 3 || argc > 4) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file> [hash_function]" << endl;
        displayAvailableHashFunctions();
        return 1;
    }

    // Check if hash function is specified
    if (argc == 4) {
        string requestedHashFunc = argv[3];
        if (hashFunctionMap.find(requestedHashFunc) != hashFunctionMap.end()) {
            selectedHashFunc = hashFunctionMap[requestedHashFunc];
            hashFuncName = requestedHashFunc;
        } else {
            cerr << "Error: Unknown hash function '" << requestedHashFunc << "'" << endl;
            displayAvailableHashFunctions();
            return 1;
        }
    }
    
    // Redirect stdout to output file
    ofstream outFile(argv[2]);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open output file " << argv[2] << endl;
        return 1;
    }

    // Save original stdout buffer
    streambuf* origCoutBuf = cout.rdbuf();
    // Redirect cout to the file
    cout.rdbuf(outFile.rdbuf());

    // Open input file
    ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file " << argv[1] << endl;
        return 1;
    }

    // cout << "Using hash function: " << hashFuncName << endl;

    // Read number of buckets
    int numBuckets;
    inFile >> numBuckets;
    inFile.ignore(); // Skip the newline after the number
    // Create symbol table with selected hash function
    SymbolTable symbolTable(numBuckets, selectedHashFunc);

    // Process commands
    string line;
    int cmdCount = 0;
    

    while (getline(inFile, line) ) {
        cmdCount++;
        cout << "Cmd " << cmdCount << ": " << line << endl;

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
                    cout << "\tNumber of parameters mismatch for the command I" << endl;
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
            case 'L': { // Lookup
                if (tokenCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command L" << endl;
                    break;
                }
                symbolTable.lookUp(tokens[1]);
                break;
            }
            case 'D': { // Delete

                if (tokenCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command D" << endl;
                    break;
                }
                
                symbolTable.remove(tokens[1]);
                break;
            }
            case 'P': { // Print

                if (tokenCount != 2) {
                    cout << "\tNumber of parameters mismatch for the command P" << endl;
                    break;
                }

                if (tokens[1][0] == 'A') {
                    symbolTable.printAllScopeTables();
                } 
                
                else if (tokens[1][0] == 'C') {
                    symbolTable.printCurrentScopeTable();
                } 
                
                else {
                    cout << "\tInvalid print option. Use A for all or C for current scope" << endl;
                }

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
                cout << "\tInvalid command" << endl;
        }
    }
    
    // Handle the Quit command if present
    if (!inFile.eof()) {
        cmdCount++;
        cout << "Cmd " << cmdCount << ": Q" << endl;
    }
    
    symbolTable.~SymbolTable();
    
    // Restore original cout buffer
    cout.rdbuf(origCoutBuf);
    
    // Close files
    inFile.close();
    outFile.close();
    
    return 0;
}