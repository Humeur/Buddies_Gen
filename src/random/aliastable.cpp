#include "aliastable.hpp"

namespace buddy {

void AliasTable::initialize() {
    std::unique_ptr<double[]> normalProbs(new double[this->size]);
    std::unique_ptr<size_t[]> largeBlock(new size_t[this->size]);
    std::unique_ptr<size_t[]> smallBlock(new size_t[this->size]);

    if (!normalProbs || !largeBlock || !smallBlock) {
        std::cout << "Error: memory allocation failed!" << std::endl;
        exit(1);
    }

    double sum = 0;
    int64_t curSmallBlock, curLargeBlock;
    int64_t numSmallBlock, numLargeBlock;
    numSmallBlock = numLargeBlock = 0;

    for (size_t i = 0; i < this->size; i++)
        sum += this->weights[i];

    for (size_t i = 0; i < this->size; i++)
        normalProbs[i] = this->weights[i] * this->size / sum;

    for (int64_t i = this->size - 1; i >= 0; i--) {
        if (normalProbs[i] < 1) {
            smallBlock[numSmallBlock++] = i;
        } else {
            largeBlock[numLargeBlock++] = i;
        }
    }

    while (numSmallBlock && numLargeBlock) {
        curSmallBlock = smallBlock[--numSmallBlock];
        curLargeBlock = largeBlock[--numLargeBlock];
        this->probs[curSmallBlock] = normalProbs[curSmallBlock];
        this->alias[curSmallBlock] = curLargeBlock;
        normalProbs[curLargeBlock] = normalProbs[curLargeBlock] + normalProbs[curSmallBlock] - 1;
        if (normalProbs[curLargeBlock] < 1) {
            smallBlock[numSmallBlock++] = curLargeBlock;
        } else {
            largeBlock[numLargeBlock++] = curLargeBlock;
        }
    }

    while (numLargeBlock) {
        this->probs[largeBlock[--numLargeBlock]] = 1;
    }

    while (numSmallBlock) {
        this->probs[smallBlock[--numSmallBlock]] = 1;
    }
}

size_t AliasTable::sampling(std::mt19937 &random) const {
    std::uniform_real_distribution<double> r_uni(0, 1.0);
    int64_t k = static_cast<int64_t>(this->size * r_uni(random));
    return r_uni(random) < probs[k] ? k : alias[k];
}

};