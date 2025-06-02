/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-05-29 19:34:45
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-02 22:37:15
 */

#ifndef ACOMMANDS_HPP
# define ACOMMANDS_HPP

#include <iostream>

class ACommand {
    protected:
        std::string command_arguments;
    public:
        ACommand(void);
        ~ACommand();
};

# endif