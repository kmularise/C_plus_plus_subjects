#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap yuikim = ClapTrap("yuikim");
	yuikim.attack("keyboard");
	yuikim.beRepaired(3);
	yuikim.takeDamage(10);
	yuikim.takeDamage(3);
	yuikim.attack("mouse");
	yuikim.beRepaired(3);

	ClapTrap clapTrap = ClapTrap("Mike");
	for (int i = 0 ; i < 5 ; i++) {
		clapTrap.attack("template");		
	}
	for (int i = 0; i < 5 ; i++) {
		clapTrap.beRepaired(3);
	}
	clapTrap.beRepaired(3);
	return 0;
}