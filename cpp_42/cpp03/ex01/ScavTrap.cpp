#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap name : " << name << " constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj){
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	ClapTrap::operator=(obj);
	std::cout << "ScavTrap " << this->name << "operator = is called" << std::endl;
	return *this;
}

void ScavTrap::guardGate() {
	if (this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " can not be in Gate keeper mode because it is dead." << std::endl;
	}
}