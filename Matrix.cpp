#include "Matrix.hpp"

/**
 * @brief Gets value at x, y position
 * 
 * @param x coordinate
 * @param y cooridnate
 * @return double valute at (x,y)
 */
double Matrix::get(int x, int y) {
    return matrix[y][x];
}

double* Matrix::range() {
    double* d = new double;
    *d = *max - *min;
    return d;
}

/**
 * @brief Adds to map
 * 
 * @param key 
 */
void Matrix::addToMap(std::string key, std::map<std::string, std::vector<std::vector<double> > >* map) {
    (*map)[key] = matrix;
}

/**
 * @brief Rezises matrix to size
 * 
 * @note resets all values to 0
 * 
 * @param size 
 */
void Matrix::resize(int size) {
    this->size = size;
    matrix.resize(size, std::vector<double>(size, 0));
}

/**
 * @brief assigns a sub-matrix of this to matrix
 * 
 * @note both from- and to- values are included in the submatrix
 * 
 * @param matrix matrix to be assigned
 * @param fromx
 * @param tox
 * @param fromy
 * @param toy
 */
void Matrix::subMatrix(Matrix* matrix, int fromx, int tox, int fromy, int toy) {
    int dx = tox-fromx;
    int dy = toy-fromy;

    if (dx != dy) throw std::runtime_error("Matrix must be squate");

    matrix->resize(dx + 1);

    int mx = 0;
    int my = 0;

    for (int y = fromy; y <= toy; y++) {
        for (int x = fromx; x <= tox; x++) {
            matrix->put(mx, my, get(x, y));
            mx++;
        }
        my++;
        mx=0;
    }
}

/**
 * @brief inverses(divides every value by 1)
 */
void Matrix::inverse() {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            double d = get(x,y);
            if (d==0) continue;
            put(x, y, 1/d);
        }
    }
}

/**
 * @brief Puts 'val' at (x,y)
 * 
 * @param x coordinate
 * @param y coordinate
 * @param val value to be assigned
 */
void Matrix::put(int x, int y, double val) {
    matrix[y][x] = val;
    if (val > *max) {
        *max = val;
        return;
    } else {
        if (val < *min) {
            *min = val;
            return;
        }
    }
}

/**
 * @brief Get size
 * 
 * @return int size
 */
int Matrix::dimensions() {
    return size;
}

/**
 * @brief Pretty print
 */
void Matrix::prettyPrint() {
    std::cout << "\n";
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            std::cout << matrix[y][x] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}