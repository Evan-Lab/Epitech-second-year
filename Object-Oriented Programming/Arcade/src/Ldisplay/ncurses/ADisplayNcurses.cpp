/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ADisplayNcurses.cpp
*/

#include "ADisplayNcurses.hpp"

arcade::ADisplayNcurses::ADisplayNcurses()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

arcade::ADisplayNcurses::~ADisplayNcurses()
{
    endwin();
}

void arcade::ADisplayNcurses::displayBlock(BlockType blockType, Position pos)
{
    int x = (pos.x * _blockSize) + (_blockSize / 2);
    int y = (pos.y * _blockSize) + (_blockSize / 2);

    switch(blockType) {
        case BlockType::BrickWall:
            mvprintw(y, x, "#");
            break;
        case BlockType::Grass:
            mvprintw(y, x, " ");
            break;
        case BlockType::Fruit:
            mvprintw(y, x, "O");
            break;
        case BlockType::Coin:
            mvprintw(y, x, "*");
            break;
        case BlockType::Character:
            mvprintw(y, x, "^");
            break;
    }
}

void arcade::ADisplayNcurses::displayText(const std::string &text, Position pos)
{
    int x = pos.x;
    int y = pos.y;
    mvprintw(y, x, "%s", text.c_str());
}

void arcade::ADisplayNcurses::clear()
{
    ::clear();
}

void arcade::ADisplayNcurses::refresh()
{
    ::refresh();
}

void arcade::ADisplayNcurses::playSound(Sound sound)
{
    switch (sound) {
        case Sound::Coin:
            beep();
            break;
        case Sound::Hurt:
            flash();
            break;
        case Sound::GameOver:
            beep();
            flash();
            break;
        case Sound::Start:
            beep();
            break;
        case Sound::Super:
            flash();
            break;
    }
}

std::list<arcade::Event> arcade::ADisplayNcurses::pollEvent()
{
    std::list<arcade::Event> events;
    arcade::Event event;
    int key = getch();

    switch (key) {
        case KEY_UP:
            event.type = arcade::EventType::Up;
            events.push_back(event);
            break;
        case KEY_DOWN:
            event.type = arcade::EventType::Down;
            events.push_back(event);
            break;
        case KEY_LEFT:
            event.type = arcade::EventType::Left;
            events.push_back(event);
            break;
        case KEY_RIGHT:
            event.type = arcade::EventType::Right;
            events.push_back(event);
            break;
        case ' ':
            event.type = arcade::EventType::Action;
            events.push_back(event);
            break;
        case 27: // ASCII code for escape key
            event.type = arcade::EventType::Pause;
            events.push_back(event);
            break;
        case KEY_BACKSPACE:
            event.type = arcade::EventType::Quit;
            events.push_back(event);
            break;
        case '+':
            event.type = arcade::EventType::SwitchToNextGame;
            events.push_back(event);
            break;
        case '-':
            event.type = arcade::EventType::SwitchToPreviousGame;
            events.push_back(event);
            break;
        case '\n': // ASCII code for enter key
            event.type = arcade::EventType::ReturnToSelectionMenu;
            events.push_back(event);
            break;
        case 'p':
            event.type = arcade::EventType::NextLibrary;
            events.push_back(event);
            break;
        case 'o':
            event.type = arcade::EventType::PreviousLibrary;
            events.push_back(event);
            break;
        case 'r':
            event.type = arcade::EventType::RestartGame;
            events.push_back(event);
            break;
    }
    return events;
}

void arcade::ADisplayNcurses::setWindowSize(Position size)
{
    _windowSize = size;
}

arcade::Position arcade::ADisplayNcurses::getWindowSize()
{
    return _windowSize;
}

void arcade::ADisplayNcurses::setWindowTitle(const std::string &title)
{
    _windowTitle = title;
}

extern "C" {
    arcade::IDisplayModule *createDisplayModule()
    {
        return new arcade::ADisplayNcurses();
    }
}