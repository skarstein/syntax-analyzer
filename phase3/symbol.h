#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "type.h"

class Symbol {
    std::string _name;
    Type _t;
    bool _def;
public:
    Symbol();
    Symbol(std::string name,Type t,bool def=false);
    std::string getName()const;
    Type getType()const;
    bool isDef()const;
    bool ifDef;
};
#endif
