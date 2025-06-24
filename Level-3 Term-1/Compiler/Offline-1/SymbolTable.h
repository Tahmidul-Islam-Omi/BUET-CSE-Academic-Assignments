#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ScopeTable.h"
#include <string>

using namespace std;

class SymbolTable {
private:
    ScopeTable* currentScope;    // Pointer to current scope table
    int numBuckets;             // Number of buckets for new scope tables
    int scopeCount;             // Counter for generating unique scope IDs
    HashFunction hashFunc;       // The hash function to use
    int totalCollisions;
public:
    // Constructor and Destructor
    SymbolTable(int numBuckets, HashFunction hashFunc = sdbmHash);
    ~SymbolTable();
    
    // Scope management
    bool enterScope();
    bool exitScope();
    
    // Symbol management
    bool insert(const string& name, const string& type);
    bool remove(const string& name);
    SymbolInfo* lookUp(const string& name) const;
    
    // Print functions
    void printCurrentScopeTable() const;
    void printAllScopeTables() const;
    
    // Statistics functions
    int getTotalCollisionCount() const;
    int getScopeCount() const;
    int getNumBuckets() const;
};

#endif // SYMBOL_TABLE_H 