NAME	=	Byro

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp

CC		=	c++

FtoO	=	$(FILES:.cpp=.o)

all: $(NAME)

$(NAME):	$(FtoO)
	@echo "compiling"
	@$(CC) $(CFLAGS) $(FtoO) -o $(NAME)
	@echo "compiled"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(FtoO)

fclean: clean
	$(RM) $(NAME) $(FtoO)

re: fclean $(NAME)

.PHONY: all clean fclean re