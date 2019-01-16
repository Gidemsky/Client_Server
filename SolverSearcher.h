
#ifndef CLIENT_SERVER_SOLVERSEARCHER_H
#define CLIENT_SERVER_SOLVERSEARCHER_H

#include "ISearcher.h"
#include "Solver.h"
#include "Stringable.h"
#include "Solution.h"
#include <string>

template <class Node>
class SolverSearcher : public Solver<Searchable<Node>*, Stringable*> {
private:
    ISearcher<Node>* s;
    int number_of_eval;
public:
    SolverSearcher(ISearcher<Node>* searcher){
        this->s=searcher;
    }

    virtual Stringable* solve(Searchable<Node>* problem){
        vector<State<Node>*> result_points;
        result_points = this->s->search(problem);
        Solution *solution = new Solution(result_points);
        return solution;
    }
};

#endif //CLIENT_SERVER_SOLVERSEARCHER_H
