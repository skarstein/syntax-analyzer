#ifndef CHECKER_H
#define CHECKER_H
#include "type.h"

using namespace std;

void openGlobal();
void closeGlobal();
void openFunction();
void closeFunction();
void openBlock();
void closeBlock();
void openScope();
void closeScope();
void variableDecl(string, Type);
void functionDecl(string, Type);
void functionDef(string, Type, bool);
void symbolUse(string, Type);

#endif
