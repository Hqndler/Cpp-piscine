#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{

    protected:
        std::string _name;
        int _hp;
        int _ep;
        int _ad;

    public:
        ClapTrap(void);
        ~ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &c);
        ClapTrap &operator=(const ClapTrap &c);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string get_name(void) const;
        int get_hp(void) const;
        int get_ep(void) const;
        int get_ad(void) const;

};

#endif