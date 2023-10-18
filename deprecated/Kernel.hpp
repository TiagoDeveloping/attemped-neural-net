#ifndef KERNEL_CLASS_HPP
#define KERNEL_CLASS_HPP

#include <string>
#include <random>
#include <iostream>

#include "../Matrix.hpp"

class Kernel: public Matrix {
    public:
        inline Kernel(int size, std::string input): Matrix(size) {}
        /**
         * @brief Construct a new Kernel object with random weights
         * 
         * @param size 
         * @param b0 lower weight bound
         * @param b1 upper weight bound
         */
        inline Kernel(int size, double b0, double b1): Matrix(size) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> distribution(b0, b1); // Range from 0.0 to 1.0

            double randomValue = distribution(gen);

            for (int y = 0; y < size; y++) {
                for (int x = 0; x < size; x++) {
                    put(x,y, randomValue);
                    randomValue = distribution(gen);
                }
            }
        }

        /**
         * @brief Construct a new Kernel object from vector<vector<double>>
         * 
         * @param mat 
         */
        inline Kernel(std::vector<std::vector<double> > mat): Matrix(mat) {}

        double* convoluteWith(Matrix* input);

    private:

};

#endif