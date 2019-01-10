//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SEPARATER_H
#define CLIENT_SERVER_SEPARATER_H

#include <algorithm>
#include <list>
#include "string"
#include "fstream"
#include <vector>

using namespace std;

class Separator {
    string user_input;
    vector<vector<double>> mat_assigned_data;
    int mat_length, mat_width;
public:
    Separator(string user_input);
    //vector<vector<double>> stringConverter(vector<string> vec_line, string split);
    void valueParser(string& strData, string strSpliter);
};

#endif //CLIENT_SERVER_SEPARATER_H