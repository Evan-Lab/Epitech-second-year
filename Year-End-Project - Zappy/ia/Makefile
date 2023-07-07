##
## EPITECH PROJECT, 2023
## Zappy_ai
## File description:
## Makefile
##

SRC = src/main.py
MAIN = src/main.py
NAME = zappy_ai

all: $(NAME)

$(NAME): $(SRC)
	cp $(MAIN) $(NAME)
	chmod +x $(NAME)
	cp $(NAME) ../$(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

