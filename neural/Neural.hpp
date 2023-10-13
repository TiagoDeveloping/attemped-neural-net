#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <vector>

#include "../Matrix.hpp"
#include "NeuralUtil.hpp"
#include "Weights.hpp"

#define LEARNING_RATE 0.01

double* convolute(Matrix* input, Matrix* kernel);

double weightedSum(const std::vector<double>& input, const Weights& weights);

double forwardPropagation(const std::vector<double>& input, const Weights& weights);

#endif