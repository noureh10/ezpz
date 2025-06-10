/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:08:19
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:23:26
 */

#include "command_header/ACommand.hpp"
#include "command_header/Help.hpp"
#include "command_header/Interactive.hpp"
#include "command_header/Modlist.hpp"
#include "command_header/SetConfig.hpp"
#include "command_header/Start.hpp"
#include "command_header/Status.hpp"
#include "command_header/Version.hpp"

ACommand::ACommand(void) {
    
}

ACommand::~ACommand() {

}

std::map<std::string, std::set<std::string>> ACommand::getCommandMap(void) {
    std::map<std::string, std::set<std::string>> commandMap = {
        {"help", {"ext"}},
        {"interactive", {"port"}},
        {"modlist", {"full", "minimal"}},
        {"setconfig", {}},
        {"start", {}},
        {"status", {}},
        {"version", {}}
    };
    return (commandMap);
}

bool ACommand::command_validator(const std::string& cmd, const std::string& subcmd) {
    const auto& command_map = getCommandMap();
    auto it = command_map.find(cmd);

    if (it == command_map.end()) {
        std::cerr << "Command " << cmd << " does not exist" << std::endl;
        return (false);
    }

    if (cmd == "setconfig") {
        if (subcmd.empty() || subcmd.size() < 6 || subcmd.substr(subcmd.size() - 5) != ".conf") {
            std::cerr << "setconfig requires a .conf file as parameter." << std::endl;
            return (false);
        }
        return (true);
    }

    if (!subcmd.empty() && it->second.find(subcmd) == it->second.end()) {
        std::cerr << "Subcommand: " << subcmd << " does not exist for command : " << cmd << std::endl;
        return (false);
    }
    return (true);
}

ACommand* ACommand::dispatch(const std::string& cmd, const std::string& subcmd) {
    if (!command_validator(cmd, subcmd))
        return (nullptr);
    if (cmd == "help") {
        return new Help();
    } else if (cmd == "interactive") {
        return new Interactive();
    } else if (cmd == "modlist") {
        return new Modlist();
    } else if (cmd == "setconfig") {
        return new SetConfig();
    } else if (cmd == "start") {
        return new Start();
    } else if (cmd == "status") {
        return new Status();
    } else if (cmd == "version") {
        return new Version();
    }
    return (nullptr);
}

