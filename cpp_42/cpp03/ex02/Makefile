NAME	= frag_trap
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: clean re

$(NAME): ClapTrap.cpp main.cpp FragTrap.cpp
	$(CC) $(FLAGS) ClapTrap.cpp main.cpp FragTrap.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all