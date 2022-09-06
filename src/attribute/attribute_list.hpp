#pragma once

#include "attribute.hpp"
#include "../random/aliastable.hpp"
#include <vector>
#include "color.hpp"
#include <utility>

namespace buddy {

template <class Type> 
class AttributeList : private NoCopy {
public:
    AttributeList(std::initializer_list<std::pair<float, const Type *>> list) :
    table(list, [] (const std::pair<float, const Type *> &pair) { return pair.first; }) {
        attributes.reserve(list.size());
        for (auto &[key, value] : list) {
            attributes.emplace_back(value);
        }
    }
    [[nodiscard]] inline const size_t &size() const {
        return this->attributes.size();
    }

    template <typename Random>
    const Type *operator()(Random &rdm) const {
        return this->attributes[this->table(rdm)];
    }
private:
    std::vector<const Type *> attributes;
    AliasTable table;
};

}