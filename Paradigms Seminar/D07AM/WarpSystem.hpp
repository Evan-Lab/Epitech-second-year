/*
** EPITECH PROJECT, 2023
** day07-am
** File description:
** WarpSystem
*/

#pragma once

namespace WarpSystem
{
    class QuantumReactor
    {
    public:
        QuantumReactor();
        ~QuantumReactor();
        bool _stability;
        bool isStable();
        void setStability(bool stability);
    };
    class Core
    {
    public:
        Core(QuantumReactor *coreReactor);
        ~Core();
        QuantumReactor *_coreReactor;
        QuantumReactor *checkReactor();

    };
}

