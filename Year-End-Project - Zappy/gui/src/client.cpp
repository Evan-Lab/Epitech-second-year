/*
** EPITECH PROJECT, 2023
** gui
** File description:
** server
*/

#include <vector>
#include <iostream>
#include "client.hpp"
#include <sys/socket.h>
#include <cstring>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include "tools.hpp"

int Client::createSocket()
{
    int blockstdin = socket(AF_INET, SOCK_STREAM, 0);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << ("ERROR opening socket") << std::endl;
        return -1;
    }
    close(blockstdin);
    return sockfd;
}

int Client::closeServer()
{
    return close(_socketfd);
}

std::string Client::readMessage()
{
    std::string str(BUFFER_SIZE, 0);
    int byte = 0;

    byte = read(_socketfd, &str[0], BUFFER_SIZE - 1);
    if (byte < 0) {
        perror("ERROR read message from serveur");
        return "";
    }
    str[byte] = '\0';
    str = str.c_str();
    return str;
}

int Client::sendMessage(std::string str)
{
    int byte;

    byte = write(_socketfd, str.c_str(), str.size());
    return byte;
}

int Client::generateWorld(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int x = 0;
    int y = 0;

    try {
        x = std::stoi(list[1]);
        y = std::stoi(list[2]);
    } catch (std::invalid_argument const&) {
        return -1;
    }
    _game->createMap(_game->getWindow(), x, y);
    return 0;
}

void Client::changeTuile(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int x, y, food, line, dera, sibu, men, phi, thy = 0;

    try {
        x = std::stoi(list[1]);
        y = std::stoi(list[2]);
        food = std::stoi(list[3]);
        line = std::stoi(list[4]);
        dera = std::stoi(list[5]);
        sibu = std::stoi(list[6]);
        men = std::stoi(list[7]);
        phi = std::stoi(list[8]);
        thy = std::stoi(list[9]);
    } catch (std::invalid_argument const&) {
        return;
    }
    _game->getMap()->getTile(x, y)->setInventory(MILK, food);
    _game->getMap()->getTile(x, y)->setInventory(LINEMATE, line);
    _game->getMap()->getTile(x, y)->setInventory(DERAUMERE, dera);
    _game->getMap()->getTile(x, y)->setInventory(SIBUR, sibu);
    _game->getMap()->getTile(x, y)->setInventory(MENDIANE, men);
    _game->getMap()->getTile(x, y)->setInventory(PHIRAS, phi);
    _game->getMap()->getTile(x, y)->setInventory(THYSTAME, thy);
}

void Client::addTeam(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    _game->addTeam(list[1]);
    return;
}

void Client::addPlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id, x, y, o, l = 0;

    try {
        id = std::stoi(list[1]);
        x = std::stoi(list[2]);
        y = std::stoi(list[3]);
        o = std::stoi(list[4]);
        l = std::stoi(list[5]);
        _game->addPlayer(list[6], std::make_pair(x, y), id, (orientation) o, l);
    } catch (std::invalid_argument const&) {
        return;
    }

    return;
}

void Client::movePlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id, x, y, o = 0;

    try {
        id = std::stoi(list[1]);
        x = std::stoi(list[2]);
        y = std::stoi(list[3]);
        o = std::stoi(list[4]);
        _game->movePlayer(id, std::make_pair(x, y), (orientation) o);
    } catch (std::invalid_argument const&) {
        return;
    }
}

void Client::changeInventoryPlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id = 0;
    std::vector<std::pair<objectType, int>> inventory;

    try {
        id = std::stoi(list[1]);
        inventory.push_back(std::make_pair((objectType) 0, std::stoi(list[5])));
        inventory.push_back(std::make_pair((objectType) 1, std::stoi(list[6])));
        inventory.push_back(std::make_pair((objectType) 2, std::stoi(list[7])));
        inventory.push_back(std::make_pair((objectType) 3, std::stoi(list[8])));
        inventory.push_back(std::make_pair((objectType) 4, std::stoi(list[9])));
        inventory.push_back(std::make_pair((objectType) 5, std::stoi(list[10])));
        _game->setPlayerInventory(id, inventory);
        _game->setPlayerFood(id, std::stoi(list[4]));
    } catch (std::invalid_argument const&) {
        return;
    }
}

void Client::changeLevelPlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id, level = 0;

    try {
        id = std::stoi(list[1]);
        level = std::stoi(list[2]);
        _game->setPlayerLevel(id, level);
    } catch (std::invalid_argument const&) {
        return;
    }
}

void Client::updatePlayer(void)
{
    for (auto player: _game->getListPlayer()) {
        updatePlayer(player->getId());
    }
}

void Client::updatePlayer(int id)
{
    std::string str;

    str = "ppo " + std::to_string(id) + "\n";
    sendMessage(str);
    str = "plv " + std::to_string(id) + "\n";
    sendMessage(str);
    str = "pin " + std::to_string(id) + "\n";
    sendMessage(str);
}

void Client::updateMap(void)
{
    sendMessage("mct\n");
}

void Client::expulsePlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id = 0;

    try {
        id = std::stoi(list[1]);
        updatePlayer(id);
        //Play Animation expulse
    } catch (std::invalid_argument const&) {
        return;
    }
}

void Client::broadcast(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id = 0;

    try {
        id = std::stoi(list[1]);
        updatePlayer(id);
        //Speak Bubble
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::startIncatation(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int x, y, l, id = 0;

    try {
        x = std::stoi(list[1]);
        y = std::stoi(list[2]);
        l = std::stoi(list[3]);
        id = std::stoi(list[4]);
        x = x;
        y =y;
        l = l;
        updatePlayer(id);
        //Start inca
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::endIncatation(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int x, y = 0;

    try {
        x = std::stoi(list[1]);
        y = std::stoi(list[2]);
        x = x;
        y = y;
        //Check result R is list[3] from Incant
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::spawningEgg(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id = 0;

    try {
        id = std::stoi(list[1]);
        updatePlayer(id);
        //Anim A egg spawning
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::dropRessource(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id, i = 0;

    try {
        id = std::stoi(list[1]);
        i = std::stoi(list[1]);
        i = i;
        updatePlayer(id);
        //Drop i ressource
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::collectRessource(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id, i = 0;

    try {
        id = std::stoi(list[1]);
        i = std::stoi(list[1]);
        i = i;
        updatePlayer(id);
        //Collect i ressource
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::killPlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int id = 0;

    try {
        id = std::stoi(list[1]);
        _game->deletePlayer(id);
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::spawnEgg(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int eggId, id, x ,y = 0;

    try {
        eggId = std::stoi(list[1]);
        id = std::stoi(list[2]);
        x = std::stoi(list[3]);
        y = std::stoi(list[4]);
        _game->addEgg(eggId, id, std::make_pair(x, y));
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::eggBecomePlayer(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int eggId = 0;

    try {
        eggId = std::stoi(list[1]);
        _game->eggToPlayer(eggId);
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::killEgg(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');
    int eggId = 0;

    try {
        eggId = std::stoi(list[1]);
        _game->deleteEgg(eggId);
    } catch (std::invalid_argument const &) {
        return;
    }
}


void Client::changeTime(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');

    try {
        _time = std::stoi(list[1]);
    } catch (std::invalid_argument const &) {
        return;
    }
}

void Client::endGame(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');

    try {
        std::stoi(list[1]); //this team win the game
    } catch (std::invalid_argument const &) {
        return;
    }
    //END THE FCK GAME
}

void Client::serverMessage(std::string str)
{
    std::vector<std::string> list = strToWordArray(str, ' ');

    std::cerr << "Serveur : " << list[1] << std::endl;
    //Maybe Add a message in the GUI
}

void Client::parseMessageServer(std::string str)
{
    size_t pos = 0;
    std::string token;
    std::string subtoken;

    if (_game == NULL) {
        std::cerr << "bbp" << std::endl;
    }
    while ((pos = str.find('\n')) != std::string::npos) {
        token = str.substr(0, pos);
        subtoken = token.substr(0, token.find(' '));
        if (subtoken == "msz") {
            generateWorld(token);
        } else if (subtoken == "bct") {
            changeTuile(token);
        } else if (subtoken == "tna") {
            addTeam(token);
        } else if (subtoken == "pnw") {
            addPlayer(token);
        } else if (subtoken == "ppo") {
            movePlayer(token);
        } else if (subtoken == "plv") {
            changeLevelPlayer(token);
        } else if (subtoken == "pin") {
            changeInventoryPlayer(token);
        } else if (subtoken == "pex") {
            expulsePlayer(token);
        } else if (subtoken == "pbc") {
            broadcast(token);
        } else if (subtoken == "pic") {
            startIncatation(token);
        } else if (subtoken == "pie") {
            endIncatation(token);
        } else if (subtoken == "pfk") {
            spawningEgg(token);
        } else if (subtoken == "pdr") {
            dropRessource(token);
        } else if (subtoken == "pgt") {
            collectRessource(token);
        } else if (subtoken == "pdi") {
            killPlayer(token);
        } else if (subtoken == "enw") {
            spawnEgg(token);
        } else if (subtoken == "ebo") {
            eggBecomePlayer(token);
        } else if (subtoken == "edi") {
            killEgg(token);
        } else if (subtoken == "sgt" || subtoken == "sst") {
            changeTime(token);
        } else if (subtoken == "seg") {
            endGame(token);
        } else if (subtoken == "seg") {
            serverMessage(token);
        }
        str.erase(0, pos + 1);
    }
}

int Client::connectServer(std::shared_ptr<Game> game)
{
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int result = -1;

    result = inet_pton(AF_INET, _hostname.c_str(), &(serv_addr.sin_addr));
    server = gethostbyname(_hostname.c_str());
    if (result == 0) {
        std::cerr << "ERROR host not found" << std::endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(reinterpret_cast<unsigned long*>(server->h_addr));
    serv_addr.sin_port = htons(_port);
    try {
        if (connect(_socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            std::cerr << "ERROR connect" << std::endl;
            return -1;
        }
    } catch (std::logic_error const&) {
        return -1;
    }
    if (readMessage() != CONNETION_OK) {
        std::cerr << "Server don't send the good message" << std::endl;
        return -1;
    }
    std::cerr << "Server and client gui connected" << std::endl;
    _game = game;
    sendMessage(TEAM_GUI);
    parseMessageServer(readMessage());
    sendMessage("sst 10\n");
    return 0;
}

void Client::run(void)
{
    std::string message;
    struct timeval timeout;
    fd_set tmp_fds = _read_fds;
    int ready = -1;

    timeout.tv_sec = 0;
    timeout.tv_usec = _time;
    ready = select(_socketfd + 1, &tmp_fds, NULL, NULL, &timeout);
    if (ready > 0) {
        if (FD_ISSET(_socketfd, &tmp_fds)) {
            message = readMessage();
            parseMessageServer(message);
        }
    } else  if (ready == 0) {
        updateMap();
        updatePlayer();
        //time out
    } else {
        perror("select"); // Erreur lors de l'appel à select
        exit(1);
    }
    FD_ZERO(&_read_fds);
    FD_SET(_socketfd, &_read_fds);
}


int Client::setHostAndPort(std::string hostname, uint16_t port)
{
    FD_ZERO(&_read_fds);
    _hostname = hostname;
    _port = port;
    _time = 10000;
    _socketfd = createSocket();
    FD_SET(_socketfd, &_read_fds);
    return _socketfd;
}

Client::~Client()
{
    close(_socketfd);
}
