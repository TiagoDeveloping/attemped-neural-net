#ifndef UTIL_HPP
#define UTIL_HPP

#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Matrix.hpp"

void map(double min, double max, double* val);
void mapMatrix(Matrix* matrix, double mapMin, double mapMax);


#endif