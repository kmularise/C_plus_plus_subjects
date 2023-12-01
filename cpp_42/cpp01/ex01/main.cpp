#include "Zombie.hpp"

int main( void ) {
    int n = 10;
    Zombie* zombieCrowds = zombieHorde(n, "redis");
    for (int i = 0 ; i < n; i++) {
        zombieCrowds[i].announce();
    }
    delete [] zombieCrowds;
    return 0;
}