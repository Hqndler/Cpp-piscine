#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal(){
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "WrongCat";
    return ;
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &d) : WrongAnimal(){
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = d;
}

WrongCat &WrongCat::operator=(const WrongCat &d){
    std::cout << "WrongCat assignement operator called" << std::endl;
    _type = d._type;
    return *this;
}

std::string WrongCat::get_type(void) const{
    return _type;
}

void WrongCat::makeSound(void) const{
    std::cout << "Miouaf Miouaf" << std::endl;
}