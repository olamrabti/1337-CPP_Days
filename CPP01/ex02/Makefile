

NAME = brain
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.cpp 
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)

re: fclean all
