#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap name : " << name << " constructor called" << std::endl;
  this->energyPoints = 100;
  this->hitPoints = 100;
  this->attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
  std::cout << "FragTrap Copy constructor called" << std::endl;
}
FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& obj) {
  ClapTrap::operator=(obj);
  std::cout << "FragTrap " << this->name << "operator = is called" << std::endl;
  return *this;
}

void FragTrap::attack(const std::string& target) {
  if (this->hitPoints > 0 && this->energyPoints > 0) {
    std::cout << "FragTrap " << this->name << " attacks " << target
              << " causing " << this->attackDamage << " points of damage!"
              << std::endl;
    this->hitPoints -= 1;
  } else {
    std::cout << "FragTrap " << this->name
              << " has no hit points or no energy points.." << std::endl;
  }
}

void FragTrap::highFivesGuys(void) {
  if (this->energyPoints > 0) {
    std::cout << "FragTrap " << this->name << "asks for a positive highfive.";
  } else {
    std::cout << "FragTrap " << this->name
              << "can not ask for a positive highfive because it is dead.";
  }
};