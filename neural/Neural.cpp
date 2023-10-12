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