##
## EPITECH PROJECT, 2023
## groundhog
## File description:
## Makefile
##

SRC	=	main.c							\
		groundhog.c						\
		utils/check_is_number.c			\
		utils/help.c					\
		calculs.c						\
		printer.c						\
		weirdest_values.c				\
		utils/remove_nb_characters.c	\
		utils/error_checker.c			\

SRCTEST	=	tests/test_is_number.c		\
			tests/test_help.c			\
			src/utils/check_is_number.c	\
			src/utils/help.c			\
			tests/test_temperature.c	\
			src/calculs.c				\
			tests/test_weirdest.c 		\
			src/weirdest_values.c		\

TESTFLAGS	=	-lcriterion --coverage

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

CFLAGS	=	-Wall -Wextra -lm

CPPFLAGS	=	-I./include

NAME	=	groundhog

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug: CPPFLAGS += -g3
debug: re

tests_run:
		gcc -o unit_tests $(SRCTEST) $(CFLAGS) $(CPPFLAGS) $(TESTFLAGS)
		./unit_tests

clean:
	@$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) unit_tests
	$(RM) -r $(BUILDDIR)
	$(RM) *.gcda
	$(RM) *.gcno

re: fclean all clean

.PHONY: fclean all clean debug re tests_run
