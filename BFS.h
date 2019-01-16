
#ifndef CLIENT_SERVER_BFS_H
#define CLIENT_SERVER_BFS_H

#include "ISearcher.h"
#include <list>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

template<class Node>
class BFS : public ISearcher<Node> {
    int count = 0;

public:
    /**
     * The algorithm
     * @param searchable
     * @return
     */
    std::vector<State<Node> *> search(Searchable<Node> *searchable) override {
        std::vector<State<Node> *> return_val;
        // get the initial node
        State<Node> *node = searchable->getInitialState();
        State<Node> *second_node, *save;
        // create a queue for the algorithm
        list<State<Node> *> queue;
        vector<State<Node> *> possible_states;
        // mark the current node as visited
        node->setVisited(true);
        // enqueue the node
        queue.push_back(node);
        while (!queue.empty()) {
            // Dequeue a vertex from queue
            node = queue.front();
            queue.pop_front();
            possible_states = searchable->getAllPossibleStates(node);
            this->count++;
            for (int i = 0; i < possible_states.size(); i++) {
                second_node = possible_states[i];
                if (!second_node->isVisited()) {
                    second_node->setVisited(true);
                    second_node->setComeFrom(node);
                    second_node->setCost(node->getCost() + second_node->getCost());
                    queue.push_back(second_node);
                }
                if (second_node->getState() == searchable->getGoalNode()) {
                    save = second_node;
                    return return_val = {save};
                }
            }
        }
        return return_val = {save};
    }

    /**
     * Getter of the number of nodes that evaluated
     * @return the number
     */
    int getNumberOfNodesEvaluated() override {
        return this->count;
    }
};

#endif //CLIENT_SERVER_BFS_H
