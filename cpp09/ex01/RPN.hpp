#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>

class Error : public std::exception{
    public:
        virtual const char *what() const throw(){
            return "Error";
        }
};

void rpn(const std::string &str);

#endif