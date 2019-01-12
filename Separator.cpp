//
// Created by gideon on 08/01/19.
//

#include "Separator.h"

#include <algorithm>
#include <list>

#define VAL_SPLITER ","
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
        //valueParser(lineData, VAL_SPLITER);
    } else {
        while ((pos = lineData.find(strSpliter)) != string::npos) {
            unsaperated_vals = lineData.substr(0, pos);
            line_vals.push_back(stod(unsaperated_vals));
            lineData.erase(0, pos + 1);
        }
        unsaperated_vals = lineData.substr(0, pos);
        line_vals.push_back(stod(unsaperated_vals));
        this->mat_assigned_data.push_back(line_vals);
    }
}

Matrix* Separator::matrixCreator(){
    valueParser(this->user_input, LINE_SPLITER);
    return new Matrix(this->mat_assigned_data);
}

