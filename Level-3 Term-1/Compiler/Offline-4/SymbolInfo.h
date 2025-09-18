#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>

using namespace std;

class SymbolInfo {
private:
    string name;    // Name of the symbol
    string type;    // Type of the symbol
    SymbolInfo* next;    // Pointer for chaining in hash table
    int offset = -1; // -1 means not set/global
    bool isGlobalVar; // true if global, false if local
    bool isParameter; // true if parameter, false otherwise
    int paramIndex = -1; // Index of the parameter (0-based)
    bool isArray = false; // true if the symbol is an array
    int arraySize = 0; // Size of the array (0 for non-arrays)

public:
    // Constructors
    SymbolInfo();
    SymbolInfo(const string& name, const string& type, int offset = -1, bool isGlobalVar = false);
    
    // Getters
    string getName() const;
    string getType() const;
    SymbolInfo* getNext() const;
    int getOffset() const { return offset; }
    bool getIsGlobalVar() const;
    bool getIsParameter() const { return isParameter; }
    int getParamIndex() const { return paramIndex; }
    bool getIsArray() const { return isArray; }
    int getArraySize() const { return arraySize; }
    
    // Setters
    void setName(const string& name);
    void setType(const string& type);
    void setNext(SymbolInfo* next);
    void setOffset(int off) { offset = off; }
    void setIsGlobalVar(bool isGlobalVar);
    void setIsParameter(bool param) { isParameter = param; }
    void setParamIndex(int idx) { paramIndex = idx; }
    void setIsArray(bool array) { isArray = array; }
    void setArraySize(int size) { arraySize = size; }
    
    // Destructor
    ~SymbolInfo();
};

#endif // SYMBOLINFO_H 