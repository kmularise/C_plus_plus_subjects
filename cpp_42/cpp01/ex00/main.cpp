#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "Create zombie on the stack." << "\n";
    Zombie zombi1("stackZombie");
    zombi1.announce();

    std::cout << "Create zombie on the heap." << "\n";
    Zombie *zombi2 = newZombie("heapZombie");
    zombi2->announce();
    delete zombi2;
    std::cout << "Call randomChump()." "\n";
    randomChump("randi");
    return 0;
}