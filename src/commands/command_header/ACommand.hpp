/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-05-29 19:34:45
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 22:07:02
 */

#ifndef ACOMMANDS_HPP
# define ACOMMANDS_HPP

#include <iostream>
#include <map>
#include <set>

class ACommand {
    private:
        static bool command_validator(const std::string& cmd, const std::string& subcmd);
        static std::map<std::string, std::set<std::string>> getCommandMap(void);
    protected:
        std::string command_arguments;
    public:
        ACommand(void);
        virtual ~ACommand();
        virtual void execute() = 0;
        static ACommand* dispatch(const std::string& cmd, const std::string& subcmd);
};

# endif