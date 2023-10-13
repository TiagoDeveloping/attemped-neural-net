#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Weights.hpp"

/**
 * Load weights from a file.
 * @param filename The name of the file to load weights from.
 * @return A map that associates keys (integers) with single-dimensional double arrays.
 */
WeightsMap loadWeightsFromFile(const std::string& filename) {
    WeightsMap result;

    std::ifstream file(filename); 
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return result;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        int key; // Declare key here
        if (line[0] == '\t') {
            double value;
            std::istringstream ss(line);

            while (ss >> value) {
                result[key].push_back(value); // Store value in the appropriate key's vector
            }
        } else {
            try {
                key = std::stoi(line);
                result[key] = Weights(); // Initialize the key's vector
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid key format in the file." << std::endl;
            }
        }
    }

    file.close(); // Close the file
    return result;
}

/**
 * @brief Save single-dimensional double arrays to a file.
 * 
 * @param filename The name of the file to write data to.
 * @param data A map that associates keys with single-dimensional double arrays.
 */
void writeWeightsToFile(const std::string& filename, const WeightsMap& data) {
    std::ofstream file(filename); // Open the file for writing

    if (file.is_open()) {
        for (const auto& entry : data) {
            file << entry.first << "\n";

            file << "\t";

            for (const double value : entry.second) {
                file << value << ' ';
            }
            file << "\n";
        }
        file << "\n";
        file.close(); // Close the file after writing
        std::cout << "Data written to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

void printWeightsMap(const WeightsMap& map) {
    for (const auto& entry : map) {
        std::cout << "Key: " << entry.first << std::endl;
        for (const double value : entry.second) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }
}