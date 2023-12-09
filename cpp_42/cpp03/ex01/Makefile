NAME	= scav_trap
	
CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: clean re

$(NAME): ClapTrap.cpp main.cpp ScavTrap.cpp
	$(CXX) $(FLAGS) ClapTrap.cpp main.cpp ScavTrap.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all