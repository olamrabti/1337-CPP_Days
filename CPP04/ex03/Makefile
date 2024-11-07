NAME = interface
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp  main.cpp
HEADERS = AMateria.hpp IMateriaSource.hpp Ice.hpp Character.hpp Cure.hpp ICharacter.hpp MateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all