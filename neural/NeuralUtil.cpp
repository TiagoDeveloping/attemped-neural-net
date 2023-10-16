#include "NeuralUtil.hpp"

/**
 * @brief Loads neuron weights from file
 * 
 * @param filename: std::string
 * @param amountOfNeurons:int amount of neurons to load
 * @param amountOfWeightsPerNeuron:size_t amount of weights that each neuron has
 * @param b0:double min weight value
 * @param b1:double max weight value
 * @return std::vector<Neuron> 
 */
std::vector<Neuron>* loadNeuronWeightsFromFile(std::string& filename, int amountOfNeurons, size_t amountOfWeightsPerNeuron, double b0, double b1) {
    WeightsMap layer_weightsMap = loadWeightsFromFile(filename);

    std::vector<Neuron>* layer = new std::vector<Neuron>;

    for (int i = 0; i < amountOfNeurons; i++) {
        Neuron n;

        Weights* weights;
        if (layer_weightsMap.find(i) == layer_weightsMap.end()) {
            weights = getRandomWeights(amountOfWeightsPerNeuron, b0, b1);
            layer_weightsMap[i] = *weights;
        } else {
            weights = new Weights;
            *weights = layer_weightsMap[i];
        }

        n.weights = *weights;
        layer->insert(layer->begin() + i, n);

        delete weights;
    }

    // writeWeightsToFile(filename, layer_weightsMap);
    return layer;
}