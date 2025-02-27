#include "Zombie.hpp"

Zombie::Zombie(void){
    return;
}

Zombie::~Zombie(void){
    return;
}

void    Zombie::set_name(std::string name){
    this->_name = name;
}

void    Zombie::announce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
