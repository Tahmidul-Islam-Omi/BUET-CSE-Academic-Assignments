#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>

using namespace std;

class SymbolInfo {
private:
    string name;    // Name of the symbol
    string type;    // Type of the symbol
    SymbolInfo* next;    // Pointer for chaining in hash table

public:
    // Constructors
    SymbolInfo();
    SymbolInfo(const string& name, const string& type);
    
    // Getters
    string getName() const;
    string getType() const;
    SymbolInfo* getNext() const;
    
    // Setters
    void setName(const string& name);
    void setType(const string& type);
    void setNext(SymbolInfo* next);
    
    // Destructor
    ~SymbolInfo();
};

#endif // SYMBOLINFO_H 