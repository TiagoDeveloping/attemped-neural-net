#include "Util.hpp"

/**
 * @brief Maps a value(val) from a set to a value between max and min
 * 
 * @note will probably crash when val < min, so should be avoided
 * 
 * @param min min interval value
 * @param max max interval value
 * @param val value to be mapped
 */
void map(double min, double max, double* val) {
    *(val) = ( ( (*val) - min ) / ( max - min ) );
}

/**
 * @brief Maps a matrix to values between mapMin and mapMax
 * 
 * @param matrix matrix
 * @param mapMin min
 * @param mapMax max
 */
void mapMatrix(Matrix* matrix, double mapMin, double mapMax) {
    double* range = matrix->range();

    double factor = (mapMax - mapMin) / (*range);
// ( 60 - -15 ) * ((1-0)/(80--15))
    for (int y = 0; y < matrix->dimensions(); y++) {
        for (int x = 0; x < matrix->dimensions(); x++) {
            double oldValue = matrix->get(x, y);
            double newValue = (oldValue - (*(matrix->min))) * factor;
            matrix->put(x, y, newValue);
        }
    }

    delete range;
}

/**
 * @brief retrieves double arrays from file
 * 
 * @param filename 
 * @return StringMatrixMap
 */
StringMatrixMap loadMatricesFromFile(std::string& filename) {
    StringMatrixMap result;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return result; // Return an empty map if the file cannot be opened
    }

    std::string key;
    std::vector<std::vector<double> > data;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        if (line[0] == '\t') {
            // Assuming lines starting with a tab character '\t' indicate data lines
            std::vector<double> row;
            double value;
            std::istringstream ss(line);

            while (ss >> value) {
                row.push_back(value);
            }

            data.push_back(row);
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

    file.close();
    return result;
}

/**
 * @brief saves doubel arrays to file
 * 
 * @param filename 
 * @param data StringMatrixMap = std::map<std::string, std::vector<std::vector<double> > >
 */
void writeMatricesToFile(const std::string& filename, const StringMatrixMap& data) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : data) {
            file << entry.first << "\n";

            for (const auto& innerVec : entry.second) {
                file << "\t";
                for (const double& value : innerVec) {
                    file << value << ' ';
                }
                file << '\n';
            }
        }
        file.close();
        std::cout << "Data written to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

void printStringMatrixMap(StringMatrixMap map) {
    for (const auto& entry : map) {
        std::cout << "Key: " << entry.first << std::endl;
        for (const auto& vector : entry.second) {
            for (const double value : vector) {
                std::cout << value << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}