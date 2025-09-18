#include "SymbolInfo.h"

using namespace std;

// Default constructor
SymbolInfo::SymbolInfo() : name(""), type(""), next(nullptr), offset(-1), isGlobalVar(false), isParameter(false) {}

// Parameterized constructor
SymbolInfo::SymbolInfo(const string& name, const string& type, int offset, bool isGlobalVar)
    : name(name), type(type), next(nullptr), offset(offset), isGlobalVar(isGlobalVar), isParameter(false) {}

// Getters
string SymbolInfo::getName() const {
    return name;
}

string SymbolInfo::getType() const {
    return type;
}

SymbolInfo* SymbolInfo::getNext() const {
    return next;
}

bool SymbolInfo::getIsGlobalVar() const {
    return isGlobalVar;
}


// Setters
void SymbolInfo::setName(const string& name) {
    this->name = name;
}

void SymbolInfo::setType(const string& type) {
    this->type = type;
}

void SymbolInfo::setNext(SymbolInfo* next) {
    this->next = next;
}

void SymbolInfo::setIsGlobalVar(bool isGlobalVar) {
    this->isGlobalVar = isGlobalVar;
}


// Destructor
SymbolInfo::~SymbolInfo() {
    // The destructor is empty as we don't want to delete the next pointer
    // This will be handled by the ScopeTable
} 