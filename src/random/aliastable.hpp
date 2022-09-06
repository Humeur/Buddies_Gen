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
        
        template <typename Random>
        size_t operator()(Random &rdm) const {
            std::uniform_real_distribution<float> r_uni(0, 1.0);
            int64_t k = static_cast<int64_t>(this->size * r_uni(rdm));
            return r_uni(rdm) < probs[k] ? k : alias[k];
        };
};

};
