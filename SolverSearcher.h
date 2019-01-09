//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SOLVERSEARCHER_H
#define CLIENT_SERVER_SOLVERSEARCHER_H

#include "ISearcher.h"
#include "Solver.h"

template <class T>
class SolverSearcher : public Solver<class Problem, class Solution> {
private:
    ISearcher<T> s;

public:

};

#endif //CLIENT_SERVER_SOLVERSEARCHER_H
