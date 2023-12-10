NAME	= animal
	
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: clean re

$(NAME): Brain.cpp Cat.cpp Dog.cpp Animal.cpp main.cpp 
	$(CXX) $(CXXFLAGS) Brain.cpp Cat.cpp Dog.cpp Animal.cpp main.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all