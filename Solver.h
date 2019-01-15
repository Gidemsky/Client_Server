
#ifndef CLIENT_SERVER_SOLVER_H
#define CLIENT_SERVER_SOLVER_H

template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};

#endif //CLIENT_SERVER_SOLVER_H
