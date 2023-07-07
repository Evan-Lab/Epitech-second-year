/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** IModule
*/

#pragma once

class IModule {
    public:
        IModule() = default;
        virtual ~IModule() = default;

        virtual void displayMod() = 0;
        virtual void setPosX() = 0;
        virtual void setPosY() = 0;
        virtual void setHeight() = 0;
        virtual void setWidth() = 0;
};