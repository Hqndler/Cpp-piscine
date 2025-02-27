#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{

    public:
        WrongCat(void);
        ~WrongCat(void);
        WrongCat(const WrongCat &d);
        WrongCat &operator=(const WrongCat &d);
        virtual void makeSound(void) const;
        std::string get_type(void) const;

};

#endif