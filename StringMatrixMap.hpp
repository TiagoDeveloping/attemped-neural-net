#ifndef STRING_MATRIX_MAP_HPP
#define STRING_MATRIX_MAP_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef std::map<std::string, std::vector<std::vector<double> > > StringMatrixMap;

StringMatrixMap loadMatricesFromFile(std::string& filename);
void writeMatricesToFile(const std::string& filename, const StringMatrixMap& data);

void printStringMatrixMap(StringMatrixMap map);

#endif