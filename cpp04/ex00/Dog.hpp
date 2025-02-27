#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{

    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog &d);
        Dog &operator=(const Dog &d);
        virtual void makeSound(void) const;
        std::string get_type(void) const;
};

#endif