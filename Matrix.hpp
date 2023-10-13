#ifndef MATRIX_CLASS_HPP
#define MATRIX_CLASS_HPP

#include "stb_image.h"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <map>

class Matrix {
    public:
        /**
         * @brief Construct a new Matrix:: Matrix object
         * 
         * @note only double values can be assigned
         * 
         * @param x max x of matrix
         * @param y max y of matrix
         */
        inline Matrix(int size): size(size) {
            matrix.resize(size, std::vector<double>(size, 0));
            min = new double;
            *min = 0;
            max = new double;
            *max = 0;
        }
        
        /**
         * @brief Construct a new Matrix object
         * 
         * @param size size
         * @param input very simple representation of matrix
         */
        inline Matrix(int size, std::string input): size(size) {
            matrix.resize(size, std::vector<double>(size, 0));
            min = new double;
            *min = 0;
            max = new double;
            *max = 0;

            for (int y = 0; y < size; y++) {
                for (int x = 0; x < size; x++) {
                    put(x, y, std::stod(input.substr((y * (size)) + x, 1)));
                }
            }

        }

        inline Matrix(std::string image) {
            size = 0;

            int width, height, channels;
            unsigned char *image_data = stbi_load(image.data(), &width, &height, &channels, 1); // 1 channel -> grayscale

            if (image_data == nullptr) {
                throw std::runtime_error("Failed to load the image!");
            }

            if (height != width) {
                stbi_image_free(image_data);
                delete this;
                throw std::runtime_error("Image must be square!");
            }

            size = width;

            matrix.resize(size, std::vector<double>(size, 0));
            min = new double;
            *min = 0;
            max = new double;
            *max = 0;

            unsigned char grayscaleValue = image_data[0];
            double grayscaleDouble = 0;

            for (int y = 0; y < size; y++) {
                for (int x = 0; x < size; x++) {
                    grayscaleValue = image_data[y * size + x];
                    grayscaleDouble = static_cast<double>(grayscaleValue);
                    put(x, y, grayscaleDouble);
                }
            }

            stbi_image_free(image_data);
        }

        /**
         * @brief Construct a new Matrix object from std::vector<std::vector<double> >
         * 
         * @param mat std::vector<std::vector<double> >
         */
        inline Matrix(std::vector<std::vector<double> >& mat) {
            size = mat.size();
            matrix.resize(size, std::vector<double>(size, 0));
            min = new double;
            *min = 0;
            max = new double;
            *max = 0;

            for (int y = 0; y < size; y++) {
                for (int x = 0; x < size; x++) {
                    matrix[y][x] = mat[y][x];
                }
            }
        }

        double get(int x, int y);
        void put(int x, int y, double val);

        std::vector<double> toSingleDimension();

        int dimensions();
        double* range();
        void addToMap(std::string key, std::map<std::string, std::vector<std::vector<double> > >* map);

        void subMatrix(Matrix* matrix, int fromx, int tox, int fromy, int toy);

        void resize(int size);
        void inverse();

        void prettyPrint();

        double* max;
        double* min;

        ~Matrix() {
            matrix.clear();
            delete max;
            delete min;
        }
    private:
        size_t size;
        std::vector<std::vector<double> > matrix;
};

#endif