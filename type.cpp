#include <ostream>
#include "tokens.h"
#include "type.h"

using namespace std;

Type::Type() {
}

Type::Type(int specifier,unsigned indirection) {
    _specifier=specifier;
    _indirection=indirection;
}

Type::Type(int specifier,unsigned indirection,unsigned length) {
    _specifier=specifier;
    _indirection=indirection;
    _length=length;
}

Type::Type(int specifier,unsigned indirection,Parameters *params) {
    _specifier=specifier;
    _indirection=indirection;
    _parameters=params;
}

bool Type::operator ==(const Type &rhs)const {
    if(_kind != rhs._kind)
        return false;
    if(_specifier != rhs._specifier)
        return false;
    if(_indirection != rhs._indirection)
        return false;
    if(_kind == ERROR)
        return true;
    if(_specifier == rhs._specifier)
        return true;
    if(_kind == FUNCTION)
        return *_parameters == *rhs._parameters;
    if(_kind == ARRAY) {
        if(_length != rhs._length)
            return false;
    }
    return true;
}

bool Type::operator !=(const Type &rhs)const {
    return !operator ==(rhs);
}

int Type::specifier()const {
    return _specifier;
}

unsigned Type::indirection()const {
    return _indirection;
}

int Type::kind()const {
    return _kind;
}

unsigned Type::length()const {
    return _length;
}

Parameters *Type::parameters()const {
    return _parameters;
}

bool Type::isArray()const {
    if(_kind==ARRAY)
        return true;
    return false;
}

bool Type::isError()const {
    if(_kind==ERROR)
        return true;
    return false;
}

bool Type::isFunction()const {
    if(_kind==FUNCTION)
        return true;
    return false;
}

std::ostream &operator <<(std::ostream &ostr,const Type &t) {
    unsigned i;
    if(t.isError())
        ostr<<"error";
    else {
        if(t.specifier()==INT)
            ostr<<"int";
        else if(t.specifier()==CHAR)
            ostr<<"char";
        else if(t.specifier()==VOID)
            ostr<<"void";
        if(t.indirection()>0) {
            ostr<<" ";
            for(i=0;i<t.indirection();i++)
                ostr<<"*";
        }
        if(t.isArray())
            ostr<<"["<<t.length()<<"]";
        if(t.isFunction()) {
            ostr<<"(";
            if(t.parameters()->size()==0)
                ostr<<"void";
            else
                for(i=0;i<t.parameters()->size();i++) {
                    if(i>0)
                        ostr<<",";
                    ostr<<(*t.parameters())[i];
                }
            ostr<<")";
        }
    }
}
