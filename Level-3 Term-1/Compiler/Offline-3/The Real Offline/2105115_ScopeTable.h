#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include "2105115_SymbolInfo.h"
#include <string>
#include <fstream>

using namespace std;

// Define a function pointer type for hash functions
typedef unsigned int (*HashFunction)(const char *, int);

// Hash function implementations
unsigned int sdbmHash(const char *p, int numBuckets);
unsigned int djb2Hash(const char *p, int numBuckets);
unsigned int fnvHash(const char *p, int numBuckets);
unsigned int additiveHash(const char *p, int numBuckets);

class ScopeTable
{
private:
    SymbolInfo **table;      // Pointer to an array of pointers to SymbolInfo objects
    ScopeTable *parentScope; // Pointer to the parent scope table
    string id;               // Unique identifier for the scope table
    int numBuckets;          // Number of buckets in the scope table
    HashFunction hashFunc;   // Pointer to the hash function to use
    int collisionCount;      // Counter for hash collisions

    // Hash value calculation
    unsigned int getHash(const string &key) const
    {
        return hashFunc(key.c_str(), numBuckets);
    }

public:
    ScopeTable(int numBuckets, const string &id, HashFunction hashFunc = sdbmHash);
    ~ScopeTable();

    // Accessors
    ScopeTable *getParentScope() const;
    string getId() const;
    int getCollisionCount() const;
    int getNumBuckets() const;
    void setParentScope(ScopeTable *parent);

    // Symbol operations
    bool insert(const string &name, const string &type, FILE *logfile);
    bool insert(const string &name, const string &type);
    bool insert(const string &name, const string &type, std::ofstream& logfile);
    SymbolInfo *lookUp(const string &name) const;
    bool remove(const string &name);

    // Display
    void print(int indentLevel = 0, FILE *outFile = nullptr) const;
    
    // New function for printing to std::ofstream
    void print(std::ofstream& outFile) const;
};

#endif