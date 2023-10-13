#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Weights.hpp"

/**
 * @brief Load single-dimensional double arrays from a file and store them in a map.
 * 
 * @param filename The name of the file to load data from.
 * @return A map that associates keys (strings) with single-dimensional double arrays.
 */
WeightsMap loadWeightsFromFile(const std::string& filename) {
    WeightsMap result; // Initialize the map of weights

    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return result; // Return an empty map if the file cannot be opened
    }

    std::string key;
    Weights data; // Use the Weights type as defined in "Weights.hpp"
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        if (line[0] == '\t') {
            // Assuming lines starting with a tab character '\t' indicate data lines
            double value;
            std::istringstream ss(line);

            while (ss >> value) {
                data.push_back(value);
            }
        } else {
            if (!key.empty()) {
                result[key] = data;
            }
            key = line; // Set the new key
            data.clear(); // Clear the data for the new key
        }
    }

    if (!key.empty()) {
        result[key] = data;
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

            for (const double value : entry.second) {
                file << "\t" << value << ' ';
            }
            file << '\n';
        }
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