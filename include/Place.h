//  Place.h
//  team_d
//
//  Created by PC on 2023-12-05.
//

#ifndef Place_h
#define Place_h

#include "Item.h"
#include "NPC.h"
#include <string>

class Place {
 private:
  Item item;
  NPC monster;

 public:
  bool itemOnGround = false;
  // Constructor
  Place(const std::string &itemName, int itemDmg, int itemHp,
        const std::string &npcName, int npcDmg, int npcHp, int npcMana);
  virtual void printRoomDescription() = 0;
  virtual std::string getSettingName() const = 0;
  Item* getItem();
  NPC* getNPC();
};

class DreamSymphony : public Place {
 public:
  // Constructor
  DreamSymphony(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("Fat Man", itemDmg, itemHp, "Freddy Kruger",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};

class FrozenTundra : public Place {
 public:
  // Constructor
  FrozenTundra(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("MK4", itemDmg, itemHp, "Canadians",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};

class KittyIsland : public Place {
 public:
  // Constructor
  KittyIsland(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("Mk6", itemDmg, itemHp, "Whiskermaster Purrington",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class RizzlerCanyons : public Place {
 public:
  // Constructor
  RizzlerCanyons(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("Mark 13", itemDmg, itemHp, "Eugene Gu",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class LuminousEchoes : public Place {
 public:
  // Constructor
  LuminousEchoes(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("B61", itemDmg, itemHp, "Queen Seraphina Starlight",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class NeonNexus : public Place {
 public:
  // Constructor
  NeonNexus(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("The TADM", itemDmg, itemHp, "Quantum Shimmer Disco", npcDmg,
              npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class NefariousCivic : public Place {
 public:
  // Constructor
  NefariousCivic(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("SM-62 SCM", itemDmg, itemHp, "Aidan Dale",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class DrunkenIsles : public Place {
 public:
  // Constructor
  DrunkenIsles(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("MIM-23 Hawk", itemDmg, itemHp, "Queen Cindy III",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};
class QuantumAbyss : public Place {
 public:
  // Constructor
  QuantumAbyss(int itemDmg, int itemHp, int npcDmg, int npcHp, int npcMana)
      : Place("AIM-47 Falcon", itemDmg, itemHp, "Count Sam The powerful",
              npcDmg, npcHp, npcMana) {}
  std::string getSettingName() const;
  void printRoomDescription();
};

#endif /* Place_h */
