#ifndef _Expression_H_
#define _Expression_H_
#include <string>
#include "Stack.h"
#include "Token.h"

class Expression {
private:
	Stack<Token> TokenStack;
	void remarkToken();
public:
	Expression(){}
	Expression(std::string infix);
	Expression(Stack<Token> copy){TokenStack = copy;} //Copy Ctor

	Stack<Token> getToken(){return TokenStack;}
	Token nextToken();

};
bool operator == (Token t, char ch);
bool operator != (Token t, char ch);
#endif