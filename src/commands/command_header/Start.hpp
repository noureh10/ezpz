/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:07:01
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:25:07
 */

#ifndef START_HPP
# define START_HPP

#include "ACommand.hpp"

class Start : public ACommand {
    public:
        Start(void);
        ~Start();
        void execute(void);
};

#endif