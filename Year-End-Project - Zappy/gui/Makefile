##
## EPITECH PROJECT, 2023
## zappy_gui
## File description:
## Makefile
##

MAIN_SRC	=	src/main.cpp

SRC	=	src/basics/image.cpp		\
		src/basics/text.cpp			\
		src/basics/rectangle.cpp	\
		src/basics/sprite.cpp		\
		src/gui.cpp					\
		src/cursor.cpp				\
		src/tools.cpp				\
		src/menu/menu.cpp			\
		src/menu/title.cpp			\
		src/menu/button.cpp			\
		src/menu/textInput.cpp		\
		src/game/map.cpp			\
		src/game/tile.cpp			\
		src/game/game.cpp			\
		src/game/inventory.cpp		\
		src/game/part.cpp			\
		src/game/player.cpp			\
		src/game/hud.cpp			\
		src/game/egg.cpp			\
    	src/client.cpp				\

OBJ	=	 $(SRC:src/%.cpp=obj/%.o)

MAIN_OBJ	=	$(MAIN_SRC:src/%.cpp=obj/%.o)

CXX	=	g++

CXXFLAGS	=	-std=c++20 -Wall -Wextra

CPPFLAGS	=	-iquote include -iquote include/basics -iquote include/game -iquote include/menu

LDLIBS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	zappy_gui

all:	$(NAME)

obj/%.o:	src/%.cpp
	mkdir -p $(@D)
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(OBJ) $(MAIN_OBJ) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@cp $(NAME) ..

clean:
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	find . -name *.gcno -delete
	find . -name *.gcda -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
