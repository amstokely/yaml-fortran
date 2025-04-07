#include <gtest/gtest.h>
#include "fixture/YamlFortranFixture.h"
#include "yaml_fortran.h"

TEST_F(YamlFortranFixture, TestYamlNode) {
    Mat3 mat3;

    // Create a loader for the Mat3 type (Vec3 rows)
    YamlFortran<std::variant<std::reference_wrapper<Vec3>>> mat3Loader;
    mat3.load(mat3Loader);
    mat3Loader.load(mat3Node);


    EXPECT_FLOAT_EQ(mat3.row1.x, 1.0f);
    EXPECT_FLOAT_EQ(mat3.row2.y, 1.0f);
    EXPECT_FLOAT_EQ(mat3.row3.z, 1.0f);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
