
#ifndef CLIENT_SERVER_BREADTHFIRSTSEARCH_H
#define CLIENT_SERVER_BREADTHFIRSTSEARCH_H

#include <list>
#include <algorithm>
#include "ISearcher.h"
#include "Searchable.h"
#include <unordered_map>
#include "SearchableMatrix.h"
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

template<class Node>
class BestFirstSearch : public ISearcher<Node> {

    class StateCompare {
    public:
        bool operator()(State<Node> *left, State<Node> *right) {
            return left->getCost() < right->getCost();
        }
    };

    int count = 0;
    vector<State<Node> *> closed;
    vector<State<Node> *> openList;

public:

    virtual std::vector<State<Node> *> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated() {
        return this->count;
    }
};

template<class Node>
/**
 * The algorithm
 * @tparam Node
 * @param searchable
 * @return
 */
std::vector<State<Node> *> BestFirstSearch<Node>::search(Searchable<Node> *searchable) {
    closed.clear();

    openList.clear();

    openList.push_back(searchable->getInitialState());

    while (openList.size() > 0) {
        auto top_itr = min_element(openList.begin(), openList.end(), StateCompare());
        auto top = *top_itr;
        openList.erase(top_itr);

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

            auto itr = find_if(openList.begin(), openList.end(), [neighbor](auto ptr) {
                return ptr->getState() == neighbor->getState();
            });

            if (itr != openList.end()) {
                (*itr)->setCost(min((*itr)->getCost(), top->getCost() + (*itr)->getCost()));
            } else {
                openList.push_back(neighbor);
            }
        }
    }
    return {};
}

#endif //CLIENT_SERVER_BREADTHFIRSTSEARCH_H
