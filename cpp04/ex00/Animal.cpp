#include "Animal.hpp"

Animal::Animal(void) : _type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
    return;
}

Animal::Animal(const std::string name) : _type(name){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void){
    std::cout << "Animal destructor called" << std::endl;
    return;
}

Animal::Animal(const Animal &a){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal &Animal::operator=(const Animal &a){
    std::cout << "Animal assignement operator called" << std::endl;
    this->_type = a._type;
    return *this;
}

std::string Animal::get_type(void) const{
    return _type;
}

void Animal::makeSound(void) const{
    std::cout << "The sound of silence" << std::endl;
}