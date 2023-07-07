##
## EPITECH PROJECT, 2023
## day05
## File description:
## Makefile
##

SRC	=	string.c	\
		assign.c	\
		append.c	\
		at_function.c		\
		clear.c		\
		lenght.c	\
		compare.c	\
		c_str_function.c	\
		empty.c		\
		copy.c		\
		find.c		\
		to_int.c	\
		insert.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu17 -Wall -Wextra

CPPFLAGS	=	-I./include

NAME	=	libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) $(CFLAGS)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean all clean
