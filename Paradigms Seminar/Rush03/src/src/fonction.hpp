/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** fonction.hpp
*/

#pragma once

#include <chrono>
#include <thread>
#include <stdio.h>
#include <dirent.h>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../classes/data/DataGraph.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

std::string getInfoFromList(std::string str, int index);
std::string getInfosVirt(int pid, int index, int index2);
std::string getInfosFromStatus(int pid, int index, int index2);
std::string getInfosFromProc(int pid, std::string filename, int index);
std::string getInfosFromProc(int pid, std::string filename, int index);
void drawHeader(WINDOW *win);
void drawHeaderProcesses(WINDOW *win);
void drawProcesses(WINDOW *win, int pid, int lineDisplay);
int draw(WINDOW *header, WINDOW *process, int pid, int pidUser1, int pidUser2, int i);
int checkEnd(void);
int getInfosFromProc(WINDOW *header, WINDOW *process, int pid1, int pid2);
int run_ncurses(int pid1, int pid2);
void rectangles(sf::RenderWindow &window, int thiknesss, int x, int y, int width, int height, sf::Color OutLine, sf::Color Fond);
void putText(sf::RenderWindow &window, sf::Font &font, std::string texts, int size, int x_pos, int y_pos, std::string unit, double value);
void drawBarChart(const std::vector<double> &data, sf::RenderWindow &window, int xPos, int yPos, int height, int width, int valueMax);
void module(sf::RenderWindow &window, sf::Font &font, int thiknesss, int x, int y, int width, int height, sf::Color OutLine, sf::Color Fond, std::vector<double> data_test, int valueMax, std::string name, std::string Unit);
int tab_is_pressed(int x, int y, int tab);
void display_sfml();