#ifndef WEIGHTS_HPP
#define WEIGHTS_HPP

#include <map>
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
typedef std::map<std::string, Weights> WeightsMap;

WeightsMap loadWeightsFromFile(const std::string& filename);
void writeWeightsToFile(const std::string& filename, const WeightsMap& data);
void printWeightsMap(const WeightsMap& map);

#endif