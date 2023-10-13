#ifndef WEIGHTS_HPP
#define WEIGHTS_HPP

#include <map>
#include <random>
#include <vector>

/**
 * @brief represents a specific weight associated with the connection between 
 * the i-th input neuron and the j-th neuron in the hidden layer
 */
typedef std::vector<double> Weights;

/**
 * @brief map of weights
 * 
 */
typedef std::map<int, Weights> WeightsMap;

/**
 * @brief Get set of random weights
 * 
 * @param amt 
 */
inline Weights* getRandomWeights(size_t amt, double b0, double b1) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(b0, b1); // Range from 0.0 to 1.0

    double randomValue = distribution(gen);

    Weights* weights = new Weights;

    for (size_t i = 0; i < amt; i++) {
        weights->push_back(randomValue);
        randomValue = distribution(gen);
    }

    return weights;
}

WeightsMap loadWeightsFromFile(const std::string& filename);
void writeWeightsToFile(const std::string& filename, const WeightsMap& data);
void printWeightsMap(const WeightsMap& map);

#endif