#ifndef YAML_NODE_H
#define YAML_NODE_H
#include <yaml-cpp/yaml.h>

int loadInt(YAML::Node &node, const std::string &key) {
    return node[key].as<int>();
}

float loadFloat(YAML::Node &node, const std::string &key) {
    return node[key].as<float>();
}

#endif //YAML_NODE_H
