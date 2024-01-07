// Item.cpp
#include "Item.h"
#include "Player.h"

Item::Item(std::string itemName, int itemDmg, int itemHp)
    : name(itemName), dmg(itemDmg), hp(itemHp) {}

std::string Item::getName() const { return name; }

int Item::getDmg() const { return dmg; }
int Item::getHp() const { return hp; }

Item::~Item() {}
