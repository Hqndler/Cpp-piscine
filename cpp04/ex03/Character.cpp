#include "Character.hpp"

Character::Character(void){
    for (int i = 0; i < 4; i++)
        items[i] = NULL;
    name = "Anon";
    return ;
}

Character::Character(const std::string &name) : name(name){
    for (int i = 0; i < 4; i++)
        items[i] = NULL;
}

Character::Character(const Character &c){
    for (int i = 0; i < 4; i++)
        items[i] = c.items[i]->clone();
    name = c.name;
}

Character::~Character(void){
    for (int i = 0; i < 4; i++)
        if (items[i])
            delete items[i];
    return ;
}

Character &Character::operator=(const Character &c){
    for (int i = 0; i < 4; i++)
        items[i] = c.items[i]->clone();
    return *this;
}

std::string const &Character::get_name(void) const{
    return name;
}

void Character::equip(AMateria *m){
    int i = 0;
    while (i < 4 && items[i])
        ++i;
    if (i == 4){
        std::cout << get_name() << "'s inventory is full !" << std::endl;
        delete m;
        return;
    }
    items[i] = m;
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4){
        items[idx] = NULL;
    }
    else
        std::cout << "Wrong index" << std::endl;
}

void Character::use(int idx, ICharacter &target){
    if (idx >= 0 && idx < 4 && items[idx])
        items[idx]->use(target);
    else
        std::cout << "Wrong index" << std::endl;
}