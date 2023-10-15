#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <ctime>

#define STB_IMAGE_IMPLEMENTATION

#include "Matrix.hpp"
#include "neural/Neural.hpp"
// #include "neural/Kernel.hpp"
#include "StringMatrixMap.hpp"
#include "Util.hpp"
#include "neural/Weights.hpp"

#define MATRIX_IMAGE_GRAYSCALE "matrix_image_grayscale"

std::string MATRICES_FILENAME = "matrices";
std::string INPUT_WEIGHTS_FILENAME = "input_weights";
std::string FIRSTLAYER_WEIGHTS_FILENAME = "first_weights";
std::string OUTPUT_WEIGHTS_FILENAME = "output_weights";

int main() {
    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();

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


    /*  FIRST LAYER WEIGHTS SETUP */
    int firstLayer_weightsPerNeuron = singleDimensionalImage.size();
    std::vector<Neuron> firstLayer = loadNeuronWeightsFromFile(FIRSTLAYER_WEIGHTS_FILENAME, firstLayer_weightsPerNeuron, singleDimensionalImage.size(), 0, 255);

    std::cout << firstLayer.at(0).weights[0] << std::endl;

    // writeWeightsToFile(WEIGHTS_FILENAME, weightsMap);

    // double neuron0 = forwardPropagation(singleDimensionalImage, *inputLayerWeights);

    // std::cout << "neuron0: " << neuron0 << "\n";

    delete imageMatrix;

    // writeMatricesToFile(MATRICES_FILENAME, matrixMap);

    std::chrono::system_clock::time_point end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> timeDiff = end_time - start_time;
    double timeDiffSeconds = timeDiff.count();
    std::cout << "finished... took: " << timeDiffSeconds << " seconds \n";

    return 0;
}

