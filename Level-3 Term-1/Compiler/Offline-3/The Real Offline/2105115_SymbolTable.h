#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "2105115_ScopeTable.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class SymbolTable
{
private:
    ScopeTable *currentScope;     // Pointer to current scope table
    int numBuckets;               // Number of buckets for new scope tables
    int scopeCount;               // This will track the sequential count for the current level
    std::vector<int> currentPath; // To track the hierarchical path
    HashFunction hashFunc;        // The hash function to use
    int totalCollisions;

    // Generate hierarchical ID string from current path
    std::string generateScopeId() const;

public:
    // Constructor and Destructor
    SymbolTable(int numBuckets, HashFunction hashFunc = sdbmHash);
    ~SymbolTable();

    // Scope management
    bool enterScope();
    bool exitScope();
    bool exitScope(FILE *logfile);
    bool exitScope(std::ofstream& logfile);

    // Symbol management
    bool insert(const string &name, const string &type, FILE *logfile);
    bool insert(const string &name, const string &type);
    bool insert(const string &name, const string &type, std::ofstream& logfile);
    bool remove(const string &name);
    SymbolInfo *lookUp(const string &name) const;

    // Print functions
    void printCurrentScopeTable(FILE *outFile = nullptr) const;
    void printAllScopeTables(FILE *outFile = nullptr) const;
    
    // New print functions for std::ofstream
    void printCurrentScopeTable(std::ofstream& outFile) const;
    void printAllScopeTables(std::ofstream& outFile) const;

    // Statistics functions
    int getTotalCollisionCount() const;
    int getScopeCount() const;
    int getNumBuckets() const;
};

#endif // SYMBOLTABLE_H