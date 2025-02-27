#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("Ice"){
    return;
}

Ice::Ice(const Ice &c) : AMateria("Ice"){
    *this = c;
    return ;
}

Ice::~Ice(void){
    return;
}

Ice &Ice::operator=(const Ice &c){
    *this = c;
    return *this;
}

Ice *Ice::clone(void) const{
    return new Ice();
}

void Ice::use(ICharacter &target){
    std::cout << "* shoots an ice bolt at " << target.get_name() << " *" << std::endl;
}