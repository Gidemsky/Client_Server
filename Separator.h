
#ifndef CLIENT_SERVER_SEPARATER_H
#define CLIENT_SERVER_SEPARATER_H

#include <algorithm>
#include <list>
#include "string"
#include "fstream"
#include "Matrix.h"
#include <vector>

using namespace std;

class Separator {
    string user_input;
    vector<vector<double>> mat_assigned_data;
public:
    Separator(string user_input);

    void valueParser(string &str_data, string spliter);

    Matrix *matrixCreator();
};

#endif //CLIENT_SERVER_SEPARATER_H