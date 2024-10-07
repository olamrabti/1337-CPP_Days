
NAME = program
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.class.cpp PhoneBook.class.cpp
HEADERS = Contact.class.hpp PhoneBook.class.hpp
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
