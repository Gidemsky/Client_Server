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
//    string matrix_client_input;
//    fstream client_input_file;
public:
    Separator(string user_input);
    //vector<vector<double>> stringConverter(vector<string> vec_line, string split);
    void valueParser(string& strData, string strSpliter);
    //Separater(string userFileName);
//    string fileReader(fstream *dataFile, string& userFileName);
//    string lexer(string line, string split);
};


#endif //CLIENT_SERVER_SEPARATER_H
