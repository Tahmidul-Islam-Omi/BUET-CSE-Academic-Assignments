#include "2105115_SymbolTable.h"
#include <iostream>
#include <sstream>

using namespace std;

// Helper method to generate scope ID string from current path
string SymbolTable::generateScopeId() const
{
    if (currentPath.empty())
    {
        return "1"; // Global scope
    }

    stringstream ss;
    ss << "1"; // Start with global scope

    // Build the hierarchical ID
    for (size_t i = 0; i < currentPath.size(); i++)
    {
        ss << "." << currentPath[i];
    }

    return ss.str();
}

// Constructor
SymbolTable::SymbolTable(int numBuckets, HashFunction hashFunc)
{
    this->numBuckets = numBuckets;
    this->scopeCount = 1;
    this->hashFunc = hashFunc;
    this->totalCollisions = 0;

    // Create the global scope with ID "1"
    this->currentScope = new ScopeTable(numBuckets, "1", hashFunc);
}

// Destructor
SymbolTable::~SymbolTable()
{
    while (currentScope != nullptr)
    {
        ScopeTable *parent = currentScope->getParentScope();
        delete currentScope;
        currentScope = parent;
    }
}

// Enter a new scope
bool SymbolTable::enterScope()
{
    // global scope or starting a new branch
    if (currentPath.empty())
    {
        scopeCount++;                          // Next sibling at level 1
        currentPath.push_back(scopeCount - 1); // -1 because bcz started at 1
    }
    else
    {
        // going deeper within an existing path
        currentPath.push_back(1); // First child at this new level
    }

    // Generate the hierarchical ID for the new scope
    string scopeId = generateScopeId();

    // Create new scope with the hierarchical ID
    ScopeTable *newScope = new ScopeTable(numBuckets, scopeId, hashFunc);
    newScope->setParentScope(currentScope);
    currentScope = newScope;
    return true;
}

// Exit current scope
// bool SymbolTable::exitScope(FILE *logfile)
// {
//     // currentScope == nullptr is safechecking & currentScope->getParentScope() == nullptr is necessary
//     if (currentScope == nullptr || currentScope->getParentScope() == nullptr)
//     {
//         if (logfile)
//         {
//             fprintf(logfile, "\tCannot exit from global scope\n");
//         }
//         else
//         {
//             cout << "\tCannot exit from global scope" << endl;
//         }
//         cout<<"ete"<<endl;
//         return false;
//     }

//     // Pop the last level from the path
//     if (!currentPath.empty())
//     {
//         // at the end of a sequence at the current level
//         if (currentPath.back() > 1)
//         {
//             // Prepare for a new sibling at this level
//             currentPath.back()++; // Increment the counter at this level
//         }
//         else
//         {
//             // going up a level completely
//             currentPath.pop_back();
//         }
//     }

//     ScopeTable *parent = currentScope->getParentScope();
//     delete currentScope;
//     currentScope = parent;
//     return true;
// }

// New exitScope function for std::ofstream
bool SymbolTable::exitScope(std::ofstream& logfile)
{
    // currentScope == nullptr is safechecking & currentScope->getParentScope() == nullptr is necessary
    if (currentScope == nullptr || currentScope->getParentScope() == nullptr)
    {
        logfile << "\tCannot exit from global scope" << std::endl;
        return false;
    }

    // Pop the last level from the path
    if (!currentPath.empty())
    {
        // at the end of a sequence at the current level
        if (currentPath.back() > 1)
        {
            // Prepare for a new sibling at this level
            currentPath.back()++; // Increment the counter at this level
        }
        else
        {
            // going up a level completely
            currentPath.pop_back();
        }
    }

    ScopeTable *parent = currentScope->getParentScope();
    delete currentScope;
    currentScope = parent;
    return true;
}

extern FILE *logout; // Reference the external logout file pointer from lexer

// bool SymbolTable::exitScope()
// {
//     return exitScope(logout);
// }

bool SymbolTable::insert(const string &name, const string &type, FILE *logfile)
{
    // currentScope == nullptr is safechecking
    if (currentScope == nullptr)
    {
        return false;
    }

    // Get the current collision count before insertion
    int beforeCollisions = currentScope->getCollisionCount();

    bool result = currentScope->insert(name, type, logfile);

    // Check if a collision occurred by comparing collision counts
    if (result && currentScope->getCollisionCount() > beforeCollisions)
    {
        totalCollisions++;
    }

    return result;
}

// New insert function for std::ofstream
bool SymbolTable::insert(const string &name, const string &type, std::ofstream& logfile)
{
    // currentScope == nullptr is safechecking
    if (currentScope == nullptr)
    {
        return false;
    }

    // Get the current collision count before insertion
    int beforeCollisions = currentScope->getCollisionCount();

    // Now use the ScopeTable's insert function that takes std::ofstream&
    bool result = currentScope->insert(name, type, logfile);

    // Check if a collision occurred by comparing collision counts
    if (result && currentScope->getCollisionCount() > beforeCollisions)
    {
        totalCollisions++;
    }

    return result;
}

// Original insert function for backward compatibility
bool SymbolTable::insert(const string &name, const string &type)
{
    return insert(name, type, nullptr);
}

bool SymbolTable::remove(const string &name)
{
    // currentScope == nullptr is safechecking
    if (currentScope == nullptr)
    {
        return false;
    }
    return currentScope->remove(name);
}

// Look up a symbol in all accessible scopes
SymbolInfo *SymbolTable::lookUp(const string &name) const
{
    ScopeTable *scope = currentScope;
    while (scope != nullptr)
    {
        SymbolInfo *symbol = scope->lookUp(name);
        if (symbol != nullptr)
        {
            return symbol;
        }
        scope = scope->getParentScope();
    }

    return nullptr;
}

// Print current scope table
void SymbolTable::printCurrentScopeTable(FILE *outFile) const
{
    if (currentScope != nullptr)
    {
        currentScope->print(0, outFile);
    }
}

// New function to print current scope table to std::ofstream
void SymbolTable::printCurrentScopeTable(std::ofstream& outFile) const
{
    if (currentScope != nullptr)
    {
        currentScope->print(outFile);
    }
}

// Print all scope tables
void SymbolTable::printAllScopeTables(FILE *outFile) const
{
    ScopeTable *temp = currentScope;
    while (temp != nullptr)
    {
        temp->print(0, outFile);
        temp = temp->getParentScope();
    }
}

// New function to print all scope tables to std::ofstream
void SymbolTable::printAllScopeTables(std::ofstream& outFile) const
{
    ScopeTable *temp = currentScope;
    while (temp != nullptr)
    {
        temp->print(outFile);
        temp = temp->getParentScope();
    }
}

// Get total collision count across all scope tables
int SymbolTable::getTotalCollisionCount() const
{
    return totalCollisions;
}

// Get current scope count
int SymbolTable::getScopeCount() const
{
    return scopeCount;
}

// Get number of buckets
int SymbolTable::getNumBuckets() const
{
    return numBuckets;
}