#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
    std::cout << "Cat default constructor called" << std::endl;
    return ;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &c) : Animal(){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = c;
}

Cat &Cat::operator=(const Cat &c){
    std::cout << "Cat assignement operator called" << std::endl;
    _type = c._type;
    return *this;
}

std::string Cat::get_type(void) const{
    return _type;
}

void Cat::makeSound(void) const{
    std::cout << "Miaou" << std::endl;
}