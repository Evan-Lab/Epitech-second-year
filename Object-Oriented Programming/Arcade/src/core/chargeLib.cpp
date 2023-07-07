/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** chargeLib.cpp
*/
#include "core.hpp"

namespace arcade {

    IDisplayModule *createDisplayModule(void *lib) {
        IDisplayModule *(*createDisplayModule)();
        createDisplayModule = (IDisplayModule * (*)()) dlsym(lib, "createDisplayModule");
        if (!createDisplayModule) throw cannotCreateModule();
        return createDisplayModule();
    }

    IGameModule *createGameModule(void *lib) {
        IGameModule *(*createGameModule)();
        createGameModule = (IGameModule * (*)()) dlsym(lib, "createGameModule");
        if (!createGameModule) throw cannotCreateModule();
        return createGameModule();
    }

    static void deleteDisplayModule(IDisplayModule *displayModule) {
        delete(displayModule);
    }

    std::string nextIndex(std::vector<std::string> lib, std::string curent) {
        for (int i = 0; i < lib.size(); i++) {
            if (lib[i] == curent) {
                if (i + 1 == lib.size()) return lib[0];
                return lib[i + 1];
            }
        }
        return lib[0];
    }

    std::string previousIndex(std::vector<std::string> lib, std::string curent) {
        for (int i = 0; i < lib.size(); i++) {
            if (lib[i] == curent) {
                if (i - 1 < 0) return lib[lib.size() - 1];
                return lib[i - 1];
            }
        }
        return lib[0];
    }

} // namespace arcade