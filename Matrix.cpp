//
// Created by gideon on 08/01/19.
//

#include "Matrix.h"

//const int INITIAL_ROW = 0;
//const int INITIAL_COL = 0;
////State<Point> Matrix::getInitialState()const {
////    size_t rowSize = _data.size();
////    if(rowSize>0){
////        return _data[INITIAL_ROW][INITIAL_COL];
////    }else{
////        throw "Matrix is empty";
////    }}
////
////State<T> Matrix::getGoalState()const {
////    size_t rowSize = _data.size();
////    if(rowSize>0){
////        size_t colSize = _data[INITIAL_ROW].size();
////        return _data[rowSize][colSize];
////    }else{
////        throw "Matrix is empty";
////    }
////}
//
//std::vector <State<Node>> Matrix::getAllPossibleStates(State<Point> state)
//const {
//
//    std::vector <State<Point>> pos_states ;
//    //current coordinates
//    int cur_x_pos = state.get_state().get_x();
//    int cur_y_pos = state.get_state().get_y();
//    //last coordinates in matrix
//    //TODO CHECK IF IT IS NEEDED TO GET LAST COORDINATES OF CURRENT POSITION
//    int last_x_pos = getGoalState().get_state().get_x();
//    int last_y_pos = getGoalState().get_state().get_y();
//    //if it is possible to return current y position on the above row
//    if(cur_x_pos > INITIAL_ROW){
//        pos_states.push_back(_data[cur_x_pos-1][cur_y_pos]);
//    }
//    //next row
//    if(cur_x_pos < last_x_pos){
//        pos_states.push_back(_data[cur_x_pos+1][cur_y_pos]);
//
//    }
//    //prev col
//    if(cur_y_pos > INITIAL_COL){
//        pos_states.push_back(_data[cur_x_pos][cur_y_pos-1]);
//    }
//    //next col
//    if(cur_y_pos < last_y_pos){
//        pos_states.push_back(_data[cur_x_pos][cur_y_pos+1]);
//
//    }
//    return pos_states;
//}
