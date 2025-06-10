/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:06:40
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:24:59
 */

#ifndef SETCONFIG_HPP
# define SETCONFIG_HPP

#include "ACommand.hpp"

class SetConfig : public ACommand {
    public:
        SetConfig(void);
        ~SetConfig(void);
        void execute(void);
};

#endif