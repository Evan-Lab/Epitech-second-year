##
## EPITECH PROJECT, 2023
## rush2
## File description:
## Makefile
##

SRCTEST	=	tests/test.c	\
			new.c	\
			player.c	\
			vertex.c	\
			point.c	\
			float.c	\


TEST	=	-lcriterion --coverage

tests_run:
	gcc -o unit_tests $(SRCTEST) $(TEST)
	./unit_tests

clean:
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) unit_tests
	$(RM) *.gcda
	$(RM) *.gcno

.PHONY: all clean fclean tests_run
