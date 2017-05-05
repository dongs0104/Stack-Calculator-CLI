#include "Calculator.h"

int Calculator::getISP(Token op)
{
	if(op == '(')
		return 8;
	else if(op == '~')
		return 2;
	else if(op == '^')
		return 3;
	else if(op == '*' || op == '/' || op == '%')
		return 4;
	else if(op == '+' || op == '-')
		return 5;
	else if(op == '#')
		return 9;
	else
		return -1;
}

int Calculator::getICP(Token op)
{
	if(op == '(')
		return 0;
	else if(op == '~')
		return 1;
	else if(op == '^')
		return 3;
	else if(op == '*' || op == '/' || op == '%')
		return 4;
	else if(op == '+' || op == '-')
		return 5;
	else if(op == '#')
		return 8;
	else
		return -1;
}
int Calculator::cal(Token first, Token second, Token oper)
{
	int f = first.getNumber();
	int s = second.getNumber();
	char o = oper.getOper();
	switch(o){
		case '+':
			return f + s;
		case '-':
			return f - s;
		case '~':
			return f - s;
		case '^':
			return pow(f, s);
		case '*':
			return f * s;
		case '/':
			if(s == 0)
				throw std::runtime_error("Divide by zero");
			return f / s;
		case '%':
			if(s == 0)
				throw std::runtime_error("Divide by zero");
			return f % s;
		default :
			throw std::runtime_error("Input Error") ;
	}
}




Expression Calculator::toPostfix(Expression infix)
{
	Stack<Token> temp; //forBracket
	Stack<Token> postfix;
	Stack<Token> reverse;

	temp.push(Token('#'));//EOS	MARK
	reverse.push(Token('#'));//EOS	MARK
	for (Token x = infix.getToken().top(); x != '#' ; x = infix.nextToken())
	{
		if(x.isNumber())
			reverse.push(x);
		else if( x == ')')
		{
			for(; temp.top() != '(' ; temp.pop())
			{
				reverse.push(temp.top());
			}
			temp.pop();
		}	
		else
		{
			for(;getISP(temp.top()) <= getICP(x);temp.pop())
				reverse.push(temp.top());
			temp.push(x);
		}
	}//EndOfFor
	for (; temp.top() != '#' ; temp.pop())
	{
		reverse.push(temp.top());
	}
	
	postfix.push(Token('#'));//EOS	MARK

	for (; reverse.top() != '#' ; reverse.pop())
	{
		postfix.push(reverse.top());
	}
	
	return Expression(postfix);

}//EndOfFunction

int Calculator::getAnswer(Expression postfix)
{
	Stack<Token> temp; //forBracket

	for(Token x = postfix.getToken().top(); x != '#';  x = postfix.nextToken())
	{
		if (x.isNumber())
		{
			temp.push(x);
		}
		else if(x.getOper() != '~')
		{
			if(temp.isEmpty() || !temp.top().isNumber())
				throw std::runtime_error("Input Error1") ;
			Token second = temp.top(); temp.pop();
			if(temp.isEmpty() || !temp.top().isNumber())
				throw std::runtime_error("Input Error2") ;
			Token frist = temp.top(); temp.pop();
			int result = cal(frist, second, x);
			temp.push(Token(result));
		}
		else if (x.getOper() == '~')
		{
			if(!temp.top().isNumber())
				throw std::runtime_error("Input Error3") ;
			int result = -1 * temp.top().getNumber() ;
			temp.pop();
			if (!temp.isEmpty()&&temp.top().isNumber())
			{	
				if(x!='#')
					result = cal(temp.top().getNumber(), result,postfix.nextToken());

				temp.pop();
			}
			temp.push(Token(result));
		}
		else
			throw std::runtime_error("Input Error4") ;
	}
	return temp.top().getNumber();
}//EndOfFunction