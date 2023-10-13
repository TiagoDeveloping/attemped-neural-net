#include <iostream>
#include <stdexcept>

#include "Neural.hpp"
#include "../Matrix.hpp"

/**
 * @brief Convluates the values
 * 
 * @param input: Matrix, input matrix
 * @param kernel: Matrix, kernel matrix
 * @return ptr double convulated value
 */
double* convolute(Matrix* input, Matrix* kernel) {
    if (input->dimensions() != kernel->dimensions()) throw std::invalid_argument("input and kernel matrix should be equally sized!");
    double* val = new double;
    *val = 0;
    
    for (int y = 0; y < input->dimensions(); y++) {
        for (int x = 0; x < input->dimensions(); x++) {
            (*val) += (input->get(x, y) * kernel->get(x, y));
        }
    }
    return val;
}

double* weightedSum(std::vector<double> input, Weights weights, int neuron_index) {
    double* weighted_sum = new double;
    *weighted_sum = 0.0;
    for (int i = 0; i < input.size(); i++) {
        *weighted_sum += input[i] * weights[i][neuron_index];
    }
    return weighted_sum;
}