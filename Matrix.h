//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MATRRIX_H
#define CLIENT_SERVER_MATRRIX_H

#include "Searchable.h"
#include <vector>

class Matrix {
    int row,col;
    using MatrixVec = std::vector<std::vector<double>> ;
    MatrixVec _data ;
    std::pair<int,int> p_start, p_goal;

public:
    using Point = std::pair<int, int>;

    explicit Matrix(const MatrixVec& vec) {//added  "explicit" check what
        this->_data = vec;
        this->row = static_cast<int>(_data.size());
        this->col = static_cast<int>(_data.front().size());
        setPointPairs(this->_data);
    }

    void setPointPairs(MatrixVec mat_vac){
        std::vector<double> point_val = mat_vac.back();
        int x = static_cast<int>(point_val[0]);
        int y = static_cast<int>(point_val[1]);
        this->_data.pop_back();
        this->p_goal.first = x;
        this->p_goal.second = y;
        point_val = mat_vac.back();
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
};

class SearchableMatrix : public Searchable<std::pair<int, int>>
{
    using Point = std::pair<int, int>;
    Matrix matrix;
    Point entry_point;
    Point exit_point;
    //int row_lenght, col_lenght;TODO: check if needed
public:
    SearchableMatrix(const Matrix &matrix, Point entry, Point exit) : matrix(matrix) {
        this->matrix = matrix;
        this->entry_point = entry;
        this->exit_point = exit;
    }
    State<Point> getInitialState() const override {
        State<Point> initial_state;
        initial_state.setComeFrom(nullptr);
        initial_state.setCost(matrix[entry_point]);
        initial_state.setState(entry_point);
    }

    Point getInitialNode() const override {
        return entry_point;
    }

    Point getGoalNode() const override {
        return exit_point;
    }
    std::vector<State<Point>> getAllPossibleStates(State<Point> mat_state) {
        std::vector<State<Point>> pos_states;

        Point exam_possible_point;

        int x_pos = mat_state.getState().first;
        int y_pos = mat_state.getState().second;

        int last_x_pos = matrix.getRow();
        int last_y_pos = matrix.getCol();

        //if it is possible to return current y position on the above row
        //TODO: check the margins of the matrix
        if (x_pos > 0) {
            exam_possible_point = Point(x_pos - 1,y_pos);
            if(matrix[exam_possible_point]>=0){
                //pos_states.emplace_back(new State<Point>(exam_possible_point,this->matrix[exam_possible_point]));
            }
        }

        //next row
        if (x_pos < last_x_pos) {
            exam_possible_point = Point(x_pos + 1,y_pos);
            if(matrix[exam_possible_point]>=0){
                //pos_states.emplace_back(new State<Point>(exam_possible_point,this->matrix[exam_possible_point]));
            }
        }

        //prev col
        if (y_pos > 0) {
            exam_possible_point = Point(x_pos,y_pos - 1);
            if(matrix[exam_possible_point]>=0){
                //pos_states.emplace_back(new State<Point>(exam_possible_point,this->matrix[exam_possible_point]));
            }
        }

        //next col
        if (y_pos < last_y_pos) {
            exam_possible_point = Point(x_pos,y_pos + 1);
            if(matrix[exam_possible_point]>=0){
                //pos_states.emplace_back(new State<Point>(exam_possible_point,this->matrix[exam_possible_point]));
            }
        }
        return pos_states;

    }

    int size(){
        return (matrix.getRow()*matrix.getCol());
    }
};

#endif //CLIENT_SERVER_MATRRIX_H
