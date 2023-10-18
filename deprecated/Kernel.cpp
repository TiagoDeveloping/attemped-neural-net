#include "../Matrix.hpp"
#include "Neural.hpp"

#include "Kernel.hpp"

double* Kernel::convoluteWith(Matrix* input) {
    return convolute(input, this);
}