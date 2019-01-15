//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SOLVERSEARCHER_H
#define CLIENT_SERVER_SOLVERSEARCHER_H

#include "ISearcher.h"
#include "Solver.h"
#include <string>

template <class Node>
class SolverSearcher : public Solver<Searchable<Node> *, std::vector <State<Node>*>> {//class SolverSearcher : public Solver<class Problem, class Solution> {
private:
    ISearcher<Node>* s;
    int number_of_eval;
public:
    SolverSearcher(ISearcher<Node>* searcher){
        this->s=searcher;
    }

    virtual std::vector <State<Node>*> solve(Searchable<Node>* problem){
        return this->s->search(problem);
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
