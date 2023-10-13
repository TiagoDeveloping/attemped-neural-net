#ifndef NEURAL_UTIL_HPP
#define NEURAL_UTIL_HPP

#include <vector>

/**
 * @brief represents a specific weight associated with the connection between 
 * the i-th input neuron and the j-th neuron in the hidden layer
 */
typedef std::vector<std::vector<double> > Weights;

inline void ReLu(double* value) {
    if (*value < 0) {
        *value = 0;
        return;
    } else {
        return;
    }
}

/**
 * @brief dot product
 * 
 * @note pls delete value!!!
 * 
 * @param input 
 * @param weights 
 * @param neuron_index 
 * @return double* 
 */
inline double* dot(std::vector<double>& input, Weights& weights, int neuron_index) {
    double* result = new double;
    *result = 0.0;
    for (int i = 0; i < input.size(); i++) {
        *result += input[i] * weights[i][neuron_index];
    }
    ReLu(result);
    return result;
}

#endif