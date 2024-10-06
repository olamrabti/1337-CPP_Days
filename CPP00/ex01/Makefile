
NAME = program
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.class.cpp PhoneBook.class.cpp
HEADERS = Contact.class.hpp PhoneBook.class.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

fclean: 
	rm -f $(NAME)

re: fclean all
