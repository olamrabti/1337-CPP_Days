
NAME = bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = Bureaucrat.cpp main.cpp
HEADERS = Bureaucrat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.cpp $(HEADERS) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all