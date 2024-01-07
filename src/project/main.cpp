#include "Director.h"
#include "Item.h"
#include "NPC.h"
#include "Place.h"
#include "Player.h"
#include <iostream>
#include <string>

int main() {
    char name[100] = {0};

    std::cout << "Hello may I have your name please?" << std::endl;
    std::cin.getline(name, 100);
    Player player(name);
    std::cout << "Welcome " << player.getName() << std::endl;

    Director director(&player);

    director.doTurn();
    return 0;
}
