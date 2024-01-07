#include <gtest/gtest.h>
#include "UI.h"

TEST(UITest, PrintMapTest) {
    // Redirect cout to a stringstream for testing
    std::stringstream output;
    std::streambuf *coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    UI ui;
    ui.printMap(4); // Assuming the current position is 4

    // Restore cout
    std::cout.rdbuf(coutBuffer);

    // Verify the printed map using EXPECT_EQ
    std::string expectedOutput =
        "Map:\n+---+---+---+\n|   |   |   | \n+---+---+---+\n|   | X |   | "
        "\n+---+---+---+\n|   |   |   |\n+---+---+---+\n";
    EXPECT_EQ(output.str(), expectedOutput);
}
