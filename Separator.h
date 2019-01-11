//
// Created by gideon on 08/01/19.
//

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
    void valueParser(string& strData, string strSpliter);
    Matrix* matrixCreator();
};

#endif //CLIENT_SERVER_SEPARATER_H