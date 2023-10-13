#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION

#include "Matrix.hpp"
#include "neural/Neural.hpp"
// #include "neural/Kernel.hpp"
#include "StringMatrixMap.hpp"
#include "Util.hpp"
#include "neural/Weights.hpp"

#define MATRIX_IMAGE_GRAYSCALE "matrix_image_grayscale"

std::string MATRICES_FILENAME = "matrices";
std::string WEIGHTS_FILENAME = "weights";

int main() {
    std::cout << "starting....\n";

    StringMatrixMap matrixMap = loadMatricesFromFile(MATRICES_FILENAME);

    Matrix* imageMatrix;
    if (matrixMap.find(MATRIX_IMAGE_GRAYSCALE) == matrixMap.end()) {
        imageMatrix = new Matrix("image.png");
        imageMatrix->addToMap(MATRIX_IMAGE_GRAYSCALE, &matrixMap);
    } else {
        imageMatrix = new Matrix(matrixMap.at(MATRIX_IMAGE_GRAYSCALE));
        std::cout << "found: " << MATRIX_IMAGE_GRAYSCALE << " at file: " << MATRICES_FILENAME << "\n";
    }
    mapMatrix(imageMatrix, 0, 1);

    std::vector<double> singleDimensionalImage = imageMatrix->toSingleDimension();

    WeightsMap weightsMap = loadWeightsFromFile(WEIGHTS_FILENAME);
    
    Weights* inputLayerWeights;
    if (weightsMap.find(0) == weightsMap.end()) {
        inputLayerWeights = getRandomWeights(singleDimensionalImage.size(), 0, 1);
        weightsMap[0] = *inputLayerWeights;
    } else {
        inputLayerWeights = new Weights;
        *inputLayerWeights = weightsMap[0];
    }

    Weights* firstLayerWeights;
    if (weightsMap.find(1) == weightsMap.end()) {
        firstLayerWeights = getRandomWeights(singleDimensionalImage.size(), 0, 1);
        weightsMap[1] = *firstLayerWeights;
    } else {
        firstLayerWeights = new Weights;
        *firstLayerWeights = weightsMap[1];
    }

    Weights* outputLayerWeights;
    if (weightsMap.find(2) == weightsMap.end()) {
        outputLayerWeights = getRandomWeights(4, 0, 1);
        weightsMap[2] = *outputLayerWeights;
    } else {
        outputLayerWeights = new Weights;
        *outputLayerWeights = weightsMap[2];
    }

    writeWeightsToFile(WEIGHTS_FILENAME, weightsMap);

    double neuron0 = forwardPropagation(singleDimensionalImage, *inputLayerWeights);

    std::cout << "neuron0: " << neuron0 << "\n";

    delete firstLayerWeights;
    delete outputLayerWeights;
    delete inputLayerWeights;
    delete imageMatrix;

    writeMatricesToFile(MATRICES_FILENAME, matrixMap);

    std::cout << "finished\n";

    return 0;
}