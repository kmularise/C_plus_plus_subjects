NAME	= materia
	
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
SRC		= main.cpp Ice.cpp Cure.cpp MateriaSource.cpp AMateria.cpp Character.cpp

.PHONY: clean re

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all