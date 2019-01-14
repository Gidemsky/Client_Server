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
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

template<class Node>

class BestFirstSearch : public ISearcher<Node> {

    class StateCompare {
    public:
        bool operator()(State<Node> *left, State<Node> *right) {
            return (left->getShortestPathVal() > right->getShortestPathVal());
        }
    };

    int count = 0;
    vector<State<Node>*> saveValues;
    vector<State<Node>*> closed;
    vector<State<Node>*> temp;

    priority_queue<State<Node>*, vector<State<Node>*>, StateCompare> openList;

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

    void addToOpenList(State<Node>* state);
    int OpenListSize();
    virtual State<Node>* popOpenList();
    bool openContaines(State<Node>*);
    State<Node>* bringContaines(State<Node>* state);
};

template<class Node>
/**
 * The algorithm
 * @tparam Node
 * @param searchable
 * @return
 */
vector<State<Node> *> BestFirstSearch<Node>::search(Searchable<Node> *searchable) {
    State<Node>* saveMyVal;
    State<Node>* chekMyVal;
    addToOpenList(searchable->getInitialState());
    while (OpenListSize() > 0) {
        State<Node>* n = popOpenList(); // inherited from Searcher, removes the best state
        closed.push_back(n);
        //calling the delegated method, returns a list of states with n as a parent
        vector<State<Node> *> succerssors = searchable->getAllPossibleStates(n);
        typename vector<State<Node>*>::iterator it;

        for (it = succerssors.begin(); it != succerssors.end(); ++it) {

            auto itClosed = find(closed.begin(), closed.end(), it.operator*());

            if ((itClosed == closed.end()) && !openContaines(it.operator*())) {
                // s.setComeFrom(n); // already done by getSuccessors

                it.operator*()->setShortestPathVal(it.operator*()->getComeFrom()->getShortestPathVal()+it.operator*()->getCost());
                addToOpenList(it.operator*());
            } else {
                double compareNode;
                if(it.operator*()->getComeFrom()== NULL){
                    compareNode = it.operator*()->getCost();
                }else{
                    compareNode = it.operator*()->getComeFrom()->getShortestPathVal() + it.operator*()->getCost();
                }
                chekMyVal = bringContaines(it.operator*());
                if (chekMyVal != nullptr) {
                    if (compareNode < chekMyVal->getCost()) {
                        while (!(*openList.top() == it.operator*())) {
                            temp.push_back(popOpenList());
                        }
                        saveMyVal = openList.top();
                        openList.pop();
                        saveMyVal->setShortestPathVal(compareNode);
                        saveMyVal->setComeFrom(it.operator*()->getComeFrom());
                        addToOpenList(saveMyVal);
                        while (!temp.empty()){
                            addToOpenList(temp.back());
                            temp.pop_back();
                        }
                    }
                }
            }
        }
    }
}

template <class Node>
void BestFirstSearch<Node>:: addToOpenList(State<Node>* state){
    openList.push(state);
    saveValues.push_back(state);
    this->count++;
}

template <class Node>
int BestFirstSearch<Node>:: OpenListSize(){
    openList.size();
}

template <class Node>
State<Node>* BestFirstSearch<Node>:: popOpenList(){
    State<Node>* top = openList.top();
    openList.pop();
    auto it = saveValues.begin();
    for(it; it != saveValues.end(); ++it){
        if(top == (*it)){
            saveValues.erase(it);
            break;
        }
    }
    return top;
}



template <class Node>
bool BestFirstSearch<Node>::openContaines(State<Node>* state){
    auto iterator = find(saveValues.begin(), saveValues.end(),state);
    if(iterator == saveValues.end()){
        return false;
    } else {
        return true;
    }
}

template <class Node>
State<Node>* BestFirstSearch<Node>::bringContaines(State<Node>* state){
    auto iterator = find(saveValues.begin(), saveValues.end(),state);
    if(iterator == saveValues.end()){
        return nullptr;
    } else {
        return *iterator;
    }
}

#endif //CLIENT_SERVER_BREADTHFIRSTSEARCH_H
