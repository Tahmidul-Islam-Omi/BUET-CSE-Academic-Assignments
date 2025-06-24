#include "ScopeTable.h"
#include <iostream>
#include <cmath>

using namespace std;

// Hash function implementations
unsigned long long sdbmHash(const string& str, int numBuckets) {
    unsigned long long hash = 0;
    
    for (char c : str) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    
    return llabs(hash) % numBuckets;
}

// DJB2 Hash function
// Source: http://www.cse.yorku.ca/~oz/hash.html
unsigned long long djb2Hash(const string& str, int numBuckets) {
    unsigned long long hash = 5381;
    
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return llabs(hash) % numBuckets;
}

// FNV-1a Hash function
// Source: http://www.isthe.com/chongo/tech/comp/fnv/
unsigned long long fnvHash(const string& str, int numBuckets) {
    const unsigned long long FNV_PRIME = 16777619;
    const unsigned long long FNV_OFFSET_BASIS = 2166136261;
    
    unsigned long long hash = FNV_OFFSET_BASIS;
    
    for (char c : str) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    
    return llabs(hash) % numBuckets;
}

// Simple Additive Hash function
unsigned long long additiveHash(const string& str, int numBuckets) {
    unsigned long long hash = 0;
    
    for (char c : str) {
        hash += c;
    }
    
    return hash % numBuckets;
}

// Constructor
ScopeTable::ScopeTable(int numBuckets, int id, HashFunction hashFunc) {
    this->numBuckets = numBuckets;
    this->id = id;
    this->parentScope = nullptr;
    this->hashFunc = hashFunc;
    this->collisionCount = 0;
    table = new SymbolInfo*[numBuckets]();  // Initialize all entries to nullptr
    cout << "\tScopeTable# " << id << " created" << endl;
}

// Destructor
ScopeTable::~ScopeTable() {
    for (int i = 0; i < numBuckets; i++) {
        SymbolInfo* current = table[i];
        while (current != nullptr) {
            SymbolInfo* next = current->getNext();
            delete current;
            current = next;
        }
    }
    delete[] table;
    cout << "\tScopeTable# " << id << " removed" << endl;
}

// Getters
ScopeTable* ScopeTable::getParentScope() const {
    return parentScope;
}

int ScopeTable::getId() const {
    return id;
}

int ScopeTable::getCollisionCount() const {
    return collisionCount;
}

int ScopeTable::getNumBuckets() const {
    return numBuckets;
}

// Setters
void ScopeTable::setParentScope(ScopeTable* parent) {
    parentScope = parent;
}

// Insert a new symbol
bool ScopeTable::insert(const string& name, const string& type) {
    // First check if symbol already exists
    unsigned long long index = getHash(name);

    SymbolInfo* current = table[index];
    int chainPos = 1;
    
    while (current != nullptr) {
        if (current->getName() == name) {
            cout << "\t'" << name << "' already exists in the current ScopeTable" << endl;
            return false;
        }
        current = current->getNext();
        chainPos++;
    }
    
    //Creating new SymbolInfo object
    SymbolInfo* newSymbol = new SymbolInfo(name, type);
    
    // If bucket is empty
    if (table[index] == nullptr) {
        table[index] = newSymbol;
        cout << "\tInserted in ScopeTable# " << id << " at position " << index+1 << ", 1" << endl;
        return true;
    } 
    
    else {
        // A collision occurred - increment collision counter
        collisionCount++;
        
        // Chain to the end of the list
        current = table[index];
        int position = 1;
        while (current->getNext() != nullptr) {
            current = current->getNext();
            position++;
        }
        current->setNext(newSymbol);
        cout << "\tInserted in ScopeTable# " << id << " at position " << index+1 << ", " << position+1 << endl;
        return true;
    }
}

// Look up a symbol
SymbolInfo* ScopeTable::lookUp(const string& name) const {
    unsigned long long index = getHash(name);
    SymbolInfo* current = table[index];
    int chainPos = 1;
    
    while (current != nullptr) {
        if (current->getName() == name) {
            cout << "\t'" << name << "' found in ScopeTable# " << id << " at position " << index+1 << ", " << chainPos << endl;
            return current;
        }
        current = current->getNext();
        chainPos++;
    }
    return nullptr;
}

// Remove a symbol
bool ScopeTable::remove(const string& name) {
    unsigned long long index = getHash(name);
    SymbolInfo* current = table[index];
    SymbolInfo* prev = nullptr;
    int chainPos = 1;
    
    while (current != nullptr) {
        if (current->getName() == name) {
            if (prev == nullptr) {
                // First element in chain (edge case)
                table[index] = current->getNext();
            } else {
                // Middle or last element in chain
                prev->setNext(current->getNext());
            }
            cout << "\tDeleted '" << name << "' from ScopeTable# " << id << " at position " << index+1 << ", " << chainPos << endl;
            delete current;
            return true;
        }
        prev = current;
        current = current->getNext();
        chainPos++;
    }
    cout << "\tNot found in the current ScopeTable" << endl;
    return false;
}

// Print the scope table
void ScopeTable::print(int indentLevel) const {
    string indent(indentLevel, '\t');

    cout << indent << "ScopeTable# " << id << endl;

    for (int i = 0; i < numBuckets; i++) {

        if (table[i] != nullptr) {
            cout << indent << (i+1) << "--> ";
            SymbolInfo* current = table[i];
            while (current != nullptr) {

                // Edge case if mistakenly type is not defined
                if (current->getType().empty()) {
                    cout << "<" << current->getName() << ",> ";
                } 
                
                else {
                    cout << "<" << current->getName() << "," << current->getType() << "> ";
                }
                current = current->getNext();
            }
            cout << endl;
        } 
        
        else {
            cout << indent << (i+1) << "--> " << endl;
        }
    }
}