/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:07:36
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:25:17
 */

#ifndef STATUS_HPP
# define STATUS_HPP

#include "ACommand.hpp"

class Status : public ACommand {
    public:
        Status(void);
        ~Status();
        void execute(void);
};

#endif