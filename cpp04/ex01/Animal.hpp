#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal{

    protected:
        std::string _type;

    public:
        Animal(void);
        Animal(const std::string name);
        virtual ~Animal(void);
        Animal(const Animal &a);
        Animal &operator=(const Animal &a);

        std::string get_type(void) const;
        virtual void makeSound(void) const;
        virtual Brain *get_brain(void) const;

};

#endif