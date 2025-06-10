/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:15:38
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 22:06:25
 */

#include "commands/command_header/ACommand.hpp"

/**
 * Temporary for now on, but good to get the project up and running
 * TO DO : Usage of smart pointers to stop using delete and new
 */
int main(int ac, char **av) {
    std::string cmd = (ac > 1) ? av[1] : "";
    std::string subcmd = (ac > 2) ? av[2] : "";
    ACommand* command = ACommand::dispatch(cmd,subcmd);
    if (!command)
        return (EXIT_FAILURE);
    try {
        command->execute();
    } catch (...) {
        delete command;
        return (EXIT_FAILURE);
    }
    delete command;
    return (EXIT_SUCCESS);
}