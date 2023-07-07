##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## Makefile
##

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu17 -Wall -Wextra

NAME	=	z

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean all clean
