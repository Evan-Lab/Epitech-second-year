/*
** EPITECH PROJECT, 2023
** day10
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <ostream>

FruitBox::FruitBox(unsigned int size): size(size), nbFruits(0), MyFruit(nullptr)
{
}

FruitBox::~FruitBox()
{
    for (int a = 0; a < nbFruits; a++)
        delete MyFruit[a];
}

unsigned FruitBox::getSize() const
{
    return size;
}

unsigned int FruitBox::nbFruit() const
{
    return nbFruits;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (nbFruits == size)
        return false;
    if (fruit == nullptr)
        return false;
    if (MyFruit == nullptr) {
        MyFruit = new IFruit * [size];
        MyFruit[0] = fruit;
        nbFruits++;
        return true;
    }
    for (int a = 0; a < nbFruits; a++) {
        if (MyFruit[a] == fruit)
            return false;
    }
    MyFruit[nbFruits] = fruit;
    nbFruits++;
    return true;
}

IFruit *FruitBox::popFruit()
{
    IFruit *tmp = nullptr;

    if (nbFruits == 0)
        return nullptr;
    tmp = MyFruit[0];
    for (int a = 0; a < nbFruits; a++) {
        MyFruit[a] = MyFruit[a + 1];
    }
    nbFruits--;
    return tmp;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &box)
{
    int nb = box.nbFruit();

    os << "[";
    for (int a = 0; a < nb; a++) {
        os << "[name: \"" << box.MyFruit[a]->getName() << "\", vitamins: " << box.MyFruit[a]->getVitamins() << ", " << (box.MyFruit[a]->isPeeled() ? "peeled: true]" : "peeled: false]");
        if (a != nb - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
