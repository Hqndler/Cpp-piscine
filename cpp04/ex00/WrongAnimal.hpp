#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{

    protected:
        std::string _type;

    public:
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal &a);
        WrongAnimal &operator=(const WrongAnimal &a);

        std::string get_type(void) const;
        virtual void makeSound(void) const;

};

#endif