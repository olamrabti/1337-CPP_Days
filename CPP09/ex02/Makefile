NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC =  main.cpp PmergeMe.cpp 
HEADERS = PmergeMe.hpp

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