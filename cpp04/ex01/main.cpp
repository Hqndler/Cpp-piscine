#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

int main()
{
	Animal	*zoo[4];

	for (int i = 0; i < 4; i++){
		if (i % 2 == 0){
			zoo[i] = new Cat();
			zoo[i]->get_brain()->set_idea("Mices taste good.");
		}
		else{
			zoo[i] = new Dog();
			zoo[i]->get_brain()->set_idea("Bones taste good.");
		}
		std::cout << "I am a " << zoo[i]->get_type() << std::endl;
		zoo[i]->get_brain()->thinking();
		std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++){
		delete zoo[i];
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "\nAnd now an unidentified animal\n";
	const Animal*	hector = new Animal();
	hector->makeSound();
	hector->get_brain();
	delete hector;

	return 0;
}