#include <iostream>
#include <stdexcept>

#include "Neural.hpp"
#include "../Matrix.hpp"
#include "Weights.hpp"

double relu_derivative(double x) {
    if (x > 0) {
        return 1.0; // The derivative of ReLU when x > 0 is 1.
    } else {
        return 0.0; // The derivative of ReLU when x <= 0 is 0.
    }
}
double sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

/**
 * @brief back propagation
 * 
 * @param hiddenLayer1_neurons 
 * @param hiddenLayer2_neurons 
 * @param outputLayer_neurons 
 * @param hiddenLayer1_values 
 * @param hiddenLayer2_values 
 * @param outputLayer_values 
 * @param input 
 * @param target 
 */
void backwardPropagation(
    std::vector<Neuron>* hiddenLayer1_neurons,
    std::vector<Neuron>* hiddenLayer2_neurons,
    std::vector<Neuron>* outputLayer_neurons,
    std::vector<double>& hiddenLayer1_values,
    std::vector<double>& hiddenLayer2_values,
    std::vector<double>& outputLayer_values,
    std::vector<double>& input,
    std::vector<double>& target
) {
    // output layer errors
    int outputSize = outputLayer_values.size();
    std::vector<double> output_errors(outputSize);
    for (int i = 0; i < outputSize; ++i) {
        output_errors[i] = target[i] - outputLayer_values[i];
        output_errors[i] *= outputLayer_values[i] * sigmoid_derivative(outputLayer_values[i]);
    }

    // hidden layer 2 errors
    int hiddenSize2 = hiddenLayer2_values.size();
    std::vector<double> hidden_errors2(hiddenSize2);
    for (int i = 0; i < hiddenSize2; ++i) {
        hidden_errors2[i] = 0;
        for (int j = 0; j < outputSize; ++j) {
            hidden_errors2[i] += output_errors[j] * outputLayer_neurons->at(j).weights[i];
        }
        hidden_errors2[i] *= hiddenLayer2_values[i] * sigmoid_derivative(hiddenLayer2_values[i]);
    }

    // hidden layer 1 errors
    int hiddenSize1 = hiddenLayer1_values.size();
    std::vector<double> hidden_errors1(hiddenSize1);
    for (int i = 0; i < hiddenSize1; ++i) {
        hidden_errors1[i] = 0;
        for (int j = 0; j < hiddenSize2; ++j) {
            hidden_errors1[i] += hidden_errors2[j] * hiddenLayer2_neurons->at(j).weights[i];
        }
        
        hidden_errors1[i] *= hiddenLayer1_values[i] * sigmoid_derivative(hiddenLayer1_values[i]);
    }

    for (int i = 0; i < outputSize; ++i) {
        for (int j = 0; j < hiddenSize2; ++j) {
            outputLayer_neurons->at(i).weights[j] += LEARNING_RATE * output_errors[i] * hiddenLayer2_values[j];
        }
    }

    for (int i = 0; i < hiddenSize2; ++i) {
        for (int j = 0; j < hiddenSize1; ++j) {
            hiddenLayer2_neurons->at(i).weights[j] += LEARNING_RATE * hidden_errors2[i] * hiddenLayer1_values[j];
        }
    }

    for (int i = 0; i < hiddenSize1; ++i) {
        for (int j = 0; j < input.size(); ++j) {
            hiddenLayer1_neurons->at(i).weights[j] += LEARNING_RATE * hidden_errors1[i] * input[j];
        }
    }
}


/**
 * @brief Do back propagation
 * 
 * @param firstLayer_neurons:ptr neurons in first layer
 * @param outputLayer_neurons:ptr neurson in second layer
 * @param firstLayer_values values of first layer after propagation
 * @param outputLayer_values values of output layer after propagation
 * @param input input values
 * @param target target output
 */
void backwardPropagation(std::vector<Neuron>* hiddenLayer_neurons, std::vector<Neuron>* outputLayer_neurons, std::vector<double>& hiddenLayer_values, std::vector<double>& outputLayer_values, std::vector<double>& input, std::vector<double>& target) {
    int outputSize = outputLayer_values.size();
    std::vector<double> output_errors(outputSize);
    for (int i = 0; i < outputSize; ++i) {
        output_errors[i] = target[i] - outputLayer_values[i];

        output_errors[i] *= outputLayer_values[i] * sigmoid_derivative(outputLayer_values[i]);
    }

    int hiddenSize = hiddenLayer_values.size();
    std::vector<double> hidden_errors(hiddenSize);
    for (int i = 0; i < hiddenSize; ++i) {
        hidden_errors[i] = 0;
        for (int j = 0; j < outputSize; ++j) {
            // double oe = output_errors[j];
            // Neuron n = outputLayer_neurons->at(j);
            // double w = n.weights[i];
            // hidden_errors[i] += oe * w;
            hidden_errors[i] += output_errors[j] * outputLayer_neurons->at(j).weights[i];
        }
        
        hidden_errors[i] *= hiddenLayer_values[i] * sigmoid_derivative(hiddenLayer_values[i]);
    }


    for (int i = 0; i < outputSize; ++i) {
        for (int j = 0; j < hiddenSize; ++j) {
            outputLayer_neurons->at(i).weights[j] += LEARNING_RATE * output_errors[i] * hiddenLayer_values[j];
        }
    }


    for (int i = 0; i < hiddenSize; ++i) {
        for (int j = 0; j < input.size(); ++j) {
            hiddenLayer_neurons->at(i).weights[j] += LEARNING_RATE * hidden_errors[i] * input[j];
        }
    }
}

/**
 * @brief Convluates the values
 * 
 * @param input: Matrix, input matrix
 * @param kernel: Matrix, kernel matrix
 * @return ptr double convulated value
 */
double* convolute(Matrix* input, Matrix* kernel) {
    if (input->dimensions() != kernel->dimensions()) throw std::invalid_argument("input and kernel matrix should be equally sized!");
    double* val = new double;
    *val = 0;
    
    for (int y = 0; y < input->dimensions(); y++) {
        for (int x = 0; x < input->dimensions(); x++) {
            (*val) += (input->get(x, y) * kernel->get(x, y));
        }
    }
    return val;
}

double ReLU(double value) {
    if (value < 0) {
        return 0;
    } else {
        return value;
    }
}

/**
 * @brief Propegate single neuron forward.
 * 
 * @param input vector<double> of the values the neuron gets
 * @param weights weights for each input value the neuron gets
 * @return double 
 */
double forwardPropagation(const std::vector<double>& input, const Weights& weights) {
    double weighted_sum = weightedSum(input, weights);

    double output = sigmoid(weighted_sum);

    return output;
}

/**
 * @brief dot product
 * 
 * @param a first Weights obj
 * @param b second Weights obj
 * @return double 
 */
double dot(const Weights& a, const Weights& b) {
    if (a.size() != b.size()) {
        // You might want to handle this case based on your requirements.
        std::cerr << "Error: Vectors must have the same dimension for dot product." << std::endl;
        return 0.0;
    }

    double result = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

/**
 * @brief returns weighted sum
 * 
 * @param input 
 * @param weights 
 * @return double 
 */
double weightedSum(const std::vector<double>& input, const Weights& weights) {
    if (input.size() != weights.size()) {
        throw std::runtime_error("Input size does not match weight size.");
    }

    double sum = 0.0;  // The running sum
    double c = 0.0;    // The compensation for lost low-order bits

    for (size_t i = 0; i < input.size(); i++) {
        double y = input[i] * weights[i] - c;   // Corrected input
        double t = sum + y;                    // New sum
        c = (t - sum) - y;                     // Recompute compensation
        sum = t;                               // Update the sum
    }

    return sum;
}