#ifndef Types_h
#define Types_h

#include <string>

class Types {
 public:
  enum attackType { PHYSICAL, RANGED, MAGIC };
  enum factionType { PLAYER, NPC, MONSTER };
  enum actionType {
      MOVE_NORTH,
      MOVE_EAST,
      MOVE_SOUTH,
      MOVE_WEST,
      FIGHT,
      PICKUP,
      INVENTORY
  };

  static std::string getActionDescription(actionType type);
};

#endif // Types_h
