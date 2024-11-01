NAME = animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp 
HEADERS = Animal.hpp  Cat.hpp Dog.hpp 

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