#include "Expression.h"
#include <iostream>
Expression::Expression (std::string infix)
{//infixExpression
	TokenStack.push(Token('#'));
	//Expression Start

	int length = infix.length();

	for (int i = 0; i < length ;)
	{
		char temp = infix.at(i);
		if ('0' <= temp && temp <= '9')
		{
			int number = 0;
			int size = 0;
			while((i + size) < length)
			{
				temp = infix.at(i + size);
				if ('0' <= temp && temp <= '9')
				{
					number = number * 10 + (temp - '0');
					size++;
				}
				else
					break;
			}
			TokenStack.push(Token(number));
			i += size ;
		}
		else{
			TokenStack.push(Token(temp));
			i++;
		}
	}//end of for

	remarkToken();
}

Token Expression::nextToken()
{
	if(!TokenStack.isEmpty())
		TokenStack.pop();
	return TokenStack.top();
}

void Expression::remarkToken()
{
	Stack<Token> reverse;
	reverse.push(Token('#'));
 
	for (; TokenStack.top() != '#' ; TokenStack.pop())
	{
		Token x = TokenStack.top();
		if( x == '-')
		{
			if(reverse.top() == ')'||reverse.top().isNumber())
				reverse.push(Token('~'));
			else if(reverse.top() == '-')
			{
				reverse.pop();
				reverse.push(Token('~'));
				reverse.push(Token('-'));
			}
			else
				reverse.push(Token('-'));
			}
		else {
			reverse.push(x);
		}
	}
	if(reverse.top() == '-')
	{
		reverse.pop();
		reverse.push(Token('~'));
	}
	TokenStack = reverse;
}
bool operator == (Token t, char c)
{
	if(!t.isNumber())
		return (t.getOper() == c);
	return false;
}

bool operator != (Token t, char c)
{
	if(!t.isNumber())
		return (t.getOper() != c);
	return true;
}
