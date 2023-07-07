/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** object
*/

#pragma once

#include <string>
#include <memory>
#include "enum.hpp"
#include "image.hpp"
#include "text.hpp"
#include "egg.hpp"

class Inventory
{
    public:
        Inventory() = default;
        Inventory(inventoryType type);
        ~Inventory() = default;
        void setPos(sf::Vector2f pos);
        void setQuantity(objectType type, int quantity);
        int getQuantity(objectType type) const;
        void setInventory(std::vector<std::pair<objectType, int>> inventory);
        void displayForTile(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages) const;
        void displayForHud(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> itemsImages, std::shared_ptr<Image> egg) const;
        void setType(inventoryType type);
    private:
        std::vector<std::pair<objectType, int>> _objects;
        inventoryType _type;
        sf::Vector2f _pos;
};
