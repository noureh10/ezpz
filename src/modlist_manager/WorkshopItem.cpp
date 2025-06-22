/**
 * @ Author: Nour Echaara
 * @ Create Time: 2025-06-15 19:18:44
 * @ Modified by: Nour Echaara
 * @ Modified time: 2025-06-22 13:41:46
 */

#include "WorkshopItem.hpp"

/**
 * @brief 
 * the hasCycleUtil is here to check if any workshop item has a circular dependency starting from the current
 * item, avoiding infinite cycles.
 * @param visited set of fully explored workshop items
 * @param recursionStack current path of the DFS
 */
bool WorkshopItem::hasCycleUtil(std::set<WorkshopItem*>& visited, std::set<WorkshopItem*>& recursionStack) {
    visited.insert(this);
    recursionStack.insert(this);

    for (auto dep : _dependencies) {
        if (visited.find(dep) == visited.end()) {
            if (dep->hasCycleUtil(visited, recursionStack)) {
                return (true);
            }
        } else if (recursionStack.find(dep) != recursionStack.end()) {
            return (true);
        }
    }
    recursionStack.erase(this);
    return (false);
}

WorkshopItem::WorkshopItem(unsigned int workshopID) : _workshopID(workshopID) {}

unsigned int WorkshopItem::getID() const {
    return (_workshopID);
}

std::string& WorkshopItem::getWorkshopName() const {
    return (_workshop_name);
}

std::string& WorkshopItem::getWorkshopModDescription() const {
    return (_workshop_item_descritpion);
}

uintmax_t WorkshopItem::getNonFormattedFilesize() const {
    return (std::filesystem::file_size(this->_workshop_item_path));
}

bool WorkshopItem::addDependency(WorkshopItem* dependency) {
    std::set<WorkshopItem*> visited;
    std::set<WorkshopItem*> recursionStack;
    
    if (dependency == this) {
        return (false);
    }
    _dependencies.insert(dependency);
    if (hasCycleUtil(visited, recursionStack)) {
        _dependencies.erase(dependency);
        return (false);
    }
    return (true);
}

const std::set<WorkshopItem*>& WorkshopItem::getDependencies() const {
    return (_dependencies);
}

std::set<WorkshopItem*> WorkshopItem::getAllDependencies() const {
    std::set<WorkshopItem*> allDeps;
    std::vector<WorkshopItem*> stack(_dependencies.begin(), _dependencies.end());

    while (!stack.empty()) {
        WorkshopItem* current = stack.back();
        stack.pop_back();

        if (allDeps.find(current) == allDeps.end()) {
            allDeps.insert(current);
            for (auto dep : current->_dependencies) {
                stack.push_back(dep);
            }
        }
    }
    return (allDeps);
}