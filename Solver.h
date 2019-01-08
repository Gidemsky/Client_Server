//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SOLVER_H
#define CLIENT_SERVER_SOLVER_H

template <class Problem, class Solution>
class Solver{
    virtual Solution solve(Problem) = 0;

};

#endif //CLIENT_SERVER_SOLVER_H
