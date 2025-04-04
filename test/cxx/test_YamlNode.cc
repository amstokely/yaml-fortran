#include <gtest/gtest.h>
#include "fixture/YamlNodeFixture.h"
#include "yaml_node.h"

TEST_F(YamlNodeFixture, TestYamlNode) {
    EXPECT_EQ(1, loadInt(this->node, "a_int"));
    EXPECT_EQ(1.0, loadFloat(this->node, "a_float"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
