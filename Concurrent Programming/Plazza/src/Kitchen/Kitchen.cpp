/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace Plazza
{
    Kitchen::Kitchen(pid_t pid, int nb_cooks, long double time) : _pid(pid), _time(time), _ipc(".", 4)
    {
        // std::cout << "Enter in ctor kitchen" << std::endl;
        // _threads.create(nb_cooks);

        // std::cout << "Pass after create" << std::endl;

        _clock.getElapsedTime();
        for (int count = 0; count < 9; ++count)
        {
            Ingredient ingredient;
            ingredient.ingredient = static_cast<PizzaIngredient>(count);
            ingredient.number = 5;
        }
        // std::cout << "PID: " << getpid() << std::endl;
        execute();
    }

    Kitchen::~Kitchen()
    {
    }

    void Kitchen::cook(std::shared_ptr<IPizza> pizza)
    {
        Clock clock;
        double time = pizza->getTime();

        while (clock.getElapsedTime() < time)
            ;
        pizza->setStatus(StatusPizza::ready);
    }

    void Kitchen::assign_cooks()
    {
        // std::shared_ptr<IPizza> pizza = _listPizza[_listPizza.size() - 1];

        // _threads.enqueue([this, pizza]() {
        //     cook(pizza);
        //     deletePizza(pizza->getId());
        // });
    }

    void Kitchen::addPizza(std::shared_ptr<IPizza> pizza)
    {
        std::vector<std::shared_ptr<IPizza>>::iterator it;

        it = _listPizza.begin();
        it = _listPizza.insert(it, pizza);
    }

    void Kitchen::regenIngredient()
    {
        for (size_t count = 0; count < _listIngredient.size(); ++count)
            _listIngredient[count].number++;
    }

    void Kitchen::execute()
    {
        while (1)
        {
            // std::cout << "in exec" << std::endl;
            // try {
            long pid = static_cast<long>(getpid());
            // std::cout << "PID kitchen: " << pid << std::endl;
            CommandPizza cmd = _ipc.receive<CommandPizza>(5000, pid);
            // std::cout << "test cmd: " << cmd << std::endl;
            std::cout << "A pizza of size " << cmd.sizePizza << " "
                      << "and type " << cmd.typePizza << " has been order " << std::endl;
            // if (_listPizza.size() > 0)
            //     assign_cooks();
            // if (_clock.getElapsedTime() > 5000) {
            //     // exit(0);
            //     std::cout << "Kitchen " << _pid << " will close" << std::endl;
            //     return;
            // }
            // } catch (const std::exception &e) {
            //     std::cout << "Catch error: " << e.what() << std::endl;
            //     return;
            // }

            // if (_clock.getElapsedTime() > _time)
            // {
            // regenIngredient();
            // }
        }
    }
    /*
void Kitchen::execute()
{
    while (!_listPizza.empty())
    {
        if (_listPizza.size() > 0)
            assign_cooks();
        if (_clock.getElapsedTime() > 5000)
        {
            std::cout << "Kitchen " << _pid << " will close" << std::endl;
            return;
        }

        if (_clock.getElapsedTime() > _time)
        {
            regenIngredient();
        }
    }
}
*/

    int Kitchen::getNumberCommand() const
    {
        return _listPizza.size();
    }

    void Kitchen::deletePizza(int id)
    {
        for (size_t count = 0; count < _listPizza.size(); ++count)
        {
            if (_listPizza[count]->getId() == id)
            {
                _listPizza.erase(_listPizza.begin() + count);
                return;
            }
        }
    }

}
