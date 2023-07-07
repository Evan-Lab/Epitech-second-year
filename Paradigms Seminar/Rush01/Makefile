##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	pushswap_checker.hs\

NAME	=	pushswap_checker

RM	=	rm -f

all:	$(NAME)

$(NAME):
	ghc $(SRC) -o $(NAME)

clean:
	$(RM) $(SRC:.hs=.hi)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
