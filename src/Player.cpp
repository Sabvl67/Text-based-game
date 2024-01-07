//  Player.cpp
//  team_d
//
//  Created by PC on 2023-12-04.
//

#include "Player.h"
#include "Item.h"
#include <algorithm>

void Player::addToInventory(const Item &item) { inventory.push_back(item); }

void Player::removeFromInventory(std::vector<Item>::iterator it) {
    inventory.erase(it);
}

std::vector<Item> &Player::getInventory() { return inventory; }

void Player::applyPowerup(const Item &item) {
    if (item.getDmg() > 0) {
        attack += item.getDmg();
        std::cout << "You gained " << item.getDmg() << " strength!\n";
        attack += item.getDmg();
    }
    if (item.getHp() > 0) {
        hp += item.getHp();
        std::cout << "You gained " << item.getHp() << " health!\n";
        hp = std::min(hp, baseHp);
    }
}

void Player::displayInventory() const {
    std::cout << "Inventory:\n";
    for (auto &item : inventory) {
        std::cout << "- " << item.getName() << std::endl;
    }
}

void Player::useItem(int index) {
    if (index >= 0 && index < inventory.size()) {
        Item &item = inventory[index];
        applyPowerup(item);
        removeFromInventory(inventory.begin() + index);
    } else {
        std::cout << "Invalid inventory index.\n";
    }
}
