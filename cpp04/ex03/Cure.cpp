#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("Cure"){
    return;
}

Cure::Cure(const Cure &c) : AMateria("Cure"){
    *this = c;
    return ;
}

Cure::~Cure(void){
    return;
}

Cure &Cure::operator=(const Cure &c){
    *this = c;
    return *this;
}

Cure *Cure::clone(void) const{
    return new Cure();
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.get_name() << "'s wounds" << std::endl;
}