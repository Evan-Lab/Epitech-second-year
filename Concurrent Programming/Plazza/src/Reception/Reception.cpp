/*
** EPITECH PROJECT, 2023
** Plazza
** File description:
** Reception
*/

#include "Reception.hpp"

namespace Plazza
{

    Reception::Reception(double factor, int nb_cooks, long double time /*, IPC ipc*/) : _ipc(".", 4)
    {
        _factor = factor;
        _nb_cooks = nb_cooks;
        _time = time;
        create_loop();
    }

    Reception::~Reception()
    {
    }

    void Reception::create_loop()
    {
        std::string line;
        // std::vector<std::string> pizza;
        std::vector<std::string> size;
        std::vector<std::string> nb;

        while (1)
        {
            std::vector<std::string> pizza;
            std::cout << "Enter a pizza: ";
            std::getline(std::cin, line);
            Parser parser(line);
            std::vector<Command> command = parser.getCommand();
            for (size_t count = 0; count < command.size(); ++count)
            {
                std::vector<std::shared_ptr<IPizza>> stock = convertCommand(command[count], 0.0);
                _pizza.insert(_pizza.end(), stock.begin(), stock.end());
            };
            assign(_pizza, _time);
            _command.push_back(std::move(_pizza));
            _pizza.clear();
        }
    }

    void Reception::assign(std::vector<std::shared_ptr<IPizza>> pizza, long double time)
    {
        // std::cout << "Assign" << std::endl;

        if (_listPid.size() == 0)
        {
            // std::cout << "Create kitchen in if" << std::endl;
            create_kitchen(time);
        }

        //std::cout << "SIZE: " << pizza.size() << std::endl;

        bool status = false;
        for (size_t count_pizza = 0; count_pizza < pizza.size(); ++count_pizza)
        {
            for (size_t count_pid = 0; count_pid < _listPid.size(); ++count_pid)
            {
                if (count_pid < 2 * _nb_cooks)
                {
                    //std::cout << "size pizza: " << count_pizza << " status pizza: " << pizza[count_pizza]->getStatus() << std::endl;

                    status = true;
                    if (pizza[count_pizza]->getStatus() == StatusPizza::toAssign)
                    {
                        // std::cout << "If in loop for assign" << std::endl;
                        CommandPizza cmd;
                        cmd.typePizza = pizza[count_pizza]->getType();
                        cmd.sizePizza = pizza[count_pizza]->getSize();
                        pizza[count_pizza]->setStatus(StatusPizza::inKitchen);
                        cmd.stockPizza = pizza[count_pizza];
                        try
                        {
                            // std::cout << "PID in for: " << _listPid[count_pid] << std::endl;
                            _ipc.send<CommandPizza>(cmd, _listPid[count_pid]);
                        }
                        catch (const std::exception &e)
                        {
                            std::cout << e.what() << std::endl;
                        }
                    }
                    // std::cout << "count: " << count_pizza << std::endl;
                    break;
                }
            }

            if (status == false)
            {
                // std::cout << "If in loop for assign status == false" << std::endl;
                CommandPizza cmd;
                cmd.typePizza = pizza[count_pizza]->getType();
                cmd.sizePizza = pizza[count_pizza]->getSize();
                pizza[count_pizza]->setStatus(StatusPizza::inKitchen);
                cmd.stockPizza = pizza[count_pizza];
                // std::cout << "Create kitchen status == false" << std::endl;
                create_kitchen(time);
                // _ipc.send(cmd);
                try
                {
                    long test = _listPid[_listPid.size() - 1];
                    _ipc.send<CommandPizza>(cmd, test);
                }
                catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
            status = false;
        }

        std::cout << "Number kitchen of kitchen created " << _listPid.size() << std::endl;
    }

    void Reception::create_kitchen(long double time)
    {
        // std::cout << "Enter kitchen" << std::endl;
        pid_t pid = fork();
        std::shared_ptr<Kitchen> test;

        if (pid == -1)
        {
            throw Exception("fork() failed");
        }
        else if (pid == 0)
        {
            // std::cout << "PID FORK: "<< getpid() << std::endl;
            // Kitchen kitchen(pid, _nb_cooks, time);
            test = std::make_shared<Kitchen>(pid, _nb_cooks, time);
            // _kitchen.push_back(std::make_shared<Kitchen>(pid, _nb_cooks, time));
            // std::cout << "exit kitchen in assign1" << std::endl;
            //  CommandPizza cmd;
            //  _ipc.send(cmd);
            // exit(0);
        }
        else
        {
            // std::cout << "PID ELSE: " << getpid() << std::endl;
            // std::cout << "PID CREATE: " << pid << std::endl;
            // std::cout << "Kitchen forked" << std::endl;
            // std::cout << "exit kitchen in assign2" << std::endl;
            // _kitchen.push_back(test);
            //CommandPizza cmd = _ipc.receive(5000);
            _listPid.push_back(pid);
        }
        std::cout << "One kitchen was created" << std::endl;
    }

    std::vector<std::shared_ptr<IPizza>> Reception::convertCommand(Command cmd, long double time)
    {
        std::vector<std::shared_ptr<IPizza>> listPizza;
        std::shared_ptr<IPizza> newPizza;
        static int id = 0;

        for (int count = 0; count < cmd.number; ++count)
        {
            if (cmd.pizza == PizzaType::Regina)
                newPizza = std::make_unique<PizzaRegina>(cmd.size, time, id);
            else if (cmd.pizza == PizzaType::Margarita)
                newPizza = std::make_unique<PizzaMargarita>(cmd.size, time, id);
            else if (cmd.pizza == PizzaType::Americana)
                newPizza = std::make_unique<PizzaAmericana>(cmd.size, time, id);
            else if (cmd.pizza == PizzaType::Fantasia)
                newPizza = std::make_unique<PizzaFantasia>(cmd.size, time, id);
            // else
            //     throw Exception("Pizza not found");
            listPizza.push_back(newPizza);
            ++id;
        }
        return listPizza;
    }

    Exception::Exception(std::string msg)
    {
        _message = msg;
    }

    const char *Exception::what() const noexcept
    {
        return _message.c_str();
    }
}
