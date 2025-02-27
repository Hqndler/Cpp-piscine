#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{

    private:
        Brain *brain;

    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat &c);
        Cat &operator=(const Cat &c);
        virtual void makeSound(void) const;
        std::string get_type(void) const;
        virtual Brain *get_brain(void) const;

};

#endif