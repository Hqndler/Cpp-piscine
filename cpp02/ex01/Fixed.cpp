#include "Fixed.hpp"

Fixed::Fixed(void) : _nbr(0){
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int n){
    std::cout << "Integer constructor called" << std::endl;
    this->_nbr = n << this->_fix;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    this->_nbr = (int)roundf(f * (1 << this->_fix));
}

float Fixed::toFloat(void) const{
    return ((float)this->_nbr / (1 << this->_fix));
}

int Fixed::toInt(void) const{
    return this->_nbr >> this->_fix;
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
    // std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream &o, Fixed const &f){
    o << f.toFloat();
    return o;
}