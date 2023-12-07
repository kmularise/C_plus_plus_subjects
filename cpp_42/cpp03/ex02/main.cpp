#include "FragTrap.hpp"

int main( void ) {
	FragTrap yuikimFrag = FragTrap("yuikimFrag");
	yuikimFrag.attack("keyboard");
	yuikimFrag.highFivesGuys();
	yuikimFrag.beRepaired(3);
	yuikimFrag.takeDamage(20);
	yuikimFrag.takeDamage(83);
	yuikimFrag.beRepaired(3);

	FragTrap fragTrap = FragTrap("Mike");
	for (int i = 0 ; i < 100 ; i++) {
		fragTrap.attack("keyboard");
	}
	fragTrap.beRepaired(3);
	return 0;
}