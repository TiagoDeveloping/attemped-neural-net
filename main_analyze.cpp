#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <ios>

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

std::vector<double> rectangleOutput(4);
std::vector<double> ellipsOutput(4);
std::vector<double> triangleOutput(4);
std::vector<double> otherOutput(4);

std::string MATRIX_IMAGE_GRAYSCALE = "matrix_image_grayscale";
std::string MATRICES_FILENAME = "matrices";
std::string SECONDLAYER_WEIGHTS_FILENAME = "second_weights";
std::string FIRSTLAYER_WEIGHTS_FILENAME = "first_weights";
std::string OUTPUT_WEIGHTS_FILENAME = "output_weights";

size_t findIndexOfHighestValue(const std::vector<double>& vec) {
    if (vec.empty()) {
        // Handle the case where the vector is empty.
        // You can throw an exception or return a default value as needed.
        // In this example, I'm returning 0 as a default.
        return 0;
    }

    double highest = vec[0];
    size_t indexOfHighest = 0;

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > highest) {
            highest = vec[i];
            indexOfHighest = i; // Update the index of the highest value.
        }
    }

    return indexOfHighest;
}

void setup() {
    rectangleOutput[0] = 0; // other
    rectangleOutput[1] = 1; // rectangle
    rectangleOutput[2] = 0; // ellips/circle
    rectangleOutput[3] = 0; // triangle

    ellipsOutput[0] = 0; // other
    ellipsOutput[1] = 0; // rectangle
    ellipsOutput[2] = 1; // ellips/circle
    ellipsOutput[3] = 0; // triangle

    triangleOutput[0] = 0; // other
    triangleOutput[1] = 0; // rectangle
    triangleOutput[2] = 0; // ellips/circle
    triangleOutput[3] = 1; // triangle

    otherOutput[0] = 1; // other
    otherOutput[1] = 0; // rectangle
    otherOutput[2] = 0; // ellips/circle
    otherOutput[3] = 0; // triangle
}

std::string extractNextFilename(std::ifstream& inputFile) {
    std::string line;
    if (std::getline(inputFile, line)) {
        return line;
    } else {
        return ""; // Return an empty string if there are no more filenames.
    }
}

void printTimeDiff(Time start, std::string msg) {
    Time end_time = std::chrono::system_clock::now();
    std::chrono::system_clock::duration timeDiff = end_time - start;
    double timeDiffSeconds = std::chrono::duration<double>(timeDiff).count();
    std::cout << ANSI_COLOR_GREEN << msg << " took: " << ANSI_COLOR_BOLD << timeDiffSeconds << ANSI_COLOR_RESET << ANSI_COLOR_GREEN << " seconds \n" << ANSI_COLOR_RESET;
}

std::vector<double> getNextImageArray(std::ifstream& inputFile, std::string file) {
    Matrix m(file);
    mapMatrix(&m, 0, 1);
    return m.toSingleDimension();
}

bool startsWith(const std::string& fullString, const std::string& start) {
    return fullString.rfind(start, 0) == 0;
}

std::vector<double> getTarget(std::string filename) {
    if (startsWith(filename, "triangle")) {
        return triangleOutput;
    } else if (startsWith(filename, "rectangle")) {
        return rectangleOutput;
    } else if (startsWith(filename, "ellipse")) {
        return ellipsOutput;
    } else if (startsWith(filename, "other")) {
        return otherOutput;
    }
    return std::vector<double>(0);
}

int main() {
    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point sstart_time = std::chrono::system_clock::now();

    std::cout << ANSI_COLOR_BLUE << "starting... \n" << ANSI_COLOR_RESET;

    std::cout << "image name:";
    std::string filename;
    getline(std::cin, filename);

    setup();

    std::cout << ANSI_COLOR_BLUE << "loading image....\n" << ANSI_COLOR_RESET;
    Matrix* imageMatrix;
    imageMatrix = new Matrix(filename);
    std::vector<double> singleDimensionalImage = imageMatrix->toSingleDimension();

    printTimeDiff(start_time, "finished loading image");

    /*  FIRST LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << ANSI_COLOR_BLUE << "loading first layer weights...\n" << ANSI_COLOR_RESET;

    int firstLayer_weightsPerNeuron = singleDimensionalImage.size();
    std::vector<Neuron>* firstLayer_neurons = loadNeuronWeightsFromFile(FIRSTLAYER_WEIGHTS_FILENAME, 490, firstLayer_weightsPerNeuron, 0, 0.1);

    printTimeDiff(start_time, "finished loading first layer weights");

    /*  SECOND LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << ANSI_COLOR_BLUE << "loading second layer weights...\n" << ANSI_COLOR_RESET;

    int secondLayer_weightsPerNeuron = firstLayer_neurons->size();
    std::vector<Neuron>* secondLayer_neurons = loadNeuronWeightsFromFile(SECONDLAYER_WEIGHTS_FILENAME, 490, secondLayer_weightsPerNeuron, 0, 0.1);

    printTimeDiff(start_time, "finished loading second layer weights");

    /* OUTPUT LAYER WEIGHTS SETUP */
    start_time = std::chrono::system_clock::now();
    std::cout << ANSI_COLOR_BLUE << "loading output layer weights...\n" << ANSI_COLOR_RESET;

    int outputLayer_weightsPerNeuron = secondLayer_neurons->size();
    std::vector<Neuron>* outputLayer_neurons = loadNeuronWeightsFromFile(OUTPUT_WEIGHTS_FILENAME, 4, outputLayer_weightsPerNeuron, 0, 0.1);

    printTimeDiff(start_time, "finished loading output layer weights");

    std::vector<double> firstLayer_values;
    std::vector<double> secondLayer_values;
    std::vector<double> outputLayer_values;

    for (int i = 0; i < firstLayer_neurons->size(); i++) {
        firstLayer_values.insert(firstLayer_values.end(), forwardPropagation(singleDimensionalImage, firstLayer_neurons->at(i).weights));
    }

    for (int i = 0; i < secondLayer_neurons->size(); i++) {
        secondLayer_values.insert(secondLayer_values.end(), forwardPropagation(firstLayer_values, secondLayer_neurons->at(i).weights));
    }

    for (int i = 0; i < outputLayer_neurons->size(); i++) {
        outputLayer_values.insert(outputLayer_values.end(), forwardPropagation(secondLayer_values, outputLayer_neurons->at(i).weights));
    }

    std::cout << filename << "\n";
    std::cout << outputLayer_values[0] << " other\n";
    std::cout << outputLayer_values[1] << " rectangle\n";
    std::cout << outputLayer_values[2] << " ellipse\n";
    std::cout << outputLayer_values[3] << " triangle\n";

    int biggest = 0;
    for (int i = 0; i < outputLayer_values.size(); i++) {
        if (outputLayer_values[i] > outputLayer_values[biggest]) {
            biggest = i;
        }
    }

    std::cout << "This is most likely a: ";
    if (biggest == 0) {
        std::cout << "Other \n";
    } else if (biggest == 1) {
        std::cout << "Rectangle \n";
    } else if (biggest == 2) {
        std::cout << "Ellipse \n";
    } else if (biggest == 3) {
        std::cout << "Triangle \n";
    }

    delete firstLayer_neurons;
    delete outputLayer_neurons;
    delete secondLayer_neurons;
    delete imageMatrix;

    printTimeDiff(sstart_time, "full executing took");

    return 0;
}

