#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* wolfy = new Dog();
	std::cout << std::endl;
	const Animal* kitty = new Cat();
	std::cout << std::endl;
	const WrongAnimal* daisy = new WrongCat();

	std::cout << std::endl;
	std::cout << "\nwolfy: " << wolfy->get_type() << std::endl;
	wolfy->makeSound(); 
	std::cout << "\nkitty: " << kitty->get_type() << std::endl;
	kitty->makeSound();
	std::cout << "\nmeta: " << meta->get_type() << std::endl;
	meta->makeSound();
	std::cout << "\ndaisy: " << daisy->get_type() << std::endl;
	daisy->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	Animal *	meta2 = new Animal(*meta);
	std::cout << "meta2: " << meta2->get_type() << std::endl;
	meta2->makeSound();

	std::cout << std::endl;
	std::cout << "SnowBall4 ancestors\n";
	Cat*	SnowBall1 = new Cat();
	Cat		SnowBall2 = *SnowBall1;
	Cat*		SnowBall3 = new Cat(SnowBall2);
	
	std::cout << std::endl;
	std::cout << "SnowBall3 is a : " << SnowBall3->get_type() << std::endl;
	SnowBall3->makeSound();

	std::cout << std::endl;
	
	WrongCat*	SnowBall4 = new WrongCat();
	std::cout << "SnowBall4 is a : " << SnowBall4->get_type() << std::endl;
	SnowBall4->makeSound();


	std::cout << std::endl;
	std::cout << "And now Ladies and Gentlemen, Santa's Little Helper progeny\n";
	Dog*	slh = new Dog();
	Dog		slh2 = *slh;
	Dog*	slh3 = new Dog(slh2);
	std::cout << "Santa's Little Little Little Helper is a : " << slh3->get_type() << std::endl;
	slh3->makeSound();


	std::cout << std::endl;
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete meta2;
	std::cout << std::endl;
	delete kitty;
	std::cout << std::endl;
	delete wolfy;
	std::cout << std::endl;
	delete daisy;
	std::cout << std::endl;
	delete SnowBall1;
	std::cout << std::endl;
	delete SnowBall3;
	std::cout << std::endl;
	delete SnowBall4;
	std::cout << std::endl;
	delete slh;
	std::cout << std::endl;
	delete slh3;

	return 0;
}
