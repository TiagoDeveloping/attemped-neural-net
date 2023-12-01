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

