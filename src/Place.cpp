//  Place.cpp
//  team_d
//  Created by PC on 2023-12-05.
//

#include "Place.h"
#include "Player.h"
#include <stdio.h>

// Constructor
Place::Place(const std::string &itemName, int itemDmg, int itemHp,
             const std::string &npcName, int npcDmg, int npcHp, int npcMana)
    : item(itemName, itemDmg, itemHp),
      monster(npcName, npcDmg, npcHp, npcMana) {}

Item* Place::getItem() { return &item; }

NPC* Place::getNPC() { return &monster; }

std::string DreamSymphony::getSettingName() const { return "Dream Symphony"; }

void DreamSymphony::printRoomDescription() {
    std::cout << "You are in the Dream Symphony.\n";
}

std::string FrozenTundra::getSettingName() const { return "Frozen Tundra"; }

void FrozenTundra::printRoomDescription() {
    std::cout << "You are in the Frozen Tundra.\n";
}

std::string KittyIsland::getSettingName() const { return "Kitty Island"; }

void KittyIsland::printRoomDescription() {
    std::cout << "You are in the Kitty Island.\n";
}

std::string RizzlerCanyons::getSettingName() const { return "Rizzler Canyons"; }

void RizzlerCanyons::printRoomDescription() {
    std::cout << "You are in the Rizzler Canyons.\n";
}

std::string LuminousEchoes::getSettingName() const { return "Luminous Echoes"; }

void LuminousEchoes::printRoomDescription() {
    std::cout << "You are in the Luminous Echoes.\n";
}

std::string NeonNexus::getSettingName() const { return "Neon Nexus"; }

void NeonNexus::printRoomDescription() {
    std::cout << "You are in the Neon Nexus.\n";
}

std::string NefariousCivic::getSettingName() const { return "Nefarious Civic"; }

void NefariousCivic::printRoomDescription() {
    std::cout << "You are in the Nefarious Civic.\n";
}

std::string DrunkenIsles::getSettingName() const { return "Drunken Isles"; }

void DrunkenIsles::printRoomDescription() {
    std::cout << "You are in the Drunken Isles.\n";
}

std::string QuantumAbyss::getSettingName() const { return "Quantum Abyss"; }

void QuantumAbyss::printRoomDescription() {
    std::cout << "You are in the Quantum Abyss.\n";
}
