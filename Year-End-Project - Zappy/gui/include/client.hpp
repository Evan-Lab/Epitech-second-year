/*
** EPITECH PROJECT, 2023
** gui
** File description:
** server
*/

#include <string>
#include <sys/select.h>
#include "game.hpp"

#pragma once

#define BUFFER_SIZE 10000
#define CONNETION_OK "WELCOME\n"
#define TEAM_GUI "GRAPHIC\n"

class Client
{
    public:
        ~Client();
        int createSocket();
        int connectServer(std::shared_ptr<Game> game);
        int closeServer();
        int setHostAndPort(std::string hostname, uint16_t port);
        void parseMessageServer(std::string str);
        std::string readMessage();
        void run(void);
        void addTeam(std::string str);
        void changeTuile(std::string str);
        void addPlayer(std::string str);
        void movePlayer(std::string str);
        void changeLevelPlayer(std::string str);
        void changeInventoryPlayer(std::string str);
        void expulsePlayer(std::string str);
        void broadcast(std::string str);
        void startIncatation(std::string str);
        void endIncatation(std::string str);
        void spawningEgg(std::string str);
        void dropRessource(std::string str);
        void collectRessource(std::string str);
        void killPlayer(std::string str);
        void spawnEgg(std::string str);
        void changeTime(std::string str);
        void eggBecomePlayer(std::string str);
        void killEgg(std::string str);
        void endGame(std::string str);
        void serverMessage(std::string str);
        void updatePlayer(int id);
        void updatePlayer(void);
        void updateMap(void);
        int sendMessage(std::string str);
        int generateWorld(std::string str);
    private:
        std::shared_ptr<Game> _game;
        int _socketfd;
        int _time;
        std::string _hostname;
        uint16_t _port;
        fd_set _read_fds;
};
