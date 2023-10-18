#ifndef NEURAL_HPP
#define NEURAL_HPP

#include <vector>

#include "../Matrix.hpp"
#include "Weights.hpp"

#define LEARNING_RATE 0.1

typedef struct {
    Weights weights;
} Neuron;

double* convolute(Matrix* input, Matrix* kernel);

double dot(const Weights& a, const Weights& b);
double sigmoid_derivative(double x);
double sigmoid(double x);
double weightedSum(const std::vector<double>& input, const Weights& weights);

double forwardPropagation(const std::vector<double>& input, const Weights& weights);
void backwardPropagation(std::vector<Neuron>* hiddenLayer_neurons, std::vector<Neuron>* outputLayer_neurons, std::vector<double>& hiddenLayer_values, std::vector<double>& outputLayer_values, std::vector<double>& input, std::vector<double>& target);

void backwardPropagation(
    std::vector<Neuron>* hiddenLayer1_neurons,
    std::vector<Neuron>* hiddenLayer2_neurons,
    std::vector<Neuron>* outputLayer_neurons,
    std::vector<double>& hiddenLayer1_values,
    std::vector<double>& hiddenLayer2_values,
    std::vector<double>& outputLayer_values,
    std::vector<double>& input,
    std::vector<double>& target
);

#endif