/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** menu
*/

#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "text.hpp"
#include "image.hpp"
#include "variables.hpp"
#include "map.hpp"
#include "title.hpp"
#include "button.hpp"
#include "enum.hpp"
#include "textInput.hpp"
#include "client.hpp"

class Menu {
    public:
        Menu() = default;
        Menu(std::shared_ptr<sf::RenderWindow> window);
        ~Menu() = default;
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void update(std::shared_ptr<sf::RenderWindow> window);
        void manageEvents(sf::Event event, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<guiStatus> status, std::shared_ptr<Client> client, std::shared_ptr<Game> game);
    private:
        void receptionEvent(sf::Event event, std::shared_ptr<sf::RenderWindow> window);
        void connectEvent(sf::Event event, std::shared_ptr<Client> client, std::shared_ptr<guiStatus> status, std::shared_ptr<Game> game);
        void switchMusic();
        Title _title;
        std::shared_ptr<Text> _error;
        bool _displayError;
        sf::View _backgroundView;
        sf::View _menuView;
        sf::Clock _clock;
        float _lastUpdate;
        Map _map;
        Cursor _cursor;
        Button _playButton;
        Button _quitButton;
        std::shared_ptr<TextInput> _ipInput;
        std::shared_ptr<TextInput> _portInput;
        Button _backButton;
        Button _connectButton;
        Button _drunkModeButton;
        subMenu _subMenu;
        sf::Music _music;
        sf::Music _drunkMusic;
};
