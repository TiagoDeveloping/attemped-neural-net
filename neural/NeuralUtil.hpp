#ifndef NEURAL_UTIL_HPP
#define NEURAL_UTIL_HPP

#include <vector>
#include <string>

#include "Neural.hpp"

std::vector<Neuron> loadNeuronWeightsFromFile(std::string& filename, int amountOfNeurons, size_t amountOfWeightsPerNeuron, double b0, double b1);

inline double ReLU(double value) {
    if (value < 0) {
        return 0;
    } else {
        return value;
    }
};

#endif