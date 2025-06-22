/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-15 19:37:06
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 11:49:44
 */

#ifndef WORKSHOPMANAGER_HPP
#define WORKSHOPMANAGER_HPP

#include <memory>
#include <unordered_map>
#include "WorkshopItem.hpp"

class WorkshopItem;

class WorkshopManager {
    private:
        std::unordered_map<unsigned int, std::shared_ptr<WorkshopItem>> items;
    public:
        std::shared_ptr<WorkshopItem> createItem(unsigned int id);
        std::shared_ptr<WorkshopItem> getItem(unsigned int id) const;
        const std::unordered_map<unsigned int, std::shared_ptr<WorkshopItem>>& getItems(void) const;
};

#endif