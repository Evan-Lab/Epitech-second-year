/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** hud
*/

#include "hud.hpp"

Hud::Hud(std::shared_ptr<sf::RenderWindow> window)
{
    _tile = nullptr;
    _tileInfoShape = Rectangle(sf::Vector2f(400, 150));
    _tileInfoShape.setFillColor(sf::Color(0, 0, 0, 100));
    _tileInfoShape.setPosition(sf::Vector2f(0, 0));
    _tileInfoCoo = std::make_shared<Text>("Error", sf::Vector2f(10, 10), 50);
    _player = nullptr;
    _playerInfoShape = Rectangle(sf::Vector2f(400, 150), TOPRIGHT);
    _playerInfoShape.setFillColor(sf::Color(0, 0, 0, 100));
    _playerInfoShape.setPosition(sf::Vector2f(WINDOW_WIDTH, 0));
    _playerInfo = std::make_shared<Text>("Error", sf::Vector2f(WINDOW_WIDTH - 400 + 10, 5), 20);
}

void Hud::update(std::vector<std::shared_ptr<Player>> playerList, std::vector<std::shared_ptr<Egg>> eggList, std::shared_ptr<sf::RenderWindow> window)
{
    if (!_tile) return;
    updateTileInfo();
    _player = nullptr;
    for (auto player : playerList) {
        if (player->getCoo() == _tile->getCoo()) {
            _player = player;
            break;
        }
    }
    for (auto egg : eggList) {
        if (egg->getCoo() == _tile->getCoo()) {
            _egg = egg;
            break;
        }
    }
    if (!_player) return;
    updatePlayerInfo(window);
}

void Hud::updateTileInfo()
{
    _tileInfoInventory = _tile->getInventory();
    _tileInfoInventory.setPos(sf::Vector2f(40, 110));
    _tileInfoCoo->setString(std::to_string(_tile->getCoo().first) + ", " + std::to_string(_tile->getCoo().second));
}

void Hud::updatePlayerInfo(std::shared_ptr<sf::RenderWindow>  window)
{
    _playerInfo->setString("Name : " + _player->getName() + "\nId : " + std::to_string(_player->getId()) + "\nTeam : " + _player->getTeam().first + "\nLevel : " + std::to_string(_player->getLevel()) + "\nFood : " + std::to_string(_player->getFood()) + "\nInventory : ");
    _playerInfoInventory = _player->getInventory();
    _playerInfoInventory.setPos(sf::Vector2f(WINDOW_WIDTH - 400 + 150, 125));
}

void Hud::display(std::shared_ptr<sf::RenderWindow> window, std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> imagesList) const
{
    if (!_tile) return;
    window->draw(_tileInfoShape);
    window->draw(*_tileInfoCoo);
    _tileInfoInventory.displayForHud(window, imagesList, (_egg) ? _egg->getImage() : nullptr);
    if (!_player) return;
    window->draw(_playerInfoShape);
    window->draw(*_playerInfo);
    _playerInfoInventory.displayForHud(window, imagesList, nullptr);
}

void Hud::setTile(std::shared_ptr<Tile> tile)
{
    _tile = tile;
}
