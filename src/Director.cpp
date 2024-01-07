#include "Director.h"
#include "MakeRandomInt.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

int placeData[9][5] = {
    // itemDmg, itemHp, npcDmg, npcHp, npcMana
    {0, 25, 30, 50, 10},  {15, 2, 35, 55, 15}, {12, 30, 47, 52, 12},
    {10, 10, 72, 52, 23}, {0, 50, 49, 35, 46}, {4, 3, 48, 34, 5},
    {40, 5, 40, 39, 28},  {2, 2, 24, 34, 55},  {2, 0, 53, 35, 60}};

Director::Director(Player *player) : player(player) {
    std::vector<std::string> seen;
    for (int i = 0; i < 9; i++) {
        while (true) {
            auto data = placeData[i];
            auto place =
                makeRandomPlace(data[0], data[1], data[2], data[3], data[4]);
            auto name = place->getSettingName();
            std::vector<std::string>::iterator it;
            it = find(seen.begin(), seen.end(), name);
            if (it == seen.end()) {
                seen.push_back(name);
                settings[i] = place;
                break;
            } else {
                delete place;
            }
        }
    }
}

Director::~Director() {
    for (int i = 0; i < 9; i++) {
        delete settings[i];
    }
}

Place *Director::makeRandomPlace(int itemDmg, int itemHp, int npcDmg, int npcHp,
                                 int npcMana) {
    int val = MakeRandomInt::getInstance()->getValue(9);
    switch (val) {
    case 0:
        return new DreamSymphony(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 1:
        return new FrozenTundra(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 2:
        return new KittyIsland(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 3:
        return new RizzlerCanyons(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 4:
        return new LuminousEchoes(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 5:
        return new NeonNexus(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 6:
        return new NefariousCivic(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 7:
        return new DrunkenIsles(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    case 8:
        return new QuantumAbyss(itemDmg, itemHp, npcDmg, npcHp, npcMana);
        break;
    }
    assert("No Place was generated!!!");
}

void Director::doTurn() {
    if (player->getHealth() <= 0) {
        std::cout << "Game Over! You died.\n";
        return;
    }
    if (defeatedMonsters == 9) {
        std::cout << "Congratulations! You defeated all the monsters!\n";
        return;
    }
    ui.printMap(position);
    settings[position]->printRoomDescription();
    if (settings[position]->itemOnGround) {
        std::cout << "There is an item on the ground!\n";
    }
    std::vector<Types::actionType> actions;
    if (position > 2) {
        actions.push_back(Types::actionType::MOVE_NORTH);
    }
    if (position % 3 != 2) {
        actions.push_back(Types::actionType::MOVE_EAST);
    }
    if (position < 6) {
        actions.push_back(Types::actionType::MOVE_SOUTH);
    }
    if (position % 3 != 0) {
        actions.push_back(Types::actionType::MOVE_WEST);
    }
    if (settings[position]->getNPC()->getHealth() > 0) {
        actions.push_back(Types::actionType::FIGHT);
    }
    if (settings[position]->itemOnGround) {
        actions.push_back(Types::actionType::PICKUP);
    }
    if (player->getInventory().size() > 0) {
        actions.push_back(Types::actionType::INVENTORY);
    }
    auto choice = ui.promptAction(actions);
    switch (choice) {
    case Types::actionType::MOVE_NORTH:
        position -= 3;
        std::cout << position << std::endl;
        break;
    case Types::actionType::MOVE_EAST:
        position += 1;
        std::cout << position << std::endl;
        break;
    case Types::actionType::MOVE_SOUTH:
        position += 3;
        std::cout << position << std::endl;
        break;
    case Types::actionType::MOVE_WEST:
        position -= 1;
        std::cout << position << std::endl;
        break;
    case Types::actionType::FIGHT:
        fightMonster();
        break;
    case Types::actionType::PICKUP:
        player->addToInventory(*settings[position]->getItem());
        settings[position]->itemOnGround = false;
        break;
    case Types::actionType::INVENTORY:
        handleInventory();
        break;
    }
    doTurn();
}

void Director::fightMonster() {
    NPC *monster = settings[position]->getNPC();
    std::cout << "You engage in a battle with " << monster->getName() << "!\n";

    while (player->getHealth() > 0 && monster->getHealth() > 0) {
        char choice = ui.promptChar(
            "It's your turn! Type 'a' to attack or 'r' to run: ", {'a', 'r'});

        if (choice == 'a') {
            player->fight(monster, Types::attackType::PHYSICAL);
        } else if (choice == 'r') {
            std::cout << "You managed to escape from the battle!\n";
            break;
        }

        // Check if the monster is defeated
        if (monster->getHealth() <= 0) {
            std::cout << "Congratulations! You defeated " << monster->getName()
                      << "!\nIt looks like it dropped something...\n";
            settings[position]->itemOnGround = true;
            defeatedMonsters++;
            break;
        }

        // Monster's turn
        monster->fight(player, Types::attackType::PHYSICAL);

        // Check if the player is defeated
        if (player->getHealth() <= 0) {
            break;
        }
    }
}

void Director::handleInventory() {
    std::cout << "Inventory:\n";
    char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::vector<char> valid = {'1', '2', '3'};
    for (auto &item : player->getInventory()) {
        std::cout << "- " << item.getName() << std::endl;
    }
    std::string msg =
        "Which do you want to do?\n1. Use item\n2. Drop item\n3. Cancel\n";

    char typeChoice = ui.promptChar(msg, valid);
    if (typeChoice == '1') {
        msg = "Which item do you want to use?\n";
    } else if (typeChoice == '2') {
        msg = "Which item do you want to drop?\n";
    } else {
        return;
    }

    int i = 0;
    valid = {};
    for (auto &item : player->getInventory()) {
        msg = msg + digits[i] + ". " + item.getName() + '\n';
        valid.push_back(digits[i]);
        i++;
    }
    char choice = ui.promptChar(msg, valid);
    Item *selItem;
    i = 0;
    for (auto &item : player->getInventory()) {
        if (i == choice - '1') {
            selItem = &item;
            break;
        }
            i++;
    }
    if (typeChoice == '1') {
        player->applyPowerup(*selItem);
        player->removeFromInventory(std::find(player->getInventory().begin(),
                                              player->getInventory().end(),
                                              *selItem));
    } else if (typeChoice == '2') {
        player->removeFromInventory(std::find(player->getInventory().begin(),
                                              player->getInventory().end(),
                                              *selItem));
    }
}
