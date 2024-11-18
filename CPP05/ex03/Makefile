
NAME = intern
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = AForm.cpp Bureaucrat.cpp \
PresidentialPardonForm.cpp RobotomyRequestForm.cpp\
 ShrubberyCreationForm.cpp main.cpp Intern.cpp 
HEADERS = AForm.hpp Bureaucrat.hpp\
PresidentialPardonForm.hpp RobotomyRequestForm.hpp\
 ShrubberyCreationForm.hpp Intern.hpp 

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