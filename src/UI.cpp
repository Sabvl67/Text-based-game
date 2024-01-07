#include "UI.h"
#include <algorithm>
#include <iostream>
#include <map>

void UI::printMap(int currPosition) {
    std::cout << "Map:\n+---+---+---+\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << "| ";
        if (i % 3 == 0 && i != 0)
            std::cout << "\n+---+---+---+\n| ";
        if (i == currPosition) {
            std::cout << "X ";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << "|\n+---+---+---+\n";
}

char UI::promptChar(std::string msg, std::vector<char> valid) {
    char choice;
    while (true) {
        std::cout << msg << std::endl << "Enter your choice: ";
        std::cin >> choice;
        choice = tolower(choice);
        if (std::find(valid.begin(), valid.end(), choice) != valid.end()) {
            return choice;
        }
        std::cout << "That is not a valid option! Try again.\n";
    }
}

Types::actionType UI::promptAction(std::vector<Types::actionType> actions) {
    char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::vector<char> valid;
    std::string msg = "What would you like to do?\n";
    std::map<char, Types::actionType> actionMap;
    int i = 0;
    for (Types::actionType a : actions) {
        msg = msg + digits[i] + ". " +
              Types::getActionDescription(a) + "\n";
        valid.push_back(digits[i]);
        actionMap[digits[i]] = a;
        i++;
    }
    char choice = promptChar(msg, valid);
    return actionMap[choice];
}
