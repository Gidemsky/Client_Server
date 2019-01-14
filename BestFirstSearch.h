//
// Created by gideon on 13/01/19.
//

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
    vector<State<Node> *> saveValues;
    vector<State<Node> *> closed;
    vector<State<Node> *> temp;

    vector<State<Node> *> openList;

public:

    /**
     * Ctor
     */
    BestFirstSearch() {
        this->count = 0;
    }

    virtual vector<State<Node> *> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated() {
        return this->count;
    }

    void addToOpenList(State<Node> *state){}

    int OpenListSize(){}

    virtual State<Node> *popOpenList(){}

    bool openContaines(State<Node> *){}

    State<Node> *bringContaines(State<Node> *state){}
};

template<class Node>
/**
 * The algorithm
 * @tparam Node
 * @param searchable
 * @return
 */
vector<State<Node> *> BestFirstSearch<Node>::search(Searchable<Node> *searchable) {
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

        auto * mat = dynamic_cast<SearchableMatrix *>(searchable);

        for (State<Node> *&neighbor : mat->getAllPossibleStates(top, 3)) {
            neighbor->setComeFrom(top);
            neighbor->setCost(neighbor->getCost() + top->getCost());


            if (find_if(closed.begin(), closed.end(), [neighbor](auto ptr)  {
                return ptr->getState() == neighbor->getState();
            }) != closed.end()) {
                continue;
            }

            auto itr = find_if(openList.begin(), openList.end(), [neighbor](auto ptr)    {
                return ptr->getState() == neighbor->getState();
            });

            if (itr != openList.end())  {
                (*itr)->setCost(min((*itr)->getCost(), top->getCost() + (*itr)->getCost()));
            } else{
                openList.push_back(neighbor);
            }
        }
    }
    return {};
}

//template<class Node>
//void BestFirstSearch<Node>::addToOpenList(State<Node> *state) {
//    openList.push(state);
//    saveValues.push_back(state);
//    this->count++;
//}
//
//template<class Node>
//int BestFirstSearch<Node>::OpenListSize() {
//    openList.size();
//}
//
//template<class Node>
//State<Node> *BestFirstSearch<Node>::popOpenList() {
//    State<Node> *top = openList.top();
//    openList.pop();
//    auto it = saveValues.begin();
//    for (it; it != saveValues.end(); ++it) {
//        if (top == (*it)) {
//            saveValues.erase(it);
//            break;
//        }
//    }
//    return top;
//}
//
//
//template<class Node>
//bool BestFirstSearch<Node>::openContaines(State<Node> *state) {
//    auto iterator = find(saveValues.begin(), saveValues.end(), state);
//    if (iterator == saveValues.end()) {
//        return false;
//    } else {
//        return true;
//    }
//}
//
//template<class Node>
//State<Node> *BestFirstSearch<Node>::bringContaines(State<Node> *state) {
//    auto iterator = find(saveValues.begin(), saveValues.end(), state);
//    if (iterator == saveValues.end()) {
//        return nullptr;
//    } else {
//        return *iterator;
//    }
//}

#endif //CLIENT_SERVER_BREADTHFIRSTSEARCH_H
