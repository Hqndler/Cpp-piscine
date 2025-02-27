#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter{

    private:
        std::string name;
        AMateria *items[4];

    public:
        ~Character(void);
        Character(void);
        Character(const std::string &name);
        Character(const Character &c);
        Character &operator=(const Character &c);

        virtual std::string const & get_name(void) const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};

#endif