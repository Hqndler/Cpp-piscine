#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
    std::cout << "FragTrap Default constructor called" << std::endl;
    _hp = 100;
    _ep = 100;
    _ad = 30;
    return;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap Destructor called" << std::endl;
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap constructor called" << std::endl;
    _hp = 100;
    _ep = 100;
    _ad = 30;
    return;
}

FragTrap::FragTrap(const FragTrap &ct) : ClapTrap(ct){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &st){
    std::cout << "FragTrap assignment operator called" << std::endl;
    _name = st._name;
    _hp = st._hp;
    _ep = st._ep;
    _ad = st._ad;
    return *this;
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _name << " wants to High Five" << std::endl;
}