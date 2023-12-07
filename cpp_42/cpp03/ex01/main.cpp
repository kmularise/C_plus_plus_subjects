#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap yuikimScav = ScavTrap("yuikimScav");
	yuikimScav.attack("keyboard");
	yuikimScav.beRepaired(3);
	yuikimScav.guardGate();
	yuikimScav.takeDamage(20);
	yuikimScav.takeDamage(33);
	yuikimScav.beRepaired(3);
	ScavTrap scavTrap = ScavTrap("Mike");
	for (int i = 0 ; i < 100 ; i++) {
		scavTrap.attack("keyboard");
	}
	scavTrap.beRepaired(3);
	return 0;
}