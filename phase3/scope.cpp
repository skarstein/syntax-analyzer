#include <string>
#include <vector>
#include "type.h"
#include "symbol.h"
#include "scope.h"

using namespace std;

Scope::Scope(Scope *enclosing) {
    _enclosing = enclosing;
}

void Scope::insert(Symbol *s) {
    //check for redefinition/redeclaration
    _symbols.push_back(s);
}

Symbol* Scope::find(const string &name)const {
    for(unsigned i=0;i<_symbols.size();i++) {
        if(name == _symbols[i]->getName()) {
            return _symbols[i];
        }
    }
    return NULL;
}

Symbol* Scope::lookup(const string &name)const {
    //check current scope
    Symbol* result = this->find(name);
    if(result != NULL)
        return result;

    //check enclosing scope
    else if(this->_enclosing != NULL) {
        return this->_enclosing->lookup(name);
    }

    else return NULL;
}

Scope *Scope::enclosing()const {
    return _enclosing;
}

