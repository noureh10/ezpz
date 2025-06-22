/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-02 23:08:42
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 12:23:24
 */

#include "command_header/Modlist.hpp"

Modlist::Modlist(void) {

}

Modlist::~Modlist(void) {
    
}

void Modlist::showModlist(void) {
    const std::unordered_map<unsigned int, std::shared_ptr<WorkshopItem>> items = _manager.getItems();
    std::shared_ptr<WorkshopItem> it_pointer;
    unsigned int workshop_id;
    
    for (auto it = items.begin(); it != items.end(); it++) {
        std::cout << BLUE << it->second->getWorkshopName() << RESET << " : "
        << it->second->getWorkshopModDescription() << " | " 
        << it->second->getFormattedFilesize() << "\n";
    }
}

bool Modlist::installWorkshopCollection(void) {
    
}

void Modlist::execute(void) {
    
}