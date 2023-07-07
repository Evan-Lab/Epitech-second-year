/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** gui
*/

#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include <iostream>
#include <fstream>
#include "map.hpp"
#include "cursor.hpp"
#include "text.hpp"
#include "player.hpp"
#include "hud.hpp"
#include "tools.hpp"

class Game {
    public:
        Game() = default;
        Game(std::shared_ptr<sf::RenderWindow> window);
        ~Game() = default;
        void update(std::shared_ptr<sf::RenderWindow> window);
        void display(std::shared_ptr<sf::RenderWindow> window) const;
        void zoom(float factor);
        void createMap(std::shared_ptr<sf::RenderWindow> window, int x, int y);
        void move(sf::Vector2f pos);
        void manageEvents(sf::Event event, std::shared_ptr<sf::RenderWindow> window);
        void movePlayer(std::shared_ptr<Player> player, sf::Vector2f pos, std::pair<int, int> coo);
        std::shared_ptr<Map> getMap();
        std::shared_ptr<sf::RenderWindow> getWindow(void);
        void addPlayer(std::pair<std::string, sf::Color> team, std::pair<int, int> coo, int id, orientation orientation, int level);
        void addPlayer(std::string team, std::pair<int, int> coo, int id, orientation orientation, int level);
        void addTeam(std::string team);
        void movePlayer(int id, std::pair<int, int> coo, orientation orientation);
        void setPlayerInventory(int id, std::vector<std::pair<objectType, int>> inventory);
        void setPlayerFood(int id, int food);
        void setPlayerLevel(int id, int level);
        void deletePlayer(int id);
        void addEgg(int eggId, int id, std::pair<int, int> coo);
        void deleteEgg(int eggId);
        void eggToPlayer(int eggId);
        std::vector<std::shared_ptr<Player>> getListPlayer(void);
        void setDrunkMode();
    private:
        sf::Color createColor();
        std::shared_ptr<sf::RenderWindow> _window;
        void initItemsImages();
        void initNames();
        std::vector<std::shared_ptr<Player>> _playerList;
        std::vector<std::shared_ptr<Egg>> _eggList;
        std::vector<std::pair<std::string, sf::Color>> _teamList;
        std::vector<std::pair<std::string, std::string>> _nameList;
        sf::Clock _clock;
        float _lastUpdate;
        std::shared_ptr<Map> _map;
        sf::View _mapView;
        sf::View _hudView;
        std::shared_ptr<Cursor> _cursor;
        Hud _hud;
        std::vector<std::pair<std::shared_ptr<Image>, std::shared_ptr<Text>>> _itemsImages;
        sf::Music _music;
};
