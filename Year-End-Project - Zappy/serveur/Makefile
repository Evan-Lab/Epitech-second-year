##
## EPITECH PROJECT, 2023
## Zappy_server
## File description:
## Makefile
##

## ===========================================================
## =========================[SRC]=============================
## ===========================================================

SRC	=	main.c										\
		error_handling/args.c						\
		error_handling/getter_args.c				\
		utils/help.c								\
		utils/check_number.c						\
		utils/clean_str.c							\
		utils/my_itoa.c								\
		utils/str_to_word_array.c					\
		utils/timer.c								\
		utils/get_length.c							\
		utils/display_ressource.c					\
		server/server.c								\
		server/setup_server.c						\
		server/read_socket.c						\
		server/create_client.c						\
		server/parsing_command.c					\
		server/connection.c							\
		server/free.c								\
		server/clock.c								\
		server/do_action.c							\
		server/get_socket_gui.c						\
		server/teams.c								\
		server/init_server.c						\
		server/gui_command.c						\
		commands/server/msz_command.c				\
		commands/server/sgt_command.c				\
		commands/server/tna_command.c				\
		commands/server/sst_command.c				\
		commands/server/mct_command.c				\
		commands/server/bct_command.c				\
		commands/server/ppo_command.c				\
		commands/server/plv_command.c				\
		commands/server/pin_command.c				\
		commands/ai/forward_command.c				\
		commands/ai/right_command.c					\
		commands/ai/left_command.c					\
		commands/ai/look_command.c					\
		commands/ai/fork_command.c					\
		commands/ai/connect_nbr_command.c			\
		commands/ai/take_object_command.c			\
		commands/ai/set_object_down_command.c		\
		commands/ai/inventory_command.c				\
		commands/ai/incantation/incantation_command.c			\
		commands/ai/incantation/choose_incantation_client.c		\
		commands/ai/incantation/remove_ressource.c	\
		commands/ai/incantation/send_notif.c		\
		commands/ai/incantation/level_2.c			\
		commands/ai/incantation/level_3.c			\
		commands/ai/incantation/level_4.c			\
		commands/ai/incantation/level_5.c			\
		commands/ai/incantation/level_6.c			\
		commands/ai/incantation/level_7.c			\
		commands/ai/incantation/level_8.c			\
		game/init_ressources.c						\
		game/init_ressources_two.c					\
		game/ressources_printer.c					\
		game/init_map.c								\
		game/player.c								\
		game/ia_action.c							\
		game/eggs.c									\
		game/spawn_ressources.c						\
		game/player_death.c							\

## ===========================================================
## ======================[VARIABLE]===========================
## ===========================================================

BUILDDIR = build

OBJ = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRC))

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

NAME	=	zappy_server

$(BUILDDIR)/%.o: 	src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

## ===========================================================
## =========================[RULES]===========================
## ===========================================================

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@cp $(NAME) ..

debug: CPPFLAGS += -g3
debug: re

## ===========================================================
## =========================[CLEAN]===========================
## ===========================================================

clean:
	@$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(BUILDDIR)
	$(RM) ../$(NAME)

re: fclean all clean

## ===========================================================
## =========================[PHONY]===========================
## ===========================================================

.PHONY: fclean all clean debug re
