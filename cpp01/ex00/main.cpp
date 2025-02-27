#include "Zombie.hpp"

int main(void){
    Zombie *zombie = newZombie("Bob");
    zombie->announce();

    randomChump("Bob2");
    
    delete zombie;
    return 0;
}