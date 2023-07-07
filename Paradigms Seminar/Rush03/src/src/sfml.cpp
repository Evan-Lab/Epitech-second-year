/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** sfml.cpp
*/

#include "fonction.hpp"

int thickness = 5;
int pos_x = 100;
int pos_y = 100;
int width = 200;
int height = 200;

void rectangles(sf::RenderWindow &window, int thiknesss, int x, int y, int width, int height, sf::Color OutLine, sf::Color Fond)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(OutLine);
    rectangle.setOutlineThickness(thiknesss);
    rectangle.setFillColor(Fond);
    window.draw(rectangle);
}

void putText(sf::RenderWindow &window, sf::Font &font, std::string texts, int size, int x_pos, int y_pos, std::string unit, double value)
{
    sf::Text text(texts + "\n" + std::to_string(value) + "  " +unit, font, size);
    text.setScale(0.25, 0.25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x_pos, y_pos);
    window.draw(text);
}

void drawBarChart(const std::vector<double> &data, sf::RenderWindow &window, int xPos, int yPos, int height, int width, int valueMax)
{
  sf::RectangleShape bar;
  bar.setFillColor(sf::Color::Green);

  int barWidth = width / 20;
  int barHeightMax = valueMax * 2;

  for (double value : data) {
    int barHeight = -(value / barHeightMax * height);
    bar.setSize(sf::Vector2f(barWidth, barHeight));
    bar.setPosition(xPos, yPos);
    window.draw(bar);
    xPos += barWidth + (barWidth/5);
  }
}

void module(sf::RenderWindow &window, sf::Font &font, int thiknesss, int x, int y, int width, int height, sf::Color OutLine, sf::Color Fond, std::vector<double> data_test, int valueMax, std::string name, std::string Unit)
{
    int text_scale = height / 4;
    rectangles(window, thiknesss, x, y, width, height, OutLine, OutLine);
    rectangles(window, thiknesss, x, y, width, height - (height/4), OutLine, Fond);
    putText(window, font, name, text_scale, x , y + height - (height/4), Unit, data_test.back());
    drawBarChart(data_test, window, x, y + height - (height/4), height - (height/4), width, valueMax);
}

int tab_is_pressed(int x, int y, int tab)
{
    if (x <= 200) {
        if (y <= 200)
            return 0;
        if (y <= 400 && y >= 200)
            return 1;
        if (y <= 600 && y >= 400)
            return 2;
        if (y <= 800 && y >= 600)
            return 3;
        if (y <= 1000 && y >= 800)
            return 4;
    }
    return tab;
}

void display_sfml()
{
    int i = 0;
    int x = 0;
    int tab = 0;
    int wait = 0;
    DataGraph dataGraphs;
    std::vector<DataGraph> data = dataGraphs.init();
    for (DataGraph &dataGraph : data) {
        dataGraph.updateValues();
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chibre");
    sf::Vector2i mousePos;
    sf::Font font;
    font.loadFromFile("src/utils/Minecraft.ttf");
    sf::Color color = sf::Color::White;
    while (window.isOpen())
    {
        i = 5;
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        mousePos = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            tab = tab_is_pressed(mousePos.x, mousePos.y, tab);
        if (wait >= 1000) {
            window.clear();
            for (DataGraph &dataGraph : data) {
                dataGraph.updateValues();
                module(window, font, thickness, 10, i - x, height, width, color, sf::Color::Black, dataGraph.getValues(), dataGraph.getMaxValue(), dataGraph.getName(), dataGraph.getUnit());
                i += 200;
                wait = 0;
            }
        }
        wait++;
        module(window, font, thickness, 500, 10, 1000, 1000, color, sf::Color::Black, data[tab].getValues(), data[tab].getMaxValue(), data[tab].getName(), data[tab].getUnit());
        window.display();
    }
}