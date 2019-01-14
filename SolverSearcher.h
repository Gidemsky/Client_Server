//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SOLVERSEARCHER_H
#define CLIENT_SERVER_SOLVERSEARCHER_H

#include "ISearcher.h"
#include "Solver.h"
#include <string>

template <class Node>
class SolverSearcher : public Solver<class Problem, class Solution> {
private:
    ISearcher<Node>* s;
public:
    virtual std::string solve(Searchable<Node>* problem){
        return this->s->search(problem);
    }
};

#endif //CLIENT_SERVER_SOLVERSEARCHER_H
