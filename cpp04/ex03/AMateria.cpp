#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void){
    return;
}

AMateria::~AMateria(void){
    return;
}

AMateria::AMateria(std::string const &type){
    this->_type = type;
    return;
}

AMateria::AMateria(const AMateria &m){
    *this = m;
}

AMateria &AMateria::operator=(const AMateria &m){
    this->_type = m._type;
    return *this;
}

std::string const &AMateria::get_type(void) const{
    return _type;
}

void AMateria::use(ICharacter &target){
    std::cout << "Won't do anything to " << target.get_name() << std::endl;
    return;
}