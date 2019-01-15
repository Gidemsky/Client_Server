
#include "Separator.h"
#include <algorithm>
#include <list>

#define VAL_SPLITER ","
#define LINE_CLIENT_SPLITER "\n"

/**
 * Ctor
 * @param userFileName
 */
Separator::Separator(string user_input) {
    this->user_input = user_input;
}

void Separator::valueParser(string &str_data, string spliter) {
    vector<double> line_vals;
    string lineData = str_data;
    size_t pos = 0;
    string source;
    if (spliter == LINE_CLIENT_SPLITER) {
        while ((pos = lineData.find(spliter)) != string::npos) {
            source = lineData.substr(0, pos);
            valueParser(source, VAL_SPLITER);
            lineData.erase(0, pos + 1);
        }
    } else {
        while ((pos = lineData.find(spliter)) != string::npos) {
            source = lineData.substr(0, pos);
            line_vals.push_back(stod(source));
            lineData.erase(0, pos + 1);
        }
        source = lineData.substr(0, pos);
        if (source != "end") {
            line_vals.push_back(stod(source));
            this->mat_assigned_data.push_back(line_vals);
        }
    }
}

Matrix *Separator::matrixCreator() {
    valueParser(this->user_input, LINE_CLIENT_SPLITER);
    return new Matrix(this->mat_assigned_data);
}
