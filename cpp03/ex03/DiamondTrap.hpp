#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{

    private:
        std::string _name;
    
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &ct);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &dt);

        void attack(const std::string &target);
        void whoAmI(void);
    
};

#endif