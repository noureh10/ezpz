/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:06:05
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 18:35:59
 */

#ifndef INTERACTIVE_HPP
# define INTERACTIVE_HPP

#include "ACommand.hpp"

class Interactive : public ACommand {
    public:
        Interactive(void);
        ~Interactive();
        void execute(void);
};

#endif