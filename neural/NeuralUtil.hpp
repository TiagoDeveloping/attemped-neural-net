#ifndef NEURAL_UTIL_HPP
#define NEURAL_UTIL_HPP

#include <vector>

inline double ReLU(double value) {
    if (value < 0) {
        return 0;
    } else {
        return value;
    }
};

#endif