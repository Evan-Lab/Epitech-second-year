/*
** EPITECH PROJECT, 2023
** day07-pm
** File description:
** Skat
*/

#pragma once

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        const int &stimPaks();
        const std::string &name() const;
        void shareStimPaks(int number, Skat &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        std::string _name;
        int _stimPaks;
};
