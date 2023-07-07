/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** hud
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "tile.hpp"
#include "image.hpp"
#include "text.hpp"
#include "rectangle.hpp"
#include "inventory.hpp"

class Hud {
    public:
        Hud() = default;
        Hud(std::shared_ptr<sf::RenderWindow> window);
        ~Hud() = default;
        void display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> ImagesList) const;
        void update(std::vector<std::shared_ptr<Player>> playerList, std::vector<std::shared_ptr<Egg>> eggList, std::shared_ptr<sf::RenderWindow> window);
        void setTile(std::shared_ptr<Tile> tile);
    private:
        void updateTileInfo();
        void updatePlayerInfo(std::shared_ptr<sf::RenderWindow> window);
        std::shared_ptr<const Tile> _tile;
        Rectangle _tileInfoShape;
        std::shared_ptr<Text> _tileInfoCoo;
        Inventory _tileInfoInventory;
        std::shared_ptr<const Player> _player;
        std::shared_ptr<const Egg> _egg;
        Rectangle _playerInfoShape;
        std::shared_ptr<Text> _playerInfo;
        Inventory _playerInfoInventory;
};
