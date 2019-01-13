//
// Created by gideon on 13/01/19.
//

#ifndef CLIENT_SERVER_BREADTHFIRSTSEARCH_H
#define CLIENT_SERVER_BREADTHFIRSTSEARCH_H

#include <list>
#include <algorithm>
#include "ISearcher.h"

using namespace std;
template <class Node>
class BreadthFirstSearch: public ISearcher<Node> {
private:
    int count=0;
public:

    /**
     * Ctor
     */
    BreadthFirstSearch() {
        this->count = 0;
    }

    virtual vector<State<Node>*> search (Searchable<Node>* searchable);

    virtual int getNumberOfNodesEvaluated(){
        return this->count;
    }
};


template<class Node>
vector<State<Node>*> BreadthFirstSearch<Node>::search(Searchable<Node> *searchable) {
    // Create a queue for BFS
    std::list<State<Node>*> queue;
    //vector<State<Node>> close;TODO: check if needed
    State<Node>* state = searchable->getInitialState();
    queue.push_back(state);
    state->setVisited(true);
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    typename vector<State<Node>*>::iterator i;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        state = queue.front();
        queue.pop_front();
        if(searchable->getGoalNode()==state->getState()){
            break;
        }
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        vector<State<Node>*> adj = searchable->getAllPossibleStates(state);
        for (i = adj.begin(); i != adj.end(); ++i) {
            State<Node>* nei=(*i);
            if (!nei->isVisited())
            {
                nei->setVisited(true);
                nei->setComeFrom(state);
                queue.push_back(nei);
            }
        }
    }
    //get the nodes from the goal to begin
    vector<State<Node>*> returnVal;
    State<Node>* currentState = new State<Node>(searchable->getGoalNode(),5);
    State<Node>* beginState = searchable->getInitialState();
    if(currentState->getComeFrom()==NULL){
        return returnVal;
    }
    while (!(beginState->getState() == currentState->getState())){
        returnVal.push_back(currentState);
        currentState = currentState->getComeFrom();
    }
    returnVal.push_back(searchable->getInitialState());
    std::reverse(returnVal.begin(),returnVal.end());
    //save number of nodes that evaluated
    //this->nodesEvaluated=returnVal.size();TODO:size function
    return returnVal;

}

#endif //CLIENT_SERVER_BREADTHFIRSTSEARCH_H
