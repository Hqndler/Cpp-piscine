#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
    std::cout << "ClapTrap Default constructor called" << std::endl;
    return;
}

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap Destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0){
    std::cout << "ClapTrap Constructor called" << std::endl;
    return;
}

std::string ClapTrap::get_name(void) const{
    return this->_name;
}

int ClapTrap::get_hp(void) const{
    return this->_hp;
}

int ClapTrap::get_ep(void) const{
    return this->_ep;
}

int ClapTrap::get_ad(void) const{
    return this->_ad;
}

ClapTrap::ClapTrap(const ClapTrap &c){
    *this = c;
    std::cout << "ClapTrap copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c){
    this->_name = c.get_name();
    this->_hp = c.get_hp();
    this->_ep = c.get_ep();
    this->_ad = c.get_ad();
    std::cout << "ClapTrap assignment operator called" << std::endl;

    return *this;
}

void ClapTrap::attack(const std::string &target){
    if (this->_ep && this->_hp){
        this->_ep -= 1;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
    }
    else if (!this->_ep && this->_hp)
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points to attack." << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hp){
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage." << std::endl;
        this->_hp -= (int)amount;
        if (this->_hp < 0)
            this->_hp = 0;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_ep && this->_hp){
        this->_ep -= 1;
        std::cout << "ClapTrap " << this->_name << " repaired himself " << amount << " hp." << std::endl;
        this->_hp += (int)amount;
    }
    else if (!this->_ep && this->_hp)
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points to repair himself." << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
}