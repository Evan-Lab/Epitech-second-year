##
## EPITECH PROJECT, 2023
## plazza
## File description:
## Makefile
##

## ===========================================================
## =========================[SRC]=============================
## ===========================================================

SRC	=	main.cpp					\
		Parser/Parser.cpp			\
		Error_handling/Error_handling.cpp	\
		Utils/IPC.cpp				\
		Pizza/APizza.cpp			\
		Pizza/Americana.cpp			\
		Pizza/Fantasia.cpp			\
		Pizza/Margarita.cpp			\
		Pizza/Regina.cpp			\
		Reception/Reception.cpp		\
		Kitchen/Kitchen.cpp			\
		Utils/Clock.cpp				\

## ===========================================================
## ======================[VARIABLE]===========================
## ===========================================================

NAME	=	plazza

BUILDDIR	=	build

OBJ_SRC	=	$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o:	src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

CXXFLAGS	=	-std=c++20 -Wall -Wextra -pthread

CXX	=	g++

## ===========================================================
## =========================[RULES]===========================
## ===========================================================

all:	$(NAME)

$(NAME):	$(OBJ_SRC)
			$(CXX) -o $(NAME) $(OBJ_SRC) $(CXXFLAGS)

debug:	CXXFLAGS += -g3
debug:	re

## ===========================================================
## =========================[CLEAN]===========================
## ===========================================================

clean:
		$(RM) $(OBJ_SRC)

fclean:	clean
		$(RM) $(NAME)
		$(RM) -r $(BUILDDIR)

re:	fclean all

## ===========================================================
## =========================[PHONY]===========================
## ===========================================================

.PHONY:	all clean fclean re