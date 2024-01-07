#include "Monster.h"
#include <gtest/gtest.h>

TEST(TestMonsters, ConstructionTest) {
    Monster monster("Goblin", 10, 100, 50);
    EXPECT_EQ(monster.getName(), "Goblin");
    EXPECT_EQ(monster.getAttack(), 10);
    EXPECT_EQ(monster.getHealth(), 100);
    EXPECT_EQ(monster.getMana(), 50);
    EXPECT_EQ(monster.getFaction(), Types::factionType::MONSTER);
}

TEST(TestMonsters, CombatTests) {
    Monster monster1("Goblin", 1, 1, 1);
    Monster monster2("Goblin", 100, 100, 100);
    EXPECT_EQ(monster1.calcDamage(Types::attackType::PHYSICAL, 10), 10);
    EXPECT_EQ(monster2.calcDamage(Types::attackType::PHYSICAL, 10), 1);
    EXPECT_EQ(monster1.applyDamage(5), 0);
    EXPECT_EQ(monster2.applyDamage(5), 95);
    monster1.fight(&monster2, Types::attackType::PHYSICAL);
    EXPECT_EQ(monster2.getHealth(), 94);
}
