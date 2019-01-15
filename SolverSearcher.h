//
// Created by gideon on 08/01/19.
//

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
        //return solution->getPath(result_points);
        return solution;
    }
};

//class SolverSearcher: public Solver<Searchable<Node>* ,Stringable*>{
//public:
//    SolverSearcher(Searcher<Point>* searcher){
//        this->searcher=searcher;
//    }
//    Stringable* solve(Searchable<Point>* searchable) override{
//        return this->searcher->search( searchable);
//    }
//};

#endif //CLIENT_SERVER_SOLVERSEARCHER_H
