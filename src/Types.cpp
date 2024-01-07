#include "Types.h"

std::string Types::getActionDescription(actionType type) {
    switch (type) {
    case MOVE_NORTH:
        return "Go North";
    case MOVE_EAST:
        return "Go East";
    case MOVE_SOUTH:
        return "Go South";
    case MOVE_WEST:
        return "Go West";
    case FIGHT:
        return "Fight Monster";
    case PICKUP:
        return "Pick up Item";
    case INVENTORY:
        return "View Inventory";
    }
    return "MISSING_DESCRIPTION";
}
