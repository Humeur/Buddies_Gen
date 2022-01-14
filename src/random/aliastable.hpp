#pragma once

#include <iostream>
#include <random>
#include <memory>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace buddy {

class AliasTable {
    private:
        size_t size;
        std::unique_ptr<double[]> weights;
        std::unique_ptr<size_t[]> alias;
        std::unique_ptr<double[]> probs;
        void initialize();
    public:
        template <class Elements, class Fn>
        constexpr AliasTable(const Elements &elements, const Fn &fn) :
        size(elements.size()), weights(new double[size]),
        alias(new size_t[size]), probs(new double[size]) {
            size_t index = 0;
            for (auto &element : elements) {
                this->weights[index++] = fn(element);
            }
            initialize();
        }
        
        size_t sampling(std::mt19937 &random) const;
};

};
