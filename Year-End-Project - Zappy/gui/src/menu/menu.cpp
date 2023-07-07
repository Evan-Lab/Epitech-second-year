/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** menu
*/

#include <iostream>
#include "menu.hpp"
#include "client.hpp"
#include <thread>

Menu::Menu(std::shared_ptr<sf::RenderWindow> window)
{
    _lastUpdate = 0;
    _title = Title(sf::Vector2f(WINDOW_WIDTH / 2, 200));
    _error = std::make_shared<Text>("Wrong ip or port !", sf::Vector2f(WINDOW_WIDTH / 2, 400), 50, CENTER);
    _error->setFillColor(sf::Color::Red);
    _displayError = false;
    _map = Map(sf::Vector2i(400, -400), 50, 50, false);
    _backgroundView.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    _backgroundView.setCenter(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    _backgroundView.zoom(1);
    _menuView = sf::View();
    _menuView.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    _menuView.setCenter(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    _playButton = Button("Play", sf::Vector2f(WINDOW_WIDTH / 2, 500), 100, CENTER);
    _quitButton = Button("Quit", sf::Vector2f(WINDOW_WIDTH / 2, 700), 100, CENTER);
    _ipInput = std::make_shared<TextInput>("IP :", sf::Vector2f(WINDOW_WIDTH / 2, 500), IP);
    _portInput = std::make_shared<TextInput>("Port :", sf::Vector2f(WINDOW_WIDTH / 2, 700), PORT);
    _backButton = Button("Back", sf::Vector2f(_ipInput->getGlobalBounds().left, 900), 75, CENTER);
    _connectButton = Button("Connect", sf::Vector2f(_ipInput->getGlobalBounds().left + _ipInput->getGlobalBounds().width, 900), 75, CENTER);
    _drunkModeButton = Button("Drunk mode", sf::Vector2f(WINDOW_WIDTH - 20, WINDOW_HEIGHT - 20), 30, BOTTOMRIGHT);
    _drunkModeButton.setActive(INACTIVE);
    _subMenu = RECEPTION;
    if (!_music.openFromFile("assets/musics/music_menu.wav") || !_drunkMusic.openFromFile("assets/musics/music_menu_drunk.wav"))
        std::cerr << "Error: cannot load music" << std::endl;
    _music.setLoop(true);
    _drunkMusic.setLoop(true);
    _drunkMusic.setVolume(20);
    _music.play();
    _drunkMusic.play();
    _drunkMusic.pause();
}

void Menu::update(std::shared_ptr<sf::RenderWindow> window)
{
    float time = _clock.getElapsedTime().asMilliseconds();

    if (_lastUpdate + 10 < time) {
        _map.update(time);
        _title.update(time);
        if (_subMenu == RECEPTION) {
            _playButton.update(sf::Mouse::getPosition(), time);
            _quitButton.update(sf::Mouse::getPosition(), time);
            _drunkModeButton.update(sf::Mouse::getPosition(), time);
        } else if (_subMenu == CONNECT) {
            _ipInput->update(sf::Mouse::getPosition(), time);
            _portInput->update(sf::Mouse::getPosition(), time);
            _backButton.update(sf::Mouse::getPosition(), time);
            _connectButton.update(sf::Mouse::getPosition(), time);
        }
        _cursor.update(window);
        _lastUpdate = time;
    }
}

void Menu::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->clear(sf::Color::White);
    window->setView(_backgroundView);
    _map.display(window);
    window->setView(_menuView);
    _title.display(window);
    if (_subMenu == RECEPTION) {
        _playButton.display(window);
        _quitButton.display(window);
        _drunkModeButton.display(window);
    } else if (_subMenu == CONNECT) {
        _ipInput->display(window);
        _portInput->display(window);
        _backButton.display(window);
        _connectButton.display(window);
        if (_displayError)
            window->draw(*_error);
    }
    _cursor.display(window);
    window->display();
}

void Menu::receptionEvent(sf::Event event, std::shared_ptr<sf::RenderWindow> window)
{
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            default:
                break;
        }
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_playButton.isHover())
            _subMenu = CONNECT;
        else if (_quitButton.isHover()) {
            window->close();
            exit(0);
        } else if (_drunkModeButton.isHover()) {
            _drunkModeButton.setActive((_drunkModeButton.isActive() == ACTIVE ? INACTIVE : ACTIVE));
            switchMusic();
        }
    }
}

void Menu::connectEvent(sf::Event event, std::shared_ptr<Client> client, std::shared_ptr<guiStatus> status, std::shared_ptr<Game> game)
{
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Escape:
                if (!_ipInput->isFocus() && !_portInput->isFocus())
                    _subMenu = RECEPTION;
                else {
                    _ipInput->setFocus(false);
                    _portInput->setFocus(false);
                }
                break;
            default:
                break;
        }
    }
    if (_ipInput->isFocus())
        _ipInput->manageEvent(event);
    else if (_portInput->isFocus())
        _portInput->manageEvent(event);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_ipInput->isHover()) {
            _ipInput->setFocus(true);
            _portInput->setFocus(false);
        } else if (_portInput->isHover()) {
            _portInput->setFocus(true);
            _ipInput->setFocus(false);
        } else if (_backButton.isHover()) {
            _subMenu = RECEPTION;
        } else if (_connectButton.isHover()) {
            std::string ip;
            uint16_t port;

            try {
                ip = _ipInput->getInput();
                port = std::stoi(_portInput->getInput());
                if (client->setHostAndPort(ip, port) < 0) {
                    throw std::invalid_argument("Error Socket");
                }
            } catch (std::invalid_argument const&) {
                _displayError = true;
                client->closeServer();
                return;
            }
            if (client->connectServer(game) < 0) {
                _displayError = true;
                client->closeServer();
                return;
            }
            _music.~Music();
            _drunkMusic.~Music();
            *status = INGAME;
            if (_drunkModeButton.isActive() == ACTIVE)
                game->setDrunkMode();
        } else {
            _ipInput->setFocus(false);
            _portInput->setFocus(false);
        }
    }
}

void Menu::manageEvents(sf::Event event, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<guiStatus> status, std::shared_ptr<Client> client, std::shared_ptr<Game> game)
{
    if (_subMenu == RECEPTION)
        receptionEvent(event, window);
    else if (_subMenu == CONNECT)
        connectEvent(event, client, status, game);
}

void Menu::switchMusic()
{
    if (_drunkModeButton.isActive() == ACTIVE && _music.getStatus() == sf::SoundSource::Playing) {
        sf::Time time = _music.getPlayingOffset();
        _music.pause();
        _drunkMusic.setPlayingOffset(time + sf::seconds(2));
        _drunkMusic.play();
    } else  if (_drunkModeButton.isActive() == INACTIVE && _drunkMusic.getStatus() == sf::SoundSource::Playing) {
        sf::Time time = _drunkMusic.getPlayingOffset();
        _drunkMusic.pause();
        _music.setPlayingOffset(time - sf::seconds(2));
        _music.play();
    }
}
