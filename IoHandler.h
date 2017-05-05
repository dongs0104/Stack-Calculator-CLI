#ifndef _IoHandler_H_
#define _IoHandler_H_
#include <string>
#include <iostream>

#include "Calculator.h"

class IoHandler{
public:
	std::string getInfix();
	void printExpression(Expression);
	void printAnswer(Expression);
};

#endif