
#ifndef Item_h
#define Item_h
#include <iostream>
#include <string>
class Player; // Forward declaration

class Item {
 public:
  Item(std::string itemName, int itemDmg, int itemHp);
  std::string getName() const;
  virtual ~Item();
  bool operator==(const Item &other) const {
      // Compare the items based on their properties
      return name == other.name && dmg == other.dmg &&
             hp == other.hp;
  }
  int getDmg() const;
  int getHp() const;

 private:
  int dmg;
  int hp;
  std::string name;
};

#endif // Item_h
