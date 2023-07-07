##
## EPITECH PROJECT, 2023
## day06
## File description:
## Makefile
##

SRC	=	MyCat.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -Werror

NAME	=	MyCat

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -std=c++20 -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
