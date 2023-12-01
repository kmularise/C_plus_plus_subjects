NAME	= unnecessary_violence
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: all clean re

all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) HumanA.cpp HumanB.cpp Weapon.cpp main.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all