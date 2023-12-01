#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie *zombieCrowds = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombieCrowds[i].setName(name);
    }
    return zombieCrowds;
}