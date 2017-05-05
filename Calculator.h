#ifndef _Calculator_H_
#define _Calculator_H_

#include "Expression.h"
#include <cmath>
#include <stdexcept>


class Calculator {
private:
	int getISP(Token op);
	int getICP(Token op);	
public:
	int cal(Token first,Token second,Token op);

	Expression toPostfix(Expression infix);
	int getAnswer(Expression postifx);
};

#endif