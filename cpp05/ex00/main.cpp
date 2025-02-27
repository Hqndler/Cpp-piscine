#include "Bureaucrat.hpp"

int main(void){
	try{
		Bureaucrat	machin = Bureaucrat();
		Bureaucrat	machin2 = Bureaucrat(machin);
		Bureaucrat	machin3 = Bureaucrat();
		machin3 = machin2;

		std::cout << machin3 << std::endl << std::endl;

		Bureaucrat	besos = Bureaucrat("Jeff", 3);
		std::cout << besos << std::endl << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat toohigh = Bureaucrat("Lul", 0);
		std::cout << toohigh << std::endl << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		std::cout << "0 is not in the value range, you're spotted miles away" << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat toolow = Bureaucrat("lol", 151);
		std::cout << toolow << std::endl << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		std::cout << "What do you want to do when you can't do anything ? GET OUT OF HERE!!!" << std::endl;

	}

	std::cout << std::endl;

	try{	
		Bureaucrat	machin = Bureaucrat("John", 150);
		for (int i = 0; i < 4; i++){
			std::cout << "Great job " << machin.get_name() << ". I promote you\n";
			machin.upgrade();
			std::cout << machin << "\n\n";
		}
		for (int i = 0; i < 6; i++){
			std::cout << "YOU ASSHOLE " << machin.get_name() << "! I'LL DEMOTED YOU!!!\n";
			machin.downgrade();
			std::cout << machin << "\n\n";
		}
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		std::cout << "John is now unemployed :(" << std::endl;
	}
}