

NAME = program
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.class.cpp PhoneBook.class.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	
%.o: %.cpp 
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: clean all
