/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:06:23
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:25:33
 */

#ifndef MODLIST_HPP
# define MODLIST_HPP

#include "ACommand.hpp"

class Modlist : public ACommand {
    public:
        Modlist(void);
        ~Modlist();
        void execute(void);
};

#endif