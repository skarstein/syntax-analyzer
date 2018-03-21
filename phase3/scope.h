#ifndef SCOPE_H
#define SCOPE_H
#include "symbol.h"
#include "type.h"

typedef std::vector<Symbol *> symbols;

class Scope {
    typedef std::string string;
    Scope *_enclosing;
    symbols _symbols;
public:
    //Scope();
    Scope(Scope *enclosing=0);
    void insert(Symbol *symbol);
    Symbol *find(const string &name)const;
    Symbol *lookup(const string &name)const;
    Scope *enclosing()const;
    //const symbols &symbols()const;
};

#endif
