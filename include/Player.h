

#ifndef Player_h
#define Player_h
#include "Entity.h"
#include <iostream>
#include <string>
#include <vector>

class Item; // Forward declaration
class Player : public Entity {
 public:
  Player(std::string name) : Entity(name, 50, 100, 50) {}

  Types::factionType getFaction() { return Types::factionType::PLAYER; }

  // Inventory management methods
  void addToInventory(const Item &item);               // pick_up
  void removeFromInventory(std::vector<Item>::iterator it); // put_down
  std::vector<Item> &getInventory();
  void applyPowerup(const Item &item);
  void displayInventory() const; // Display player's inventory
  void useItem(int index);       // Use an item from the inventory

  void setAttack(int attack) { this->attack = attack; }
  void setHealth(int health) { this->hp = health; }

 private:
  // Player's inventory
  std::vector<Item> inventory;
};

#endif /* Player_h */
