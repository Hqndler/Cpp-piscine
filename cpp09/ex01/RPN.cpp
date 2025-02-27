#include "RPN.hpp"

void rpn(const std::string &str){
	std::string sep =  " ()";
	std::string op = "+-*/";
	std::list<long int> rpn;
	size_t i;

	for (i = 0; i < str.length(); ++i){
		if (sep.find(str[i]) != std::string::npos)
			continue;

		if (std::isdigit(str[i])){
			if (isdigit(str[i + 1])){
				std::cout << "Number too big : ";
				throw(Error());
			}
			rpn.push_front(str[i] - 48);
			continue;
		}

		else{
			if (rpn.size() < 2)
				throw(Error());

			if (op.find(str[i]) != std::string::npos){
				int a = rpn.front();
				rpn.pop_front();
				int b = rpn.front();
				rpn.pop_front();
				if (str[i] == op[0]) // addition
					rpn.push_front(a + b);
				else if (str[i] == op[1]) // soustraction
					rpn.push_front(b - a);
				else if (str[i] == op[2]) // multiplication
					rpn.push_front(a * b);
				else{ // division
					if (a == 0){
						std::cout << "Division by 0 is forbiden : ";
						throw(Error());
					}
					if (b % a)
						std::cout << "Decimal value lost during division" << std::endl;
					rpn.push_front(b / a);
				}
			}
			else{
				std::cout << "Operand not recognize `" << str[i] << "` : ";
				throw(Error());
			}
		}
	}
	if (rpn.size() == 1)
		std::cout << rpn.front() << std::endl;
	else
		throw(Error());
}