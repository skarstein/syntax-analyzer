#include <ostream>
#include "symbol.h"
#include "type.h"

using namespace std;

Symbol::Symbol() {
}

Symbol::Symbol(std::string name,Type t,bool def) {
    _name=name;
    _t=t;
    _def=def;
}

string Symbol::getName()const {
    return _name;
}

Type Symbol::getType()const {
    return _t;
}

bool Symbol::isDef() const {
    return _def;
}
