#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <vector>

#include "../Matrix.hpp"
#include "Weights.hpp"

#define LEARNING_RATE 0.000001

typedef struct {
    Weights weights;
} Neuron;

double* convolute(Matrix* input, Matrix* kernel);

double dot(const Weights& a, const Weights& b);
double sigmoid(double& value);
double weightedSum(const std::vector<double>& input, const Weights& weights);

double forwardPropagation(const std::vector<double>& input, const Weights& weights);
void backwardPropagation(std::vector<Neuron>* hiddenLayer_neurons, std::vector<Neuron>* outputLayer_neurons, std::vector<double>& hiddenLayer_values, std::vector<double>& outputLayer_values, std::vector<double>& input, std::vector<double>& target);

#endif