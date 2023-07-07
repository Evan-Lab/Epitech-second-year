/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** closeLib.cpp
*/
#include "core.hpp"

namespace arcade {

    void deleteAllModules(IDisplayModule *displayModule, IGameModule *gameModule) {
        delete(displayModule);
        delete(gameModule);
    }

    static int closeLib(void *lib) {
        if (dlclose(lib) != 0) throw cannotCloseLibrary();
        return 0;
    }

    void closeAllLibs(Core *core) {
        for (auto &displayLib : core->_displayLibs) {
            closeLib(displayLib.second.second);
        }
        for (auto &gameLib : core->_gameLibs) {
            closeLib(gameLib.second.second);
        }
        delete(core);
    }
} // namespace arcade