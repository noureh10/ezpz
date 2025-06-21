/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-15 18:37:41
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-21 23:35:36
 */

#ifndef WORKSHOPITEM_HPP
#define WORKSHOPITEM_HPP

#include <set>
#include <vector>

class WorkshopItem {
private:
    unsigned int _workshopID;
    std::set<WorkshopItem*> _dependencies;
    bool hasCycleUtil(std::set<WorkshopItem*>& visited, std::set<WorkshopItem*>& recursionStack);
public:
    explicit WorkshopItem(unsigned int workshopID);
    unsigned int getID() const;
    bool addDependency(WorkshopItem* dependency);
    const std::set<WorkshopItem*>& getDependencies() const;
    std::set<WorkshopItem*> getAllDependencies() const;
};

#endif