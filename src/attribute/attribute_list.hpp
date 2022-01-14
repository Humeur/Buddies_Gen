#pragma once

#include "attribute.hpp"
#include "../random/aliastable.hpp"
#include <vector>

namespace buddy {

template <class T> 
class AttributeList {
    private:
        std::vector<T *> attributes;
        AliasTable table;
        double totalWeight;
    public:
        AttributeList(std::initializer_list<std::pair<double, T *>> &&list) :
        table(list, [] (const std::pair<double, T *> &pair) { return pair.first; }) {
            attributes.reserve(list.size());
            for (auto &[key, value] : list) {
                attributes.emplace_back(value);
            }
        }

        AttributeList(const AttributeList<T> &other) = delete;
        AttributeList(AttributeList<T> &&other) = delete;

        [[nodiscard]] inline const size_t &size() const {
            return this->attributes.size();
        }

        template <class Random>
        [[nodiscard]] T *random(Random &random) const {
            return this->attributes[this->table.sampling(random)];
        }
};

struct ColoredAttribute : Attribute {
    const AttributeList<HexColor> *colors = nullptr;
};

}