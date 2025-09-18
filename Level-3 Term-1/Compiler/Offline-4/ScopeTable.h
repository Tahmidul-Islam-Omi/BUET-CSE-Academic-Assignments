#ifndef SCOPE_TABLE_H
#define SCOPE_TABLE_H

#include "SymbolInfo.h"
#include <string>

using namespace std;

// Define a function pointer type for hash functions
typedef unsigned long long (*HashFunction)(const string&, int);

// Hash function implementations
unsigned long long sdbmHash(const string& str, int numBuckets);
unsigned long long djb2Hash(const string& str, int numBuckets);
unsigned long long fnvHash(const string& str, int numBuckets);
unsigned long long additiveHash(const string& str, int numBuckets);

class ScopeTable {
private:
    int id; // Unique identifier for the scope table
    int numBuckets; // Number of buckets in the scope table
    SymbolInfo** table; // Pointer to an array of pointers to SymbolInfo objects
    ScopeTable* parentScope;  // Pointer to the parent scope table
    HashFunction hashFunc;  // Pointer to the hash function to use
    int collisionCount;  // Counter for hash collisions
    int parameterCount;  // Counter for parameters in this scope

public:
    ScopeTable(int numBuckets, int id, HashFunction hashFunc = sdbmHash);
    ~ScopeTable();

    // Accessors
    ScopeTable* getParentScope() const;
    int getId() const;
    int getCollisionCount() const;
    int getNumBuckets() const;
    void setParentScope(ScopeTable* parent);

    // Hash function access
    unsigned long long getHash(const string& str) const {
        return hashFunc(str, numBuckets);
    }

    // Symbol operations
    bool insert(const string& name, const string& type);
    SymbolInfo* lookUp(const string& name) const;
    bool remove(const string& name);

    // Parameter management
    int getParameterCount() const { return parameterCount; }
    void incrementParameterCount() { parameterCount++; }

    // Display
    void print(int indentLevel = 0) const;
};

#endif 