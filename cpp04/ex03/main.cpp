#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{

	AMateria * tmp;
	AMateria *	garbage;

	std::cout << "Materia source\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	std::cout << std::endl;
	std::cout << "Materia source2\n";
	MateriaSource*	src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	MateriaSource*	src3 = src2;

	std::cout << "\nCharacter\n";
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	tmp = src->createMateria("Ice");
	me->equip(tmp);
	garbage = src->createMateria("Cure");
	me->equip(garbage);

	tmp = src3->createMateria("Ice");
	me->equip(tmp);
	tmp = src3->createMateria("Cure");

	
	std::cout << "\nusing staff.\n";	
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);
	me->use(2, *me);
	me->use(5, *bob);
	me->use(-42, *bob);

	std::cout << "\nFilling Bob's backpack\n";
	tmp = src->createMateria("Ice");
	bob->equip(tmp);
	tmp = src->createMateria("Cure");
	bob->equip(tmp);
	tmp = src->createMateria("Ice");
	bob->equip(tmp);
	tmp = src->createMateria("Cure");
	bob->equip(tmp);
	tmp = src->createMateria("Ice");
	bob->equip(tmp);
	tmp = src->createMateria("Cure");
	bob->equip(tmp);

	std::cout << std::endl;
	for (int i = -2; i < 6; i++)
		bob->use(i, *me);

	delete bob;
	delete me;
	delete src;
	delete src2;
	delete garbage;
	return 0;
}