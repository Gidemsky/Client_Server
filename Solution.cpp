
#include <algorithm>
#include "Solution.h"

Solution::Solution(vector<State<Point> *> vec) {
    this->path_vector = vec;
}

string Solution::makeString() {
    return this->getPath();
}

string Solution::getPath() {
    vector<State<Point> *> points;
    // creates all-in-one vector of the points
    while (this->path_vector.front()->getComeFrom() != nullptr) {
        points.push_back(this->path_vector.front());
        this->path_vector[0] = this->path_vector.front()->getComeFrom();
    }
    // adds the last one to the vector
    points.push_back(this->path_vector.front());
    reverse(points.begin(), points.end());
    string path = "";
    // prints the path with the keys: "Up\Down\Left\Right"
    for (int i = 0; i < points.size() - 1; ++i) {
        int i1 = points.at(i)->getState().first;
        int j1 = points.at(i)->getState().second;
        int i2 = points.at(i + 1)->getState().first;
        int j2 = points.at(i + 1)->getState().second;
        if ((i1 == i2) && (j1 == (j2 + 1))) {
            path += "Left,";
        } else if ((i1 == i2) && (j1 == (j2 - 1))) {
            path += "Right,";
        } else if ((i1 == (i2 + 1)) && (j1 == j2)) {
            path += "Up,";
        } else if ((i1 == (i2 - 1)) && (j1 == j2)) {
            path += "Down,";
        }
    }
    return path;
}