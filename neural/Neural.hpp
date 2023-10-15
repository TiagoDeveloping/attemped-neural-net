#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <vector>

#include "../Matrix.hpp"
#include "Weights.hpp"

#define LEARNING_RATE 0.01

typedef struct {
    Weights weights;
} Neuron;

double* convolute(Matrix* input, Matrix* kernel);

double dot(const Weights& a, const Weights& b);
double sigmoid(double& value);
double weightedSum(const std::vector<double>& input, const Weights& weights);

double forwardPropagation(const std::vector<double>& input, const Weights& weights);

#endif