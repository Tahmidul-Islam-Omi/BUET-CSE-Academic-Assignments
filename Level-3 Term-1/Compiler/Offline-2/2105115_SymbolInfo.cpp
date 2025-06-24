#include "2105115_SymbolInfo.h"

using namespace std;

// Default constructor
SymbolInfo::SymbolInfo() : name(""), type(""), next(nullptr) {}

// Parameterized constructor
SymbolInfo::SymbolInfo(const string &name, const string &type)
    : name(name), type(type), next(nullptr) {}

// Getters
string SymbolInfo::getName() const
{
    return name;
}

string SymbolInfo::getType() const
{
    return type;
}

SymbolInfo *SymbolInfo::getNext() const
{
    return next;
}

// Setters
void SymbolInfo::setName(const string &name)
{
    this->name = name;
}

void SymbolInfo::setType(const string &type)
{
    this->type = type;
}

void SymbolInfo::setNext(SymbolInfo *next)
{
    this->next = next;
}

// Destructor
SymbolInfo::~SymbolInfo()
{
    // The destructor is empty as we don't want to delete the next pointer
    // This will be handled by the ScopeTable
}