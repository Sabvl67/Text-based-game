// NPC.h

#ifndef NPC_h
#define NPC_h
#include "Entity.h"
#include <iostream>
#include <string>

class NPC : public Entity {
 public:
  NPC(std::string name, int baseStrength, int baseHp, int baseMana)
      : Entity(name, baseStrength, baseHp, baseMana) {}

  NPC(std::string name) : Entity(name, 10, 100, 50) {}

  virtual void talk() const {
    std::cout << name << ": Greetings!" << std::endl;
  }

  Types::factionType getFaction() { return Types::factionType::NPC; }
};

#endif /* NPC_h */
