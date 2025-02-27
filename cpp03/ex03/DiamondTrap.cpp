#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap(){
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    _hp = 100;
    _ep = 50;
    _ad = 30;
    return;
}

DiamondTrap::~DiamondTrap(void){
    std::cout << "DiamondTrap Destructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name){
    std::cout << "DiamondTrap constructor called" << std::endl;
    _hp = 100;
    _ep = 50;
    _ad = 30;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ct) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = ct;
    return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt){
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    _name = dt._name;
    ClapTrap::_name = dt.ClapTrap::_name;
    _hp = dt._hp;
    _ep = dt._ep;
    _ad = dt._ad;
    return *this;
}

void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void){
    std::cout << "My name is " << _name << ", " << ClapTrap::_name << "." << std::endl;
}