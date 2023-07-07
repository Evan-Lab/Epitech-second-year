/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** status
*/

#pragma once

enum guiStatus {
    INMENU,
    INGAME,
};

enum subMenu {
    RECEPTION,
    CONNECT,
};

enum inputType {
    IP,
    PORT,
};

enum anchor {
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    CENTER,
};

enum playerStatus {
    WAITING,
    EVOLVING,
};

enum orientation {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4,
};

enum objectType {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    MILK = 6,
};

enum inventoryType {
    TILE_INV,
    PLAYER_INV,
};

enum buttonStatus {
    NONE,
    ACTIVE,
    INACTIVE,
};
