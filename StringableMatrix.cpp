
#include "StringableMatrix.h"

/**
 * Setter of the matrix data
 * @param mat_data
 */
StringableMatrix::StringableMatrix(string mat_data){
    this->mat_data = mat_data;
}

/**
 * Getter of the matrix string
 * @return the string
 */
string StringableMatrix::makeString() {
    return this->mat_data;
}