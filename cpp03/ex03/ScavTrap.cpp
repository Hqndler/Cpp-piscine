#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
    std::cout << "ScavTrap Default constructor called" << std::endl;
    _hp = 100;
    _ep = 50;
    _ad = 20;
    return;
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap Destructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap constructor called" << std::endl;
    _hp = 100;
    _ep = 50;
    _ad = 20;
    return;
}

ScavTrap::ScavTrap(const ScavTrap &ct) : ClapTrap(ct){
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st){
    std::cout << "ScavTrap assignment operator called" << std::endl;
    _name = st._name;
    _hp = st._hp;
    _ep = st._ep;
    _ad = st._ad;
    return *this;
}

void ScavTrap::attack(const std::string &target){
    if (this->_ep && this->_hp){
        this->_ep -= 1;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
    }
    else if (!this->_ep && this->_hp)
        std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points to attack." << std::endl;
    else
        std::cout << "ScavTrap " << this->_name << " is already dead." << std::endl;
    return;
}

void ScavTrap::guardGate(void){
    std::cout << std::endl;
    std::cout << "/*****   MAY I HAVE YOUR ATTENTION PLEASE   *****\\" << std::endl;
    std::cout << " ScavTrap " << _name << " keep the gate" << std::endl;
    std::cout << "  \\*****   THANK YOU FOR YOUR ATTENTION   *****/  " << std::endl;
    std::cout << std::endl;
    return;
}