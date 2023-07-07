##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

CC				=			g++

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=			MyGKrellm

NAME_TEST		=			unit_test

## ==========================[PATHS]==========================

SRC_PATH		=			src/

TEST_PATH		=			tests/

## ===========================[SRC]===========================

SRC				=			src/Main.cpp							\
							src/classes/data/DataGraph.cpp			\
							src/classes/data/DataGraph.hpp			\
							src/src/info_real.cpp					\
							src/src/sfml.cpp						\
							src/src/ncurses.cpp						\


TEST_SRC		=			$(TEST_PATH)tests_error_handling.c		\

OBJ				=			$(SRC:.cpp=.o)

## =========================[OPTIONS]=========================

CFLAGS			=			-std=c++20 -Wall -Wextra

LCRITERION		=			-lcriterion --coverage

SFMLFLAGS		=			-lsfml-graphics -lsfml-window -lsfml-system

NCURSESFLAGS	=			-lncurses

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(SFMLFLAGS) $(NCURSESFLAGS) $(OBJ)

re:			fclean	all

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(NAME_TEST) *gcda *gcno

debug: CFLAGS += -g3
debug: re

tests_run:
	g++ $(LCRITERION) $(SRC) $(TEST_SRC) -o $(NAME_TEST)
	./$(NAME_TEST)

## ===========================[END]===========================

.PHONY:	all	re	clean	fclean	tests_run	debug
