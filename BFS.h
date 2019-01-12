//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_BFS_H
#define CLIENT_SERVER_BFS_H

#include "ISearcher.h"
#include <list>
#include <map>
#include <vector>

using namespace std;

template<class Node>
class BFS : public ISearcher<Node> {
    Searchable<Node> *searchable;
    int count;

public:
    /**
     * The algorithm
     * @param searchable
     * @return
     */
    std::vector<Node> search(Searchable<Node> *searchable) override {
        // get the initial node
        State<Node> node = searchable->getInitialState();
        State<Node> second_node;
        // create a queue for the algorithm
        list<State<Node>> queue;
        vector<State<Node>> possible_states;
        // mark the current node as visited
        node.setVisited(true);
        // enqueue the node
        queue.push_back(node);

        //TODO: add solution
        while (!queue.empty()) {
            // Dequeue a vertex from queue
            node = queue.front();
            queue.pop_front();
            possible_states = searchable->getAllPossibleStates(node);
            for (int i = 0; i < possible_states.size(); i++) {
                second_node = possible_states[i];
                if (!second_node.isVisited()) {
                    second_node.setVisited(true);
                    second_node.setComeFrom(node);
                }
                if (second_node.getState() == searchable->getGoalNode()) {
                    break;
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return this->count;
    }
};

#endif //CLIENT_SERVER_BFS_H
