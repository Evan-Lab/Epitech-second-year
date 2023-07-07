/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** gui
*/

#include "gui.hpp"
#include "client.hpp"
#include <iostream>

Gui::Gui()
{
    sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
    _window = std::make_shared<sf::RenderWindow>(fullscreenMode, "Zappy", sf::Style::Fullscreen);
    _window->setMouseCursorVisible(false);
    _window->setFramerateLimit(60);
    _game = std::make_shared<Game>(_window);
    _menu = std::make_shared<Menu>(_window);
    _client = std::make_shared<Client>();
    _status = std::make_shared<guiStatus>(INMENU);
}

void Gui::run()
{
    while (_window->isOpen()) {
        manageEvent();
        if (*_status == INMENU) {
            _menu->update(_window);
            _menu->display(_window);
        }
        else if (*_status == INGAME) {
            _client->run();
            _game->update(_window);
            _game->display(_window);
        }
    }
}

void Gui::manageEvent()
{
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
            exit(0);
        }
        switch(*_status) {
            case INMENU:
                _menu->manageEvents(event, _window, _status, _client, _game);
                break;
            case INGAME:
                _game->manageEvents(event, _window);
                break;
            default:
                break;
        }
    }
}
