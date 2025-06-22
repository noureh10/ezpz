/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-15 19:36:59
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 11:49:41
 */

#include "WorkshopManager.hpp"


std::shared_ptr<WorkshopItem> WorkshopManager::createItem(unsigned int id) {
    auto item = std::make_shared<WorkshopItem>(id);
    items[id] = item;
    return (item);
}

std::shared_ptr<WorkshopItem> WorkshopManager::getItem(unsigned int id) const {
    auto it = items.find(id);
    if (it != items.end())
        return (it->second);
    else
        return (nullptr);
}

const std::unordered_map<unsigned int, std::shared_ptr<WorkshopItem>>& WorkshopManager::getItems(void) const {
    return (items);
}