NAME	= animal
	
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: clean re

$(NAME): Dog.cpp Cat.cpp Animal.cpp main.cpp WrongCat.cpp WrongAnimal.cpp
	$(CXX) $(CXXFLAGS) Dog.cpp Cat.cpp Animal.cpp main.cpp WrongCat.cpp WrongAnimal.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all