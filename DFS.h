//
// Created by benda on 10/01/19.
//

#ifndef CLIENT_SERVER_DFS_H
#define CLIENT_SERVER_DFS_H

#include "ISearcher.h"
#include <map>

using namespace std;

template <class Node>
class DFS : public ISearcher<Node> {
    // members
    Searchable<Node>* searchable;
    int count;

public:


    /**
     * The algorithm
     * @param searchable
     * @return
     */
    vector<Node> search (Searchable<Node>* searchable) override {
        // number of vertices
        int size = 10; // TODO: use the relevant func to find the size
        // get the initial state
        State<Node> node = this->searchable->getInitialState();
        // help us to know if the vertex is visited
        map<State<Node>, bool> visited;
        this->dfsUtil(node, visited);
    }

    void dfsUtil(State<Node> node, map<State<Node>, bool> &visited) {
        // mark the node as visited
        visited.insert(node, true);
        vector<State<Node>> possible_states =
                this->searchable->getAllPossibleStates(node);
        for (int i = 0; i < possible_states.size(); i++) {
            if (!visited.find(possible_states[i])) {
                this->dfsUtil(possible_states[i], visited);
            }
        }
    }

    /**
     * Getter of the number of nodes that evaluated.
     * @return the counter.
     */
    int getNumberOfNodesEvaluated() override {
        return count;
    }
};

#endif //CLIENT_SERVER_DFS_H
