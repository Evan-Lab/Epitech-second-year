##
## EPITECH PROJECT, 2023
## groundhog
## File description:
## Makefile
##

SRC	=	main.c					\
		error_handling.c		\
		panoramix.c				\
		druid.c					\
		villageois.c			\
		villageois_actions.c	\

SRCTEST =	tests/test_is_number.c	\
			tests/test_if_more_than_0.c	\
			tests/test_check_args.c		\
			src/error_handling.c		\

TESTFLAGS	=	-lcriterion --coverage

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

CFLAGS	=	-lpthread

CPPFLAGS	=	-I./include

NAME	=	panoramix

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
	$(RM) -rf build
	$(RM) $(NAME)
	$(RM) -r $(BUILDDIR)
	$(RM) unit_tests*

re: fclean all clean

.PHONY: fclean all clean debug re tests_run
