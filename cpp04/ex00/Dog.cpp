#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
    std::cout << "Dog default constructor called" << std::endl;
    return ;
}

Dog::~Dog(void){
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog &d) : Animal(){
    std::cout << "Dog copy constructor called" << std::endl;
    *this = d;
}

Dog &Dog::operator=(const Dog &d){
    std::cout << "Dog assignement operator called" << std::endl;
    _type = d._type;
    return *this;
}

std::string Dog::get_type(void) const{
    return _type;
}

void Dog::makeSound(void) const{
    std::cout << "Wouaf" << std::endl;
}