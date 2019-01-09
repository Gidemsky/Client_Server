//
// Created by gideon on 08/01/19.
//

#include "Separator.h"

#include <algorithm>
#include <list>

#define VAL_SPLITER ","
#define FILE_SPACE " "
#define CMD_SPLIT "#"
#define LINE_SPLITER "|"

/**
 * Ctor
 * @param userFileName
 */
Separator::Separator(string user_input) {
    this->user_input = user_input;
}

void Separator::valueParser(string& strData, string strSpliter) {
    vector<double> line_vals;
    string lineData = strData;
    size_t pos = 0;
    string unsaperated_vals;
    if (strSpliter == LINE_SPLITER) {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            unsaperated_vals = lineData.substr(0, pos);
            valueParser(unsaperated_vals, VAL_SPLITER);
            lineData.erase(0, pos + 1);
        }
        //line_vals.push_back(lineData);
        valueParser(lineData, VAL_SPLITER);
    } else {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            unsaperated_vals = lineData.substr(0, pos);
            line_vals.push_back(stod(unsaperated_vals));
            lineData.erase(0, pos + 1);
        }
        line_vals.push_back(stod(unsaperated_vals));
        this->mat_assigned_data.push_back(line_vals);
    }
}

//vector<vector<double>> Separator::stringConverter(vector<string> vec_line, string split) {
//    size_t pos = 0;
//    vector<double> dataTaken;
//    while (line.at(0) == ' ') {
//        line.erase(0, 1);
//    }
//    //run the loop as far as it has space bars
//    while ((pos = line.find(split)) != string::npos) {
//        dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
//        line.erase(0, pos + split.length());
//    }
//    dataTaken.push_back(stod(line.substr(0, pos) + SIM_INPUT_SPLIT));
//    return dataTaken;
//}
