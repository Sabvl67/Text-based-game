//

//  Director.h

//  team_d

//
//  Created by PC on 2023-12-03.
//
#ifndef Director_h
#define Director_h
#include "NPC.h"
#include "Place.h"
#include "Player.h"
#include "UI.h"

class Director {
 public:
  Player *player;
  Place *settings[9];
  int position = 4; // Center. Note this goes left to right and not up to down
  UI ui;
  Director(Player *player);
  ~Director();
  void doTurn();
  void fightMonster();
  void handleInventory();

 private:
  Place *makeRandomPlace(int itemDmg, int itemHp, int npcDmg, int npcHp,
                          int npcMana);
  int defeatedMonsters = 0;
};

#endif /* Director_h */
