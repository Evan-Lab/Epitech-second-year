/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** game
*/

#include "game.hpp"

Game::Game(std::shared_ptr<sf::RenderWindow> window)
{
    _lastUpdate = 0;
    _window = window;
    _map = NULL;
    _mapView = sf::View();
    _mapView.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    _mapView.setCenter(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    _hudView = sf::View();
    _hudView.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    _hudView.setCenter(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    _cursor = std::make_shared<Cursor>();
    initItemsImages();
    _hud = Hud(window);
    if (!_music.openFromFile("assets/musics/music_game.wav"))
        std::cerr << "Error: cannot load music" << std::endl;
    _music.setLoop(true);
    initNames();
}

void Game::setDrunkMode()
{;
    if (!_music.openFromFile("assets/musics/music_game_drunk.wav"))
        std::cerr << "Error: cannot load music" << std::endl;
    _music.setLoop(true);
    _itemsImages[6].first = std::make_shared<Image>("assets/images/beer.png", CENTER);
}

std::shared_ptr<Map> Game::getMap()
{
    return _map;
}

void Game::createMap(std::shared_ptr<sf::RenderWindow> window, int x, int y)
{
    _map = std::make_shared<Map>(sf::Vector2i(MAP_POS_X, MAP_POS_Y), x, y);;
}

void Game::update(std::shared_ptr<sf::RenderWindow> window)
{
    float time = _clock.getElapsedTime().asMilliseconds();

    if (_lastUpdate + 10 < time) {
        if (_music.getStatus() != sf::Music::Playing)
            _music.play();
        _map->update(time, window, _cursor, _mapView);
        for (auto player : _playerList)
            player->moveTo(_map->getTile(player->getCoo().first, player->getCoo().second)->getPos(), player->getCoo());
        _cursor->update(window);
        _hud.update(_playerList, _eggList, window);
        _lastUpdate = time;
    }
}

std::shared_ptr<sf::RenderWindow> Game::getWindow(void)
{
    return _window;
}

void Game::display(std::shared_ptr<sf::RenderWindow> window) const
{
    window->clear(sf::Color::White);
    window->setView(_mapView);
    _map->display(window, _itemsImages);
    for (auto player : _playerList)
        player->display(window);
    for (auto egg : _eggList)
        egg->displayOnTile(_map->getTile(egg->getCoo().first, egg->getCoo().second)->getPos(), window);
    window->setView(_hudView);
    _hud.display(window, _itemsImages);
    _cursor->display(window);
    window->display();
}

void Game::zoom(float factor)
{
    _mapView.zoom(factor);
}

void Game::move(sf::Vector2f pos)
{
    _mapView.move(pos);
}

void Game::manageEvents(sf::Event event, std::shared_ptr<sf::RenderWindow> window)
{
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                move(sf::Vector2f(0, -10));
                break;
            case sf::Keyboard::Down:
                move(sf::Vector2f(0, 10));
                break;
            case sf::Keyboard::Left:
                move(sf::Vector2f(-10, 0));
                break;
            case sf::Keyboard::Right:
                move(sf::Vector2f(10, 0));
                break;
            case sf::Keyboard::Add:
                zoom(0.9);
                break;
            case sf::Keyboard::Subtract:
                zoom(1.1);
                break;
            case sf::Keyboard::Escape:
                _music.~Music();
                window->close();
                exit(0);
                break;
            default:
                break;
        }
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        _cursor->setTarget(_cursor->getHover());
        _hud.setTile(_cursor->getHover());
    }
}

std::vector<std::shared_ptr<Player>> Game::getListPlayer(void)
{
    return _playerList;
}

void Game::movePlayer(std::shared_ptr<Player> player, sf::Vector2f pos, std::pair<int, int> coo)
{
    player->moveTo(pos, coo);
}

void Game::initItemsImages()
{
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_1.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_2.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_3.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_4.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_5.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/stone_6.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/milk.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
    _itemsImages.push_back(std::make_pair(std::make_shared<Image>("assets/images/egg.png", CENTER), std::make_shared<Text>("0", sf::Vector2f(0, 0), 10, CENTER)));
}

void Game::addPlayer(std::string team, std::pair<int, int> coo, int id, orientation orientation, int level)
{
    bool teamExist = false;
    sf::Color teamColor;

    for (auto oneTeam : _teamList) {
        if (oneTeam.first == team) {
            teamExist = true;
            teamColor = oneTeam.second;
        }
    }
    if (!teamExist) return;
    addPlayer(std::make_pair(team, teamColor), coo, id, orientation, level);
}

void Game::addPlayer(std::pair<std::string, sf::Color> team, std::pair<int, int> coo, int id, orientation orientation, int level)
{
    std::string firstName = _nameList[randInt(0, _nameList.size() - 1)].first;
    std::string lastName = _nameList[randInt(0, _nameList.size() - 1)].second;

    _playerList.push_back(std::make_shared<Player>(team, coo, id, firstName + ' ' + lastName));
    _playerList[_playerList.size() - 1]->setOrientation(orientation);
    _playerList[_playerList.size() - 1]->setLevel(level);
    _playerList[_playerList.size() - 1]->moveTo(_map->getTile(coo.first, coo.second)->getPos(), coo);
}

void Game::movePlayer(int id, std::pair<int, int> coo, orientation orientation)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            player->setOrientation(orientation);
            player->moveTo(_map->getTile(coo.first, coo.second)->getPos(), coo);
            break;
        }
    }
}

void Game::setPlayerInventory(int id, std::vector<std::pair<objectType, int>> inventory)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            player->setInventory(inventory);
            break;
        }
    }
}

void Game::setPlayerFood(int id, int food)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            player->setFood(food);
            break;
        }
    }
}

void Game::setPlayerLevel(int id, int level)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            player->setLevel(level);
            break;
        }
    }
}

void Game::deletePlayer(int id)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            _playerList.erase(std::remove(_playerList.begin(), _playerList.end(), player), _playerList.end());
            break;
        }
    }
}

void Game::addEgg(int eggId, int id, std::pair<int, int> coo)
{
    for (auto player : _playerList) {
        if (player->getId() == id) {
            _eggList.push_back(std::make_shared<Egg>(eggId, player->getTeam(), coo));
            break;
        }
    }
}

void Game::deleteEgg(int eggId)
{
    for (auto egg : _eggList) {
        if (egg->getId() == eggId) {
            _eggList.erase(std::remove(_eggList.begin(), _eggList.end(), egg), _eggList.end());
            break;
        }
    }
}

void Game::eggToPlayer(int eggId)
{
    for (auto egg : _eggList)
        addPlayer(egg->getTeam(), egg->getCoo(), egg->getId(), (orientation) 1 , 1);
    deleteEgg(eggId);
}

sf::Color Game::createColor()
{
    int r = randInt(0, 255);
    int g = randInt(0, 255);
    int b = 0;

    if (r > 155 && g > 155)
        b = randInt(0, 155);
    else if (r > 155 || g > 155)
        b = randInt(0, 255);
    else
        b = randInt(155, 255);
    return sf::Color(r, g, b);
}

void Game::addTeam(std::string name)
{
    sf::Color color;
    bool colorOk = false;

    for (auto team : _teamList) {
        if (team.first == name)
            return;
    }
    while (!colorOk) {
        color = sf::Color(createColor());
        colorOk = true;
        for (auto team : _teamList) {
            if (team.second == color)
                colorOk = false;
        }
    }
    _teamList.push_back(std::make_pair(name, color));
}

void Game::initNames() //open assets/catnames.txt
{
    std::ifstream file("assets/catnames.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::vector<std::string> tmp = strToWordArray(line, ' ');
            _nameList.push_back(std::make_pair(tmp[0], tmp[1]));
        }
        file.close();
    }
}
