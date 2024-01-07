#ifndef UI_h
#define UI_h
#include "Types.h"
#include <cctype>
#include <string>
#include <vector>

class UI {
 public:
  UI() {}
  void printMap(int currPosition);
  char promptChar(std::string msg, std::vector<char> valid);
  Types::actionType promptAction(std::vector<Types::actionType>);
};

#endif // UI_h
