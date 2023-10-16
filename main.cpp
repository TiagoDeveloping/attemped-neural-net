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
    std::chrono::system_clock::time_point end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> timeDiff = end_time - start_time;
    double timeDiffSeconds = timeDiff.count();

    std::cout << "starting....\n";
    std::cout << "loading image....\n";

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

    end_time = std::chrono::system_clock::now();
    timeDiff = end_time - start_time;
    timeDiffSeconds = timeDiff.count();
    std::cout << "finished loading image matrices: " << timeDiffSeconds << " seconds \n";

    /*  FIRST LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << "loading first layer weights...\n";

    int firstLayer_weightsPerNeuron = singleDimensionalImage.size();
    std::vector<Neuron>* firsyLayerNeurons = loadNeuronWeightsFromFile(FIRSTLAYER_WEIGHTS_FILENAME, firstLayer_weightsPerNeuron, singleDimensionalImage.size(), 0, 1);

    std::cout << firsyLayerNeurons->at(0).weights[0] << std::endl;

    end_time = std::chrono::system_clock::now();
    timeDiff = end_time - start_time;
    timeDiffSeconds = timeDiff.count();
    std::cout << "finished loading first layer weights: " << timeDiffSeconds << " seconds \n";

    /* OUTPUT LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << "loading output layer weights...\n";

    int outputLayer_weightsPerNeuron = firsyLayerNeurons->size();
    std::vector<Neuron>* outputLayerNeurons = loadNeuronWeightsFromFile(OUTPUT_WEIGHTS_FILENAME, 4, outputLayer_weightsPerNeuron, 0, 1);

    std::cout << outputLayerNeurons->at(0).weights[0] << std::endl;

    end_time = std::chrono::system_clock::now();
    timeDiff = end_time - start_time;
    timeDiffSeconds = timeDiff.count();
    std::cout << "finished loading output layer weights: " << timeDiffSeconds << " seconds \n";

    bool learning = true;
    int r = 0;

    std::vector<double> firstLayer_values;
    std::vector<double> outputLayer_values;

    start_time = std::chrono::system_clock::now();

    // while (learning) {
    //     if (r == 100) learning = false;

        /* first layer */
        for (int i = 0; i < firsyLayerNeurons->size(); i++) {
            firstLayer_values.insert(firstLayer_values.begin() + i, forwardPropagation(singleDimensionalImage, firsyLayerNeurons->at(i).weights));
        }
        std::cout << std::endl;

        /* output layer */
        for (int i = 0; i < outputLayerNeurons->size(); i++) {
            outputLayer_values.insert(outputLayer_values.begin() + i, forwardPropagation(firstLayer_values, outputLayerNeurons->at(i).weights));
        }

        for (double d : outputLayer_values) {
            std::cout << d << "\n";
        }
    // }

    delete firsyLayerNeurons;
    delete outputLayerNeurons;
    delete imageMatrix;

    end_time = std::chrono::system_clock::now();
    timeDiff = end_time - start_time;
    timeDiffSeconds = timeDiff.count();
    std::cout << "finished... took: " << timeDiffSeconds << " seconds \n";

    return 0;
}

