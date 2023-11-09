#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "Create zombie on the stack." << std::endl;
    Zombie zombi1("stackZombie");
    zombi1.announce();

    std::cout << "Create zombie on the heap." << std::endl;
    Zombie *zombi2 = newZombie("heapZombie");
    zombi2->announce();
    delete zombi2;
    std::cout << "Call randomChump()." << std::endl;
    randomChump("randi");
    return 0;
}