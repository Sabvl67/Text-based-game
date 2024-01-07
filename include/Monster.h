#ifndef Monster_h
#define Monster_h

#include "Entity.h"
#include <iostream>
#include <string>

class Monster : public Entity {
 public:
  Monster(std::string name, int baseStrength, int baseHp, int baseMana)
      : Entity(name, baseStrength, baseHp, baseMana) {}

  Types::factionType getFaction() { return Types::factionType::MONSTER; }
};

#endif /* Monster_h */
