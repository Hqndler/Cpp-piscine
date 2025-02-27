#include "Zombie.hpp"

int main(void){
    Zombie  *horde;
    int     N = 10;

    horde = zombieHorde(N, "Bob");

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete [] horde;
    return (0);
}