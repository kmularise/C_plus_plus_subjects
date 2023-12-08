#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("defualt"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap name : " << name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (&other == this) {
		return *this;
	}
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
		this->hitPoints-=1;
	} else {
		std::cout << "ClapTrap " << this->name << " has no hit points or no energy points.." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->energyPoints <= amount || this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		this->energyPoints = 0;
	} else {
		this->energyPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes Damage " << amount << " and his energy point is now " << this->energyPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		this->energyPoints+= amount;
		std::cout << "ClapTrap " << this->name << " is Repaired " << amount << " and his energy point is now " << this->energyPoints << std::endl;
		this->hitPoints-=1;
	} else {
		std::cout << "ClapTrap " << this->name << "has no hitPoints or no energy points." << std::endl;
	}
}