#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>


class FragTrap : public ClapTrap {
 private:
    std::string name;
 public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& obj);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& obj);
    void highFivesGuys(void);
};

#endif