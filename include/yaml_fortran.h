#ifndef YAML_FORTRAN_H
#define YAML_FORTRAN_H

#include <iostream>
#include <unordered_map>
#include <variant>
#include <string>
#include <functional>
#include <stdexcept>
#include <yaml-cpp/yaml.h>
#include "yaml_fortran.h"


template<typename T, typename Variant>
struct is_in_variant;

template<typename T, typename... Types>
struct is_in_variant<T, std::variant<Types...> >
        : std::disjunction<std::is_same<T, Types>...> {
};

template<typename T, typename Variant>
constexpr bool is_in_variant_v = is_in_variant<T, Variant>::value;


template<typename VariableType>
class YamlFortran {
    std::unordered_map<std::string, VariableType> variableRegistry;

public:
    virtual ~YamlFortran() = default;

    template<typename T>
    void registerVariable(const std::string &name,
                          T &variable) {
        variableRegistry.emplace(name, std::ref(variable));
    }

    template<typename T>
    void setVariable(const std::string &name,
                     T value) {
        auto it = variableRegistry.find(name);
        if (it == variableRegistry.end()) {
            throw std::runtime_error(
                "Variable not registered: " + name);
        }

        try {
            std::get<std::reference_wrapper<T> >(it->second).get() =
                    value;
        } catch (const std::bad_variant_access &e) {
            throw std::runtime_error(
                "Type mismatch when setting variable: " + name);
        }
    }

    void load(YAML::Node node) {
        for (const auto &pair: variableRegistry) {
            const std::string &name = pair.first;
            const VariableType &variable = pair.second;

            if (!node[name]) {
                continue;
            }
            std::visit([&](auto &&arg) {
                using T = std::decay_t<decltype(arg.get())>;
                if constexpr (!is_in_variant_v<T, std::variant<
                    std::reference_wrapper<float> > >) {
                    std::cout << "Loading variable: " << name
                              << std::endl;
                    YAML::Node varNode = node[name];
                    std::cout << varNode["x"] << std::endl;
                }
                if constexpr (is_in_variant_v<T, std::variant<
                    std::reference_wrapper<float> > >) {
                    std::cout << "Loading variable: " << name
                              << std::endl;
                }
            }, variable);
        }
    }
};

#endif // YAML_FORTRAN_H
