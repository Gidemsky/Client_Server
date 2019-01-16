
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
            return left->getCost() + left->getHeuristic() <
                   right->getCost() + right->getHeuristic();
        }
    };
    using Point = pair<int, int>;
    Searchable<Node> *searchable;
    int count = 0;

public:
    virtual std::vector<State<Node> *> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated();

};

/**
 * The algorithm
 * @tparam Node
 * @param searchable
 * @return
 */
template<class Node>
std::vector<State<Node> *> AStar<Node>::search(Searchable<Node> *searchable) {
    vector<State<Node> *> closed;
    vector<State<Node> *> open;
    // get the initial state
    State<Node> *initial_state = searchable->getInitialState();
    open.push_back(initial_state);
    while (open.size() > 0) {
        auto top_itr = min_element(open.begin(), open.end(), StateCompare());
        auto top = *top_itr;
        open.erase(top_itr);
        closed.push_back(top);
        if (top->getState() == searchable->getGoalNode()) {
            return {top};
        }
        auto *mat = dynamic_cast<SearchableMatrix *>(searchable);
        this->count++;
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

/**
 * Getter of nodes evaluated
 * @tparam Node
 * @return
 */
template<class Node>
int AStar<Node>::getNumberOfNodesEvaluated() {
    return this->count;
}

#endif //CLIENT_SERVER_ASTAR_H
