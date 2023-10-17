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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BOLD    "\x1b[1m"

typedef std::chrono::system_clock::time_point Time;

std::vector<double> squareOutput(4);

std::string MATRIX_IMAGE_GRAYSCALE = "matrix_image_grayscale";
std::string MATRICES_FILENAME = "matrices";
std::string INPUT_WEIGHTS_FILENAME = "input_weights";
std::string FIRSTLAYER_WEIGHTS_FILENAME = "first_weights";
std::string OUTPUT_WEIGHTS_FILENAME = "output_weights";

void setup() {
    squareOutput[0] = 0; // unknown
    squareOutput[1] = 1; // square
    squareOutput[2] = 0; // ellips/circle
    squareOutput[3] = 0; // triangle
}

void printTimeDiff(Time start, std::string msg) {
    Time end_time = std::chrono::system_clock::now();
    std::chrono::system_clock::duration timeDiff = end_time - start;
    double timeDiffSeconds = std::chrono::duration<double>(timeDiff).count();
    std::cout << ANSI_COLOR_GREEN << msg << " took: " << ANSI_COLOR_BOLD << timeDiffSeconds << ANSI_COLOR_RESET << ANSI_COLOR_GREEN << " seconds \n" << ANSI_COLOR_RESET;
}

int main() {
    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point sstart_time = std::chrono::system_clock::now();

    std::cout << ANSI_COLOR_BLUE << "starting... \n" << ANSI_COLOR_RESET;
    setup();
    std::cout << ANSI_COLOR_BLUE << "loading image....\n" << ANSI_COLOR_RESET;

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

    writeMatricesToFile(MATRICES_FILENAME, matrixMap);

    std::vector<double> singleDimensionalImage = imageMatrix->toSingleDimension();

    printTimeDiff(start_time, "finished loading image matrices");

    /*  FIRST LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << ANSI_COLOR_BLUE << "loading first layer weights...\n" << ANSI_COLOR_RESET;

    int firstLayer_weightsPerNeuron = singleDimensionalImage.size();
    std::vector<Neuron>* firstLayer_neurons = loadNeuronWeightsFromFile(FIRSTLAYER_WEIGHTS_FILENAME, firstLayer_weightsPerNeuron, singleDimensionalImage.size(), 0, 0.0000001);

    std::cout << firstLayer_neurons->at(0).weights[0] << std::endl;

    printTimeDiff(start_time, "finished loading first layer weights");

    /* OUTPUT LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << ANSI_COLOR_BLUE << "loading output layer weights...\n" << ANSI_COLOR_RESET;

    int outputLayer_weightsPerNeuron = firstLayer_neurons->size();
    std::vector<Neuron>* outputLayer_neurons = loadNeuronWeightsFromFile(OUTPUT_WEIGHTS_FILENAME, 4, outputLayer_weightsPerNeuron, 0, 0.0000001);

    std::cout << outputLayer_neurons->at(0).weights[0] << std::endl;

    printTimeDiff(start_time, "finished loading output layer weights");

    bool learning = true;
    int r = 0;int a = 0;

    std::vector<double> firstLayer_values;
    std::vector<double> outputLayer_values;

    start_time = std::chrono::system_clock::now();

    std::cout << ANSI_COLOR_BLUE << "start learning... \n" << ANSI_COLOR_RESET;

    std::cout << ANSI_COLOR_BLUE << "value before: " << ANSI_COLOR_RED << firstLayer_neurons->at(0).weights[0] << "\n" << ANSI_COLOR_RESET;

    /* run 1000 iteration of learning */
    while (learning) {
        if (a == 10) learning = false;
        if (r == 100 || r == 99) {
            std::cout << ANSI_COLOR_GREEN << ANSI_COLOR_BOLD << "SAVING FILES" << ANSI_COLOR_RESET << std::endl;
            WeightsMap map = getWeightsMapFromNeurons(firstLayer_neurons);
            writeWeightsToFile(FIRSTLAYER_WEIGHTS_FILENAME, map);

            map = getWeightsMapFromNeurons(outputLayer_neurons);
            writeWeightsToFile(OUTPUT_WEIGHTS_FILENAME, map);
            r = 0;
            a++;
        }
        /* first layer */
        for (int i = 0; i < firstLayer_neurons->size(); i++) {
            firstLayer_values.insert(firstLayer_values.end(), forwardPropagation(singleDimensionalImage, firstLayer_neurons->at(i).weights));
        }

        /* output layer */
        for (int i = 0; i < outputLayer_neurons->size(); i++) {
            outputLayer_values.insert(outputLayer_values.end(), forwardPropagation(firstLayer_values, outputLayer_neurons->at(i).weights));
        }

        for (double d : outputLayer_values) {
            std::cout << d << "\n";
        }
        std::cout << "\n";

        /* BACKWARD */
        backwardPropagation(firstLayer_neurons, outputLayer_neurons, firstLayer_values, outputLayer_values, singleDimensionalImage, squareOutput);
        firstLayer_values.clear();
        firstLayer_values.shrink_to_fit();
        outputLayer_values.clear();
        outputLayer_values.shrink_to_fit();
        r++;
    }

    printTimeDiff(start_time, "finished learning");

    std::cout << ANSI_COLOR_BLUE << "value after: " << ANSI_COLOR_RED << firstLayer_neurons->at(0).weights[0] << "\n" << ANSI_COLOR_RESET;

    delete firstLayer_neurons;
    delete outputLayer_neurons;
    delete imageMatrix;

    printTimeDiff(sstart_time, "full executing took");

    return 0;
}

