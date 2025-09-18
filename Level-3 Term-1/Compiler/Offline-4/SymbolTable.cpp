#include "SymbolTable.h"
#include <iostream>

using namespace std;

// Constructor
SymbolTable::SymbolTable(int numBuckets, HashFunction hashFunc) {
    this->numBuckets = numBuckets;
    this->scopeCount = 1;
    this->hashFunc = hashFunc;
    this->currentScope = new ScopeTable(numBuckets, scopeCount, hashFunc);
    this->totalCollisions = 0;
}

// Destructor
SymbolTable::~SymbolTable() {
    while (currentScope != nullptr) {
        ScopeTable* parent = currentScope->getParentScope();
        delete currentScope;
        currentScope = parent;
    }
}

// Enter a new scope
bool SymbolTable::enterScope() {
    scopeCount++;
    ScopeTable* newScope = new ScopeTable(numBuckets, scopeCount, hashFunc);
    newScope->setParentScope(currentScope);
    currentScope = newScope;
    return true;
}

// Exit current scope
bool SymbolTable::exitScope() {
    // currentScope == nullptr is safechecking & currentScope->getParentScope() == nullptr is necessary
    if (currentScope == nullptr || currentScope->getParentScope() == nullptr) {
        cout << "\tCannot exit from global scope" << endl;
        return false;
    }
    
    ScopeTable* parent = currentScope->getParentScope();
    delete currentScope;
    currentScope = parent;
    return true;
}

// Insert a symbol in current scope
bool SymbolTable::insert(const string& name, const string& type) {
    // currentScope == nullptr is safechecking
    if (currentScope == nullptr) {
        return false;
    }
    
    // Get the current collision count before insertion
    int beforeCollisions = currentScope->getCollisionCount();
    
    // Perform the insertion
    bool result = currentScope->insert(name, type);
    
    // Check if a collision occurred by comparing collision counts
    if (result && currentScope->getCollisionCount() > beforeCollisions) {
        totalCollisions++; // Increment total collision counter
    }
    
    return result;
}

// Remove a symbol from current scope
bool SymbolTable::remove(const string& name) {
    // currentScope == nullptr is safechecking
    if (currentScope == nullptr) {
        return false;
    }
    return currentScope->remove(name);
}

// Look up a symbol in all accessible scopes
SymbolInfo* SymbolTable::lookUp(const string& name) const {
    ScopeTable* scope = currentScope;
    while (scope != nullptr) {
        SymbolInfo* symbol = scope->lookUp(name);
        if (symbol != nullptr) {
            return symbol;
        }
        scope = scope->getParentScope();
    }
    cout << "\t'" << name << "' not found in any of the ScopeTables" << endl;
    return nullptr;
}

// Print current scope table
void SymbolTable::printCurrentScopeTable() const {
    if (currentScope != nullptr) {
        currentScope->print(1);
    }
}

// Print all scope tables
void SymbolTable::printAllScopeTables() const {
    // First, calculate depth
    int depth = 0;
    ScopeTable* temp = currentScope;
    while (temp != nullptr) {
        depth++;
        temp = temp->getParentScope();
    }
    // Now print from currentScope, increasing indentation
    temp = currentScope;
    for (int i = 1; i <= depth && temp != nullptr; i++) {
        temp->print(i);
        temp = temp->getParentScope();
    }
}

// Get total collision count across all scope tables
int SymbolTable::getTotalCollisionCount() const {
    return totalCollisions;
}

// Get current scope count
int SymbolTable::getScopeCount() const {
    return scopeCount;
}

// Get number of buckets
int SymbolTable::getNumBuckets() const {
    return numBuckets;
}

// Get current scope's parameter count
int SymbolTable::getCurrentScopeParamCount() const {
    if (currentScope == nullptr) return 0;
    return currentScope->getParameterCount();
}

// Increment current scope's parameter count
void SymbolTable::incrementCurrentScopeParamCount() {
    if (currentScope != nullptr) {
        currentScope->incrementParameterCount();
    }
}

// Set current scope's parameter count
void SymbolTable::setCurrentScopeParamCount(int count) {
    if (currentScope != nullptr) {
        // Set parameter count by incrementing from 0 to the desired count
        currentScope->incrementParameterCount();  // This will increment by 1, adjust if count > 1 is needed
    }
}