//
// Created by gideon on 11/01/19.
//

#include "StringableMatrix.h"

StringableMatrix::StringableMatrix(string mat_data){//added explicit
    this->mat_data = mat_data;
}

string StringableMatrix::makeString() {
    return this->mat_data;
}