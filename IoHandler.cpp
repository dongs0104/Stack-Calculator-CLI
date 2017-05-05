#include "IoHandler.h"
using namespace std;

string IoHandler::getInfix()
{
	string temp = "";
	char ch = 0;
	while(ch != '\n')
	{
		cin.get(ch);
		if(!(ch == ' ' || ch == '\n'))
			temp.push_back(ch);
	}
	return temp;
}

void IoHandler::printExpression(Expression e)
{
	Stack<Token> temp = e.getToken(); //복사생성자
	for (Token x = temp.top(); temp.top() != '#' ;  temp.pop(), x = temp.top())
	{
		if(x.isNumber())
			cout << x.getNumber() << " ";
		else
			cout << x.getOper() << " ";
	}
	cout << endl;
}

void IoHandler::printAnswer(Expression post)
{
	Calculator c;
	cout << c.getAnswer(post) << endl;
}