/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-05-29 19:34:45
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-04 23:39:00
 */

#ifndef ACOMMANDS_HPP
# define ACOMMANDS_HPP

#include <iostream>
#include <map>
#include <set>

class ACommand {
    protected:
        std::string command_arguments;
    public:
        ACommand(void);
        ACommand(const std::string& cmd_args);
        virtual ~ACommand();
        virtual void execute() = 0;
        static ACommand* dispatch(const std::string& cmd, const std::string& subcmd);
        static const std::map<std::string, std::set<std::string>> getCommandMap(void);
};

# endif