#ifndef YAMLNODEFIXTURE_H
#define YAMLNODEFIXTURE_H

#include <gtest/gtest.h>
#include "yaml-cpp/yaml.h"

class YamlNodeFixture : public ::testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;

    YAML::Node node;

};

#endif // YAMLNODEFIXTURE_H
