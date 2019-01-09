//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MATRRIX_H
#define CLIENT_SERVER_MATRRIX_H

#include "Searchable.h"
#include <vector>

class Matrix {

    using MatrixVec = std::vector<std::vector<double>> ;
public:
    using Point = std::pair<int, int>;

    Matrix(const MatrixVec& vec)    {
        this->_data = vec;
    }

    double& operator[](const Point& p)  {
        return _data[p.first][p.second];
    }

    double operator[](const Point& p) const {
        return _data[p.first][p.second];
    }

private:
    MatrixVec _data ;
};

class SearchableMatrix : public Searchable<std::pair<int, int>>
{//
    using Point = std::pair<int, int>;
    Matrix matrix;
    Point entry_point;
    Point exit_point;
public:
    State<Point> getInitialState() const override {
        State<Point> initial_state;
        initial_state.setCome_from(nullptr);
        initial_state.setCost(matrix[entry_point]);
        initial_state.setState(entry_point);
    }

    Point getInitialNode() const override {
        return entry_point;
    }

    Point getGoalNode() const override {
        return exit_point;
    }
    virtual std::vector<State<Point>> getAllPossibleStates(State<Point>) const {}
};


#endif //CLIENT_SERVER_MATRRIX_H


