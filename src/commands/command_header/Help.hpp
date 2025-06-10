/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:05:48
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:25:44
 */

#ifndef HELP_HPP
# define HELP_HPP

#include "ACommand.hpp"

class Help : public ACommand {
    public:
        Help(void);
        ~Help();
        void execute(void);
};

#endif