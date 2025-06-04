/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:15:38
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-04 23:43:52
 */

#include "commands/command_header/ACommand.hpp"

bool command_validator(int ac, char **av) {
    size_t true_argument_count;
    std::string command;
    std::string subcommand;

    true_argument_count = ac - 1;
    if (true_argument_count == 0) {
        std::cerr << "No proper argument provided, aborting" << std::endl;
        return (false);
    }

    command = av[1];
    subcommand = (true_argument_count > 1) ? av[2] : "";

    const auto& command_map = ACommand::getCommandMap();
    auto it = command_map.find(command);

    if (it == command_map.end()) {
        std::cerr << "Command " << command << " does not exist" << std::endl;
        return (false);
    }

    if (!subcommand.empty() && it->second.find(subcommand) == it->second.end()) {
        std::cerr << "Subcommand: " << subcommand << " does not exist for command : " << command << std::endl;
        return (false);
    }

    return (true);
}

/**
 * Temporary for now on, but good to get the project up and running
 * TO DO : Usage of smart pointers to stop using delete and new
 */
int main(int ac, char **av) {
    if (!command_validator(ac,av))
        return EXIT_FAILURE;
    std::string command_args = av[1];
    std::string subcommand_args = (ac > 2) ? av[2] : "";
    ACommand* command = ACommand::dispatch(command_args, subcommand_args);
    if (!command) {
        std::cerr << "Dispatching error, work more on the validator !";
        return EXIT_FAILURE;
    }
    try {
        command->execute();
    } catch (...) {
        delete command;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}