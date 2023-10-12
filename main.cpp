#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION

#include "Matrix.hpp"
#include "neural/Neural.hpp"
#include "neural/Kernel.hpp"
#include "Util.hpp"

#define KERNEL_DIAGONAL_LT_RB "kernel_diagonal_lt_rb"
std::string KERNELS_FILENAME = "kernels";

int main() {
    std::cout << "starting....\n";

    StringMatrixMap map = loadMatricesFromFile(KERNELS_FILENAME);

    Matrix* kernel = new Matrix(map.at("keykey"));

    kernel->prettyPrint();

    delete kernel;

    std::cout << "finished\n";

    return 0;
}