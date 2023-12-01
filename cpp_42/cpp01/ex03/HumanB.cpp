#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {
	
}

void HumanB::attack() {
	if (weapon != NULL && !weapon->getType().empty())
		std::cout << name << " attacks with their " << this->weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}