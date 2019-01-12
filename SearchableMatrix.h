//
// Created by gideon on 11/01/19.
//

#ifndef CLIENT_SERVER_SEARCHABLEMATRIX_H
#define CLIENT_SERVER_SEARCHABLEMATRIX_H

#include "Matrix.h"
#include "Searchable.h"

class SearchableMatrix : public Searchable<std::pair<int, int>>
{
    Matrix matrix;

    using Point = std::pair<int, int>;
    Point entry_point;
    Point exit_point;
    //State<Point> initial_state;

public:
    SearchableMatrix(Matrix matrix, Point entry, Point exit) {
        this->matrix = matrix;
        this->entry_point = entry;
        this->exit_point = exit;
    }

    State<Point> getInitialState() const override {
    State<Point> *initial_state = nullptr;
    initial_state->setComeFrom(nullptr);
    initial_state->setCost(matrix[entry_point]);
    initial_state->setState(entry_point);
    }

    Point getInitialNode() const override {
    return entry_point;
    }

    Point getGoalNode() const override {
    return exit_point;
    }

    std::vector<State<Point>*> getAllPossibleStates(State<Point> mat_state) {

        std::vector<State<Point>*> pos_states;
        Point exam_possible_point;

        int x_pos = mat_state.getState().first;
        int y_pos = mat_state.getState().second;

        int last_x_pos = matrix.getRow();
        int last_y_pos = matrix.getCol();

        State<Point> *state;

        //if it is possible to return current y position on the above row
        //TODO: check the margins of the matrix
        if (x_pos > 0) {
            exam_possible_point = Point(x_pos - 1,y_pos);
            if(matrix[exam_possible_point]>=0){
                state = new State<Point>(exam_possible_point,this->matrix[exam_possible_point]);
                pos_states.push_back(state);
            }
        }

        //next row
        if (x_pos < last_x_pos) {
            exam_possible_point = Point(x_pos + 1,y_pos);
            if(matrix[exam_possible_point]>=0){
                state = new State<Point>(exam_possible_point,this->matrix[exam_possible_point]);
                pos_states.push_back(state);
            }
        }

        //prev col
        if (y_pos > 0) {
            exam_possible_point = Point(x_pos,y_pos - 1);
            if(matrix[exam_possible_point]>=0){
                state = new State<Point>(exam_possible_point,this->matrix[exam_possible_point]);
                pos_states.push_back(state);
            }
        }

        //next col
        if (y_pos < last_y_pos) {
            exam_possible_point = Point(x_pos,y_pos + 1);
            if(matrix[exam_possible_point]>=0){
                state = new State<Point>(exam_possible_point,this->matrix[exam_possible_point]);
                pos_states.push_back(state);
            }
        }
        return pos_states;
    }

//    int size(){
//        return (matrix.getRow()*matrix.getCol());
//    }
};

#endif //CLIENT_SERVER_SEARCHABLEMATRIX_H
