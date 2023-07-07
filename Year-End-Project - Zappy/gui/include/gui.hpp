/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** gui
*/

#pragma once

#include "game.hpp"
#include "menu.hpp"
#include "enum.hpp"
#include "client.hpp"

class Gui {
    public:
        Gui();
        ~Gui() = default;
        void run();
        void manageEvent();
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<Game> _game;
        std::shared_ptr<Menu> _menu;
        std::shared_ptr<Client> _client;
        std::shared_ptr<guiStatus> _status;
};
