#ifndef _Token_H_
#define _Token_H_
//Token의 cpp는 없음.
#include <iostream>

class Token {

private:
	int number;
	char oper;
	bool flag; // check for the type of Token. True is Number
public:
	Token(){}
	Token(int val) { number = val; flag = true;}
	Token(char op) { oper = op; flag = false; }
	
	int getNumber() { return number; }
	char getOper() { return oper; }
	bool isNumber() { return flag; }
};

#endif