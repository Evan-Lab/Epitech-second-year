##
## EPITECH PROJECT, 2023
## myftp
## File description:
## Makefile
##

SRC	=	main.c	\
		server/server.c	\
		server/reader.c	\
		server/settings.c	\
		server/client.c	\
		utils/take_words.c	\
		utils/is_number.c	\
		Command/command.c	\
		Command/file_transfer.c	\
		Command/retr_command.c	\
		Command/other_commands.c	\
		Command/all_commands.c	\
		Command/command_two.c	\
		Command/listing_command.c	\
		Command/all_commands_two.c	\
		Command/cwd_command.c	\
		Command/delete_file.c	\

SRCTEST	=	src/utils/is_number.c	\
			src/utils/take_words.c	\
			tests/test_is_number.c	\
			tests/test_take_words.c	\

TESTFLAGS	=	-lcriterion --coverage

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

NAME	=	myftp

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
	$(RM) *.gcda
	$(RM) *.gcno

re: fclean all clean

.PHONY: fclean all clean debug re
