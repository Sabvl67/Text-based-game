#ifndef Entity_h
#define Entity_h

#include "Types.h"
#include <algorithm>
#include <iostream>
#include <string>

class Entity {
 public:
  Entity(std::string name, int baseAttack, int baseHp, int baseMana)
      : name(name), baseAttack(baseAttack), baseHp(baseHp),
        baseMana(baseMana), attack(baseAttack), hp(baseHp), mana(baseMana) {}

  void fight(Entity *target, Types::attackType type) {
      int strength;
      if (type == Types::attackType::PHYSICAL ||
          type == Types::attackType::RANGED) {
          strength = attack;
      }
      if (type == Types::attackType::MAGIC) {
          strength = mana;
      }

      int dealt = target->calcDamage(type, strength);
      target->applyDamage(dealt);

      std::cout << name << " attacked " << target->name << " for " << dealt
                << " damage. (" << target->hp << "/" << target->baseHp
                << "HP)" << std::endl;
  }

  int applyDamage(int value) {
      hp = std::max(0, hp - value);
      return hp;
  }

  int calcDamage(Types::attackType type, int intensity) {
      int baseStat;
      if (type == Types::attackType::PHYSICAL ||
          type == Types::attackType::RANGED) {
          baseStat = attack;
      }
      if (type == Types::attackType::MAGIC) {
          baseStat = mana;
      }
      return std::max(1, intensity - (baseStat / 2));
  }

  int getHealth() { return hp; }
  int getAttack() { return attack; }
  int getMana() { return mana; }

  std::string getName() { return name; }

  virtual Types::factionType getFaction() = 0;

  virtual ~Entity() {}

 protected:
  int baseAttack;
  int baseHp;
  int baseMana;
  int attack;
  int hp;
  int mana;
  std::string name;
};

#endif /* Entity_h */
