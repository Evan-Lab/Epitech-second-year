##
## EPITECH PROJECT, 2023
## Assembly
## File description:
## Makefile
##

SRC			=	strlen.asm	\
				strchr.asm	\
				strrchr.asm	\
				memcpy.asm	\
				strcmp.asm	\
				strncmp.asm	\
				memset.asm	\
				memmove.asm	\
				strstr.asm

SRC_TEST	=	tests/test_strlen.c	\
				tests/test_memcpy.c	\
				tests/test_memset.c	\
				tests/test_strcmp.c	\
				tests/test_memmove.c	\
				tests/test_strncmp.c	\
				tests/test_strchr.c	\
				tests/test_strrchr.c	\
				tests/test_strstr.c

OBJ			=	$(SRC:.asm=.o)

OBJ_TST		=	$(SRC_TST:.asm=.o)

ASM			=	nasm

CC			=	gcc

RM			=	rm -f

CFLAGS		+=	-fpic -shared

CPPFLAGS	+=	-I./include

LDFLAGS		=	-f elf64

TESTFLAGS	=	-lcriterion --coverage -L lasm -ldl

NAME		=	libasm.so

NAMETEST	=	unit_tests

all: 		$(NAME)

%.o: %.asm
			$(ASM) $(LDFLAGS) $< -o $@

$(NAME):	$(OBJ)
			ld $(CFLAGS) $(OBJ) -o $(NAME)

debug:		CFLAGS += -g3
debug:		re

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) all_test
			$(RM) test_strlen
			$(RM) unit_tests
			$(RM) *.gcda
			$(RM) *.gcno

test: re
		$(CC) -o all_test all_test.c $(OBJ)
		LD_PRELOAD=./$(NAME)
		./all_test

tests_run:	re
			$(CC) -o unit_tests $(SRC_TEST) $(TESTFLAGS)
			./unit_tests

re:			fclean all

.PHONY: 	all debug clean fclean re test tests_run
