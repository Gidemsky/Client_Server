//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MATRRIX_H
#define CLIENT_SERVER_MATRRIX_H

#include <vector>
//#include "SearchableMatrix.h"

class Matrix {
    int row,col;
    using MatrixVec = std::vector<std::vector<double>>;
    MatrixVec _data ;
    std::pair<int,int> p_start, p_goal;
public:
    const MatrixVec &get_data() const {
        return _data;
    }

    const std::pair<int, int> &getP_start() const {
        return p_start;
    }

    const std::pair<int, int> &getP_goal() const {
        return p_goal;
    }
    using Point = std::pair<int, int>;

    Matrix(const MatrixVec& vec) {//added  "explicit" check what
        this->_data = vec;
        setPointPairs();
        this->row = static_cast<int>(_data.size());
        this->col = static_cast<int>(_data.front().size());
    }

    Matrix() {}

    void setPointPairs(){
        std::vector<double> point_val = this->_data.back();
        int x = static_cast<int>(point_val[0]);
        int y = static_cast<int>(point_val[1]);
        this->_data.pop_back();
        this->p_goal.first = x;
        this->p_goal.second = y;
        point_val = this->_data.back();
        x = static_cast<int>(point_val[0]);
        y = static_cast<int>(point_val[1]);
        this->_data.pop_back();
        this->p_start.first = x;
        this->p_start.second = y;
    }

    double& operator[](const Point& p)  {
        return _data[p.first][p.second];
    }

    double operator[](const Point& p) const {
        return _data[p.first][p.second];
    }

    int getRow(){
        return this->row;
    }

    int getCol(){
        return this->col;
    }

//    SearchableMatrix create(){
//        return new SearchableMatrix(this->_data, this->p_start, this->p_goal);
//    }
};

#endif //CLIENT_SERVER_MATRRIX_H
