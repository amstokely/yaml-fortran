#ifndef YAMLNODEFIXTURE_H
#define YAMLNODEFIXTURE_H

#include <yaml_fortran.h>
#include <gtest/gtest.h>
#include "yaml-cpp/yaml.h"

class YamlFortranFixture : public ::testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;

    struct Vec3 {
        float x, y, z;

        void load(YamlFortran<std::variant<std::reference_wrapper<float>>>& yf) {
            yf.registerVariable("x", x);
            yf.registerVariable("y", y);
            yf.registerVariable("z", z);
        }
    };


    struct Mat3 {
        Vec3 row1, row2, row3;
        float sum{};

        void load(YamlFortran<std::variant<std::reference_wrapper<Vec3>>>& yf) {
            yf.registerVariable("row1", row1);
            yf.registerVariable("row2", row2);
            yf.registerVariable("row3", row3);
        }
    };

    YAML::Node row1;
    YAML::Node row2;
    YAML::Node row3;
    YAML::Node mat3Node;
};

#endif // YAMLNODEFIXTURE_H
