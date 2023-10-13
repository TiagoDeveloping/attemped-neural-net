#include <iostream>
#include <stdexcept>

#include "Neural.hpp"
#include "../Matrix.hpp"
#include "Weights.hpp"



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

/**
 * @brief Propegate single neuron forward.
 * 
 * @param input vector<double> of the values the neuron gets
 * @param weights weights for each input value the neuron gets
 * @return double 
 */
double forwardPropagation(const std::vector<double>& input, const Weights& weights) {
    double weighted_sum = weightedSum(input, weights);

    double output = ReLU(weighted_sum);

    return output;
}

/**
 * @brief returns weighted sum
 * 
 * @param input 
 * @param weights 
 * @return double 
 */
double weightedSum(const std::vector<double>& input, const Weights& weights) {
    if (input.size() != weights.size()) {
        throw std::runtime_error("Input size does not match weight size.");
    }

    double sum = 0.0;

    for (size_t i = 0; i < input.size(); i++) {
        sum += input[i] * weights[i];
    }

    return sum;
}