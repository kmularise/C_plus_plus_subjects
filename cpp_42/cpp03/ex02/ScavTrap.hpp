#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>


class ScavTrap : public ClapTrap {
 private:
	
 public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj);
	void guardGate();
};

#endif
