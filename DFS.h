//
// Created by benda on 10/01/19.
//

#ifndef CLIENT_SERVER_DFS_H
#define CLIENT_SERVER_DFS_H

#include "ISearcher.h"
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <class Node>
class DFS : public ISearcher<Node> {
    int count;

public:
    DFS() {
        this->count = 0;
    }

    /**
     * The algorithm
     * @param searchable
     * @return
     */
    std::vector<State<Node> *> search (Searchable<Node>* searchable) override {
        std::vector<State<Node> *> return_val;
        stack<State<Node>*> stack;
        // get the initial state
        State<Node>* node = searchable->getInitialState();
        stack.push(node);
        // get all adjacent vertices of the initial state
        vector<State<Node>*> possible_states;
        State<Node>* second_node, *save;
        save = nullptr;
        while (!stack.empty()) {
            node = stack.top();
            stack.pop();

            if (!node->isVisited()) {
                node->setVisited(true);
            }
            possible_states = searchable->getAllPossibleStates(node);
            for (int i = 0; i < possible_states.size(); i++) {
                second_node = possible_states[i];
                if (!second_node->isVisited()) {
                    second_node->setComeFrom(node);
                    stack.push(second_node);
                    this->count++;
                }

                if (second_node->getState() == searchable->getGoalNode()) {
                    save = second_node;
                }
            }
        }
        return_val.push_back(save);
        return return_val;
    }

    /**
     * Getter of the number of nodes that evaluated.
     * @return the counter.
     */
    int getNumberOfNodesEvaluated() override {
        return this->count;
    }

};

#endif //CLIENT_SERVER_DFS_H
