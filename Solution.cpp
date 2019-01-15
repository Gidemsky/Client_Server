//
// Created by gideon on 15/01/19.
//

#include <algorithm>
#include "Solution.h"

Solution::Solution(vector<State<Point>> vec){
    this->path_vector=vec;
}
string Solution::makeString(){

}
string Solution::getPath(vector<State<Point>*> path_vec){
    //Up, Down, Left, Right
    //string *path = new string();
    string path;
    for (int i = 0; i < (path_vec.size() - 1); ++i) {
        int i1 = path_vec.at(i)->getState().first;
        int j1 = path_vec.at(i)->getState().second;
        int i2 = path_vec.at(i+1)->getState().first;
        int j2 = path_vec.at(i+1)->getState().second;
        if ((i1 == i2) && (j1 == (j2 + 1))) {
            path += "Right";
        } else if ((i1 == i2) && (j1 == (j2 - 1))) {
            path += "Left";
        } else if ((i1 == (i2 + 1)) && (j1 == j2)) {
            path += "Down";
        } else if ((i1 == (i2 - 1)) && (j1 == j2)) {
            path += "Up";
        }
    }
    reverse(path.begin(), path.end());
    return path;
}