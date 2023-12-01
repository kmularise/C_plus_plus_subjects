#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " has been destroyed." << "\n";
}

void    Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << "\n";
}

void    Zombie::setName( std::string name ) {
    this->_name = name;
}