##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

PATH_ASSETS = gui/assets/
ASSETS_NAME = /assets

all: zappy_server zappy_gui zappy_ia

zappy_server:

	make -C serveur
	cp -r  $(PATH_ASSETS) assets

zappy_gui:

	make -C gui

zappy_ia:

	make -C ia

fclean:
	make fclean -C serveur
	make fclean -C gui
	make fclean -C ia
	$(RM) zappy_server
	$(RM) zappy_gui
	$(RM) zappy_ai
	$(RM) -r assets

re: fclean all

.PHONY: all clean fclean re zappy_server zappy_gui zappy_ia
