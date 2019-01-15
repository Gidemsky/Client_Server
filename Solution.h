//
// Created by gideon on 15/01/19.
//

#ifndef CLIENT_SERVER_SOLUTION_H
#define CLIENT_SERVER_SOLUTION_H


#include "ClientHandler.h"

class Solution : public Stringable{
    vector<State<Point>*> path_vector;
public:
    Solution(vector<State<Point>*> vec);
    string makeString() override;
    string getPath();
};


#endif //CLIENT_SERVER_SOLUTION_H
