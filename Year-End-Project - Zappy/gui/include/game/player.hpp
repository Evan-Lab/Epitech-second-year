/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "image.hpp"
#include "sprite.hpp"
#include "enum.hpp"
#include "inventory.hpp"

class Player {
    public:
        Player() = default;
        Player(std::pair<std::string, sf::Color> team, std::pair<int, int> coo, int id, std::string name);
        ~Player() = default;
        void display(std::shared_ptr<sf::RenderWindow> window);
        void moveTo(sf::Vector2f pos, std::pair<int, int> coo);
        void setHeight(int height);
        void setLevel(int level);
        void setFood(int quantity);
        void setOrientation(orientation orientation);
        std::pair<int, int> getCoo() const;
        std::pair<std::string, sf::Color> getTeam() const;
        int getLevel() const;
        int getFood() const;
        Inventory getInventory() const;
        void setInventory(std::vector<std::pair<objectType, int>> inventory);
        int getId() const;
        std::string getName() const;
    private:
        int _food;
        std::pair<std::string, sf::Color> _team;
        int _level;
        orientation _orientation;
        Inventory _inventory;
        std::pair<int, int> _coo;
        playerStatus _status;
        int _id;
        std::string _name;
        std::shared_ptr<Sprite> _flag;
        std::shared_ptr<Sprite> _ship;
};
