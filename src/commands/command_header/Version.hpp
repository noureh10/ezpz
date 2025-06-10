/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:07:10
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-10 14:25:27
 */

#ifndef VERSION_HPP
# define VERSION_HPP

#include "ACommand.hpp"

class Version : public ACommand {
    public:
        Version(void);
        ~Version();
        void execute(void);
};

#endif