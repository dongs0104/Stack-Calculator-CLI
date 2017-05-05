#include <iostream>
#include <string>

#include "IoHandler.h"

using namespace std;


int main ()
{
	string infix ="";
	IoHandler ioh;
	Calculator c;

	try{
		do{
			cout << "Put in Expression : (End = quit)";
			infix = ioh.getInfix();
			if(infix == "quit")
				break;
			Expression ie(infix);
			cout << "infix " ;ioh.printExpression(ie);
			Expression pe = c.toPostfix(ie);
			cout <<"Postfix is ";
			ioh.printExpression(pe);
			cout <<"Answer is ";
			ioh.printAnswer(pe);
		}while(infix != "quit");
	}	
	catch(const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << '\n';
	}
	return 0;
}