#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{

    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat &c);
        Cat &operator=(const Cat &c);
        virtual void makeSound(void) const;
        std::string get_type(void) const;

};

#endif