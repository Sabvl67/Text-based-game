#include <gtest/gtest.h>
#include "Item.h"
#include "Player.h"

TEST(TestPlayer, ConstructionTest) {
    Player player("Greg");
    EXPECT_EQ(player.getName(), "Greg");
    EXPECT_EQ(player.getAttack(), 50);
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getMana(), 50);
    EXPECT_EQ(player.getFaction(), Types::factionType::PLAYER);
}

TEST(TestPlayer, CombatTests) {
    Player player1("Greg");
    Player player2("Bob");
    EXPECT_EQ(player1.calcDamage(Types::attackType::PHYSICAL, 10), 1);
    EXPECT_EQ(player2.calcDamage(Types::attackType::PHYSICAL, 10), 1);
    EXPECT_EQ(player1.applyDamage(5), 95);
    EXPECT_EQ(player2.applyDamage(5), 95);
    player1.fight(&player2, Types::attackType::PHYSICAL);
    EXPECT_EQ(player2.getHealth(), 70);
}
TEST(TestPlayer, InventoryTest) {
    Player player("Greg");
    Item sword("Sword", 10, 0);
    player.addToInventory(sword);
    EXPECT_EQ(player.getInventory().size(), 1);
    player.removeFromInventory(player.getInventory().begin());
    EXPECT_EQ(player.getInventory().size(), 0);
}
