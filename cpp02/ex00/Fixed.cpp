#include "Fixed.hpp"

Fixed::Fixed(void) : _nbr(0){
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &f){
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_nbr;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_nbr = raw;
}

Fixed &Fixed::operator=(Fixed const &f){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_nbr = f.getRawBits();

    return *this;
}