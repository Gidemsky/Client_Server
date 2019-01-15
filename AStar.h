//
// Created by benda on 12/01/19.
//

#ifndef CLIENT_SERVER_ASTAR_H
#define CLIENT_SERVER_ASTAR_H

#include "ISearcher.h"
#include "SearchableMatrix.h"
#include <map>
#include <stdlib.h>

using namespace std;

template<class Node>
class AStar : public ISearcher<Node> {
    class StateCompare {
    public:
        bool operator()(State<Node> *left, State<Node> *right) {
            return left->getCost() < right->getCost();
        }
    };
    
    using Point = pair<int, int>;
    Searchable<Node> *searchable;
    int count;

public:
    virtual vector<Node> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated();

    virtual double distance(State<Point> *start, State<Point> *goal);

};

template<class Node>
vector<Node> AStar<Node>::search(Searchable<Node> *searchable) {
    vector<State<Node>*> closed;
    vector<State<Node>*> open;
    map<State<Node>*, double> f_scores;
    map<State<Node>*, double> g_scores;
    map<State<Node>*, double> h_scores;

    // get the initial state
    State<Node> * initial_state = searchable->getInitialState();

    State<Node> * goal_state = searchable->getGoalState();

    // the cost of going from start to start  is 0
    g_scores.insert(pair<State<Node>*, double>(initial_state, 0));

    // the heuristic of the initial node
    f_scores.insert(pair<State<Node>*, double>(
            initial_state, distance(initial_state, goal_state)));

    while (open.size() > 0) {
        auto top_itr = min_element(open.begin(), open.end(), StateCompare());
        auto top = *top_itr;
        open.erase(top_itr);

        closed.push_back(top);

        if (top->getState() == searchable->getGoalNode()) {
            return {top};
        }

        auto *mat = dynamic_cast<SearchableMatrix *>(searchable);

        for (State<Node> *&neighbor : mat->getAllPossibleStates(top, 3)) {
            neighbor->setComeFrom(top);
            neighbor->setCost(neighbor->getCost() + top->getCost());


            if (find_if(closed.begin(), closed.end(), [neighbor](auto ptr) {
                return ptr->getState() == neighbor->getState();
            }) != closed.end()) {
                continue;
            }

            auto itr = find_if(open.begin(), open.end(), [neighbor](auto ptr) {
                return ptr->getState() == neighbor->getState();
            });

            if (itr != open.end()) {
                (*itr)->setCost(min((*itr)->getCost(), top->getCost() + (*itr)->getCost()));
            } else {
                open.push_back(neighbor);
            }
        }
    }
    return {};

}

template<class Node>
int AStar<Node>::getNumberOfNodesEvaluated() {
    return this->count;
}

template <class Point>
double distance(State<Point> *start, State<Point> *goal) {
    int x = abs(start->getState().first - goal->getState().first);
    int y = abs(start->getState().second - goal->getState().second);
    return x + y;
}

#endif //CLIENT_SERVER_ASTAR_H
