#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed()){
    return;
}

Point::~Point(void){
    return;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)){
    return;
}

Point::Point(const Point &p) : _x(p._x), _y(p._y){
    return;
}

Point &Point::operator=(Point const &p){
    // this->_x = p._x;
    // this->_y = p._y;
    (void)p;

    return *this;
}

Fixed Point::get_x(void) const{
    return this->_x;
}

Fixed Point::get_y(void) const{
    return this->_y;
}