#include "Fixed.hpp"

Fixed::Fixed(void) : _nbr(0){
    // std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int n){
    // std::cout << "Integer constructor called" << std::endl;
    this->_nbr = n << this->_fix;
}

Fixed::Fixed(const float f){
    // std::cout << "Float constructor called" << std::endl;
    this->_nbr = (int)roundf(f * (1 << this->_fix));
}

float Fixed::toFloat(void) const{
    return ((float)this->_nbr / (1 << this->_fix));
}

int Fixed::toInt(void) const{
    return this->_nbr >> this->_fix;
}

Fixed::~Fixed(void){
    // std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &f){
    // std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

int Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_nbr;
}

void Fixed::setRawBits(int const raw){
    // std::cout << "setRawBits member function called" << std::endl;
    this->_nbr = raw;
}

Fixed &Fixed::operator=(Fixed const &f){
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_nbr = f.getRawBits();

    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &f){
    o << f.toFloat();
    return o;
}

bool Fixed::operator>(Fixed const &f){
    return (this->getRawBits() > f.getRawBits());
}

bool Fixed::operator<(Fixed const &f){
    return (this->getRawBits() < f.getRawBits());
}

bool Fixed::operator>=(Fixed const &f){
    return (this->getRawBits() >= f.getRawBits());
}

bool Fixed::operator<=(Fixed const &f){
    return (this->getRawBits() <= f.getRawBits());
}

bool Fixed::operator==(Fixed const &f){
    return (this->getRawBits() == f.getRawBits());
}

bool Fixed::operator!=(Fixed const &f){
    return (this->getRawBits() != f.getRawBits());
}

Fixed Fixed::operator+(Fixed const &f){
    Fixed res;

    res.setRawBits(this->_nbr + f._nbr);
    return res;
}

Fixed Fixed::operator-(Fixed const &f){
    Fixed res;

    res.setRawBits(this->_nbr - f._nbr);
    return res;
}

Fixed Fixed::operator*(Fixed const &f){
    Fixed res(this->toFloat() * f.toFloat());
    return res;
}

Fixed Fixed::operator/(Fixed const &f){
    Fixed res;
    if (f.getRawBits() == 0){
        std::cerr << "Division error: can't divide by zero" << std::endl;
        res = 0;
    }
    else
        res = (this->toFloat() / f.toFloat());
    return res;
}

Fixed Fixed::operator++(void){
    this->_nbr += 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    this->_nbr += 1;
    return tmp;
}

Fixed Fixed::operator--(void){
    this->_nbr -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    this->_nbr -= 1;
    return tmp;
}

Fixed &Fixed::min(Fixed &l, Fixed &r){
    if (l._nbr < r._nbr)
        return (l);
    return (r);
}

const Fixed &Fixed::min(Fixed const &l, Fixed const &r){
    if (l._nbr < r._nbr)
        return (l);
    return (r);
}

Fixed &Fixed::max(Fixed &l, Fixed &r){
    if (l._nbr > r._nbr)
        return (l);
    return (r);
}

const Fixed &Fixed::max(Fixed const &l, Fixed const &r){
    if (l._nbr > r._nbr)
        return (l);
    return (r);
}