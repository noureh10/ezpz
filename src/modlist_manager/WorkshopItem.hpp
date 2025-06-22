/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-15 18:37:41
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 13:39:53
 */

#ifndef WORKSHOPITEM_HPP
#define WORKSHOPITEM_HPP

#include <set>
#include <vector>
#include <iostream>
#include <filesystem>

class WorkshopItem {
private:
    unsigned int    _workshopID;
    std::string&    _workshop_name;
    std::string&    _workshop_item_descritpion;
    std::string&    _workshop_item_path;
    unsigned int    _workshop_item_size;
    std::set<WorkshopItem*> _dependencies;
    bool hasCycleUtil(std::set<WorkshopItem*>& visited, std::set<WorkshopItem*>& recursionStack);
public:
    explicit WorkshopItem(unsigned int workshopID);
    unsigned int getID(void) const;
    std::string& getWorkshopName(void) const;
    std::string& getWorkshopModDescription(void) const;
    std::string& getFormattedFilesize(void) const;
    uintmax_t getNonFormattedFilesize(void) const;
    bool addDependency(WorkshopItem* dependency);
    const std::set<WorkshopItem*>& getDependencies() const;
    std::set<WorkshopItem*> getAllDependencies() const;
};

#endif