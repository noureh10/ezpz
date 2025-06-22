/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-05-29 19:34:45
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 11:53:12
 */

#ifndef ACOMMANDS_HPP
# define ACOMMANDS_HPP

#include <iostream>
#include <map>
#include <set>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define BLUE    "\x1b[34m"
# define BLACK   "\x1b[30m"
# define WHITE   "\x1b[37m"
# define PINK    "\x1b[35m"
# define YELLOW  "\x1b[33m"
# define BROWN   "\x1b[33m"
# define ORANGE  "\x1b[33m"
# define PURPLE  "\x1b[35m"
# define GRAY    "\x1b[90m"
# define LIGHTGRAY "\x1b[37m"
# define DARKGRAY  "\x1b[90m"
# define RESET   "\x1b[0m"

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