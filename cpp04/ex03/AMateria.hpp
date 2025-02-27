#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria{

    protected:
        std::string _type;

    public:
        AMateria(void);
        virtual ~AMateria(void);
        AMateria(const AMateria &m);
        AMateria &operator=(const AMateria &m);

        AMateria(std::string const &type);

        std::string const &get_type(void) const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};

#endif