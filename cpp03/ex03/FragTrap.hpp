#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

    public:
        FragTrap(void);
        FragTrap(const std::string name);
        FragTrap(const FragTrap &ct);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &ft);

        void highFivesGuys(void);
};

#endif