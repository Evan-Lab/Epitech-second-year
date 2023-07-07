##
## EPITECH PROJECT, 2023
## nanotekspice
## File description:
## Makefile
##

## ===========================================================
## ===========================[SRC]===========================
## ===========================================================

SRC	=	presentation/main.cpp	\
		presentation/simulation.cpp	\
		cross_cutting/exception.cpp	\
		cross_cutting/string_utils.cpp		\
		infra/command_line_handler.cpp		\
		infra/parser.cpp					\
		model/circuit.cpp					\
		model/component.cpp					\
		model/link.cpp						\
		model/logic.cpp						\
		model/component/output.cpp			\
		model/component/input.cpp			\
		model/component/and.cpp				\
		model/component/or.cpp				\
		model/component/true.cpp			\
		model/component/input_output.cpp	\
		model/component/not.cpp				\
		model/component/xor.cpp				\
		model/component/false.cpp			\
		model/component/clock.cpp			\
		model/component/4081_and.cpp		\
		model/component/4071_or.cpp			\
		model/component/4011_nand.cpp		\
		model/component/4001_nor.cpp		\
		model/component/4030_xor.cpp		\
		model/component/4069_not.cpp		\
		model/component/and_or_not.cpp		\

## ===========================================================
## ===========================[VARIABLE]======================
## ===========================================================

NAME	=	nanotekspice

BUILDDIR	=	build

OBJ_SRC	=	$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o:	src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -c -o $@ $<

CXXFLAGS	=	-std=c++20 -Wall -Wextra

INCLUDE_FLAGS	=	-I./include

CXX	=	g++

RM	=	rm -f


## ===========================================================
## ===========================[RULES]=========================
## ===========================================================

all:	$(NAME)

$(NAME):	$(OBJ_SRC)
			$(CXX) -o $(NAME) $(OBJ_SRC)

debug:	CXXFLAGS += -g3
debug:	re

clean:
		$(RM) $(OBJ_SRC)

fclean:	clean
		$(RM) -r build
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re