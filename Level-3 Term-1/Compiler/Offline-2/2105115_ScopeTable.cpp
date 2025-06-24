#include "2105115_ScopeTable.h"
#include <iostream>
#include <cmath>

using namespace std;

// Hash function implementations
// unsigned long long sdbmHash(const string &str, int numBuckets)
// {
//     unsigned long long hash = 0;

//     for (char c : str)
//     {
//         hash = c + (hash << 6) + (hash << 16) - hash;
//     }

//     return llabs(hash) % numBuckets;
// }

unsigned int sdbmHash(const char *p, int numBuckets)
{
    unsigned int hash = 0;
    auto *str = (unsigned char *)p;
    int c{};
    while ((c = *str++))
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % numBuckets;
}

// DJB2 Hash function
// Source: http://www.cse.yorku.ca/~oz/hash.html
unsigned int djb2Hash(const char *p, int numBuckets)
{
    unsigned int hash = 5381;
    auto *str = (unsigned char *)p;
    int c{};

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % numBuckets;
}

// FNV-1a Hash function
// Source: http://www.isthe.com/chongo/tech/comp/fnv/
unsigned int fnvHash(const char *p, int numBuckets)
{
    const unsigned int FNV_PRIME = 16777619;
    const unsigned int FNV_OFFSET_BASIS = 2166136261;

    unsigned int hash = FNV_OFFSET_BASIS;
    auto *str = (unsigned char *)p;
    int c{};

    while ((c = *str++))
    {
        hash ^= c;
        hash *= FNV_PRIME;
    }

    return hash % numBuckets;
}

// Simple Additive Hash function
unsigned int additiveHash(const char *p, int numBuckets)
{
    unsigned int hash = 0;
    auto *str = (unsigned char *)p;
    int c{};

    while ((c = *str++))
    {
        hash += c;
    }

    return hash % numBuckets;
}

// Constructor
ScopeTable::ScopeTable(int numBuckets, const string &id, HashFunction hashFunc)
{
    this->numBuckets = numBuckets;
    this->id = id;
    this->parentScope = nullptr;
    this->hashFunc = hashFunc;
    this->collisionCount = 0;
    table = new SymbolInfo *[numBuckets](); // Initialize all entries to nullptr
}

// Destructor
ScopeTable::~ScopeTable()
{
    for (int i = 0; i < numBuckets; i++)
    {
        SymbolInfo *current = table[i];
        while (current != nullptr)
        {
            SymbolInfo *next = current->getNext();
            delete current;
            current = next;
        }
    }
    delete[] table;
}

// Getters
ScopeTable *ScopeTable::getParentScope() const
{
    return parentScope;
}

string ScopeTable::getId() const
{
    return id;
}

int ScopeTable::getCollisionCount() const
{
    return collisionCount;
}

int ScopeTable::getNumBuckets() const
{
    return numBuckets;
}

// Setters
void ScopeTable::setParentScope(ScopeTable *parent)
{
    parentScope = parent;
}

// Insert a new symbol
bool ScopeTable::insert(const string &name, const string &type, FILE *logfile)
{
    // First check if symbol already exists
    // Cast to unsigned long long to match format specifier
    unsigned long long index = static_cast<unsigned long long>(getHash(name));

    SymbolInfo *current = table[index];
    int chainPos = 0;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            // If logfile is provided, write to it, otherwise write to stdout
            if (logfile)
            {
                fprintf(logfile, "< %s : %s > already exists in ScopeTable# %s at position %llu, %d\n\n",
                        name.c_str(), type.c_str(), id.c_str(), index, chainPos);
            }
            else
            {
                fprintf(stdout, "< %s : %s > already exists in ScopeTable# %s at position %llu, %d\n",
                        name.c_str(), type.c_str(), id.c_str(), index, chainPos);
            }
            return false;
        }
        current = current->getNext();
        chainPos++;
    }

    // Creating new SymbolInfo object
    SymbolInfo *newSymbol = new SymbolInfo(name, type);

    // If bucket is empty
    if (table[index] == nullptr)
    {
        table[index] = newSymbol;
        return true;
    }
    else
    {
        // A collision occurred - increment collision counter
        collisionCount++;

        // Chain to the end of the list
        current = table[index];
        int position = 0;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
            position++;
        }
        current->setNext(newSymbol);
        return true;
    }
}

// Overloaded insert for backward compatibility
bool ScopeTable::insert(const string &name, const string &type)
{
    return insert(name, type, nullptr);
}

// Look up a symbol
SymbolInfo *ScopeTable::lookUp(const string &name) const
{
    // Cast to unsigned long long to match format specifier
    unsigned long long index = static_cast<unsigned long long>(getHash(name));
    SymbolInfo *current = table[index];
    int chainPos = 0;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            return current;
        }
        current = current->getNext();
        chainPos++;
    }
    return nullptr;
}

// Remove a symbol
bool ScopeTable::remove(const string &name)
{
    // Cast to unsigned long long to match format specifier
    unsigned long long index = static_cast<unsigned long long>(getHash(name));
    SymbolInfo *current = table[index];
    SymbolInfo *prev = nullptr;
    int chainPos = 0;

    while (current != nullptr)
    {
        if (current->getName() == name)
        {
            if (prev == nullptr)
            {
                table[index] = current->getNext();
            }
            else
            {
                prev->setNext(current->getNext());
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->getNext();
        chainPos++;
    }
    return false;
}

// Print the scope table
void ScopeTable::print(int indentLevel, FILE *outFile) const
{
    if (outFile)
    {
        fprintf(outFile, "ScopeTable # %s\n", id.c_str());

        for (int i = 0; i < numBuckets; i++)
        {
            if (table[i] != nullptr)
            {
                fprintf(outFile, "%d --> ", i);
                SymbolInfo *current = table[i];
                while (current != nullptr)
                {
                    // Edge case if mistakenly type is not defined
                    if (current->getType().empty())
                    {
                        fprintf(outFile, "< %s : > ", current->getName().c_str());
                    }
                    else
                    {
                        fprintf(outFile, "< %s : %s >", current->getName().c_str(), current->getType().c_str());
                    }
                    current = current->getNext();
                }
                fprintf(outFile, "\n");
            }
        }
    }
    else
    {
        cout << "ScopeTable # " << id << endl;

        for (int i = 0; i < numBuckets; i++)
        {
            if (table[i] != nullptr)
            {
                cout << i << "--> ";
                SymbolInfo *current = table[i];
                while (current != nullptr)
                {
                    // Edge case if mistakenly type is not defined
                    if (current->getType().empty())
                    {
                        cout << "< " << current->getName() << " : > ";
                    }
                    else
                    {
                        cout << "< " << current->getName() << " : " << current->getType() << " > ";
                    }
                    current = current->getNext();
                }
                cout << endl;
            }
        }
    }
}
