NAME	= clap_trap
	
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: clean re

$(NAME): ClapTrap.cpp main.cpp
	$(CXX) $(CXXFLAGS) ClapTrap.cpp main.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all