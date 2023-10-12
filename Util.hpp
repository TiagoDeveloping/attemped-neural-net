#ifndef UTIL_HPP
#define UTIL_HPP

#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Matrix.hpp"

typedef std::map<std::string, std::vector<std::vector<double> > > StringMatrixMap;

void map(double min, double max, double* val);
void mapMatrix(Matrix* matrix, double mapMin, double mapMax);

StringMatrixMap loadMatricesFromFile(std::string& filename);
void writeMatricesToFile(const std::string& filename, const StringMatrixMap& data);

void printStringMatrixMap(StringMatrixMap map);

#endif