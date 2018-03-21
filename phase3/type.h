#ifndef TYPE_H
#define TYPE_H
#include <ostream>
#include <vector>

typedef std::vector<class Type> Parameters;
enum {ARRAY,SCALAR,FUNCTION,TYPEERROR};

class Type {
private:
    int _specifier;
    unsigned _indirection;
    int _kind;
public:
    unsigned _length;
    Parameters *_parameters;
    Type();
    Type(int specifier,unsigned indirection);
    Type(int specifier,unsigned indirection,unsigned length);
    Type(int specifier,unsigned indirection,Parameters *params);
    bool operator ==(const Type &rhs)const;
    bool operator !=(const Type &rhs)const;
    int specifier()const;
    unsigned indirection()const;
    int kind()const;
    unsigned length()const;
    Parameters *parameters()const;
    bool isArray()const;
    bool isError()const;
    bool isFunction()const;
};

std::ostream &operator <<(std::ostream &ostr,const Type &type);
#endif
