#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return;
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a){
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    this->_type = a._type;
    return *this;
}

std::string WrongAnimal::get_type(void) const{
    return _type;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "The wrong sound of silence" << std::endl;
}