#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <vector>

#include "../Matrix.hpp"
#include "NeuralUtil.hpp"

#define LEARNING_RATE 0.01

double* convolute(Matrix* input, Matrix* kernel);

double* weightedSum(std::vector<double> input, Weights weights, int neuron_index);

#endif