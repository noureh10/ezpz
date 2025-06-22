/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:06:23
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 15:30:35
 */

#ifndef MODLIST_HPP
# define MODLIST_HPP

#include "ACommand.hpp"
#include "../../modlist_manager/WorkshopManager.hpp"

class Modlist : public ACommand {
    private:
        // Object accountable for every mod installation and removal
        WorkshopManager _manager;
        
        void showModlist(void);
        bool installWorkshopCollection(void);
        bool installSingleMod(unsigned int workshop_id);
        bool removeMod(void);
        bool removeWorkshopCollection(void);
        bool removeAll(void);
    public:
        Modlist(void);
        ~Modlist();
        void execute(void);
};

#endif