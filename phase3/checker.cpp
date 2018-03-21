#include <iostream>
#include <string>
#include "type.h"
#include "symbol.h"
#include "scope.h"
#include "checker.h"
#include "lexer.h"
#include "tokens.h"

using namespace std;

Scope *global = new Scope();
Scope *current = global;

void openScope() {
    cout << "Open Scope\tEnclosing(" << current << ")\tNew(";
    current = new Scope(current);
    if(global==NULL)
        global=current;
    cout << current << ")" << endl;
}

void closeScope() {
    Scope *s;
    s=current;
    if(current != NULL) {
        current = current->enclosing();
        delete s;
    }
}

void variableDecl(string name,Type t) {
    cout<<"Declare Variable "<<name<<endl;
    Symbol *s;
    s=current->find(name);
    if(s==NULL) {
        if(t.specifier() == VOID && t.indirection() == 0)
            report("'%s' has type void",name);
        else {
            s = new Symbol(name,t);
            current->insert(s);
            }
    }
    else if(current != global) {
        cout<<"NAME IS: "<<name<<endl;
        report("redeclaration of '%s'",name);
    }
    else if(t != s->getType()) {
        report("conflicting types for '%s'",name);
    }
}

void functionDecl(string name,Type t) {
    cout<<"Declare Function "<<name<<endl;
    Symbol *s;
    s = global->find(name);
    if(s==NULL) {
        s=new Symbol(name,t);
        global->insert(s);
    }
    else if(current != global) {
        report("redeclaration of '%s'",name);
    }
    else if(t != s->getType()) {
        report("conflicting types for '%s'",name);
    }
}

void functionDef(string name,Type t) {
    cout<<"Defined Function "<<name<<endl;
    Symbol *symbol;
    symbol = global->find(name);
    if(symbol->ifDef == true && symbol != NULL) {
        report("redefinition of '%s'",name);
    }
    //else 
        //functionDecl(name,t);
}

void symbolUse(string name, Type t) {
    cout<<"Used symbol "<<name<<endl;
    Symbol *s;
    s=current->lookup(name);
    if(s==NULL) {
        report("'%s' undeclared",name);
    }
}
