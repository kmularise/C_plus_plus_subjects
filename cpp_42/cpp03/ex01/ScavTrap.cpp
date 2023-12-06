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
	if (&obj != this) {
		this->attackDamage = obj.attackDamage;
		this->energyPoints = obj.energyPoints;
		this->hitPoints = obj.hitPoints;
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}