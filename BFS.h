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
    Searchable<Node>* searchable;
    int count;

public:
    /**
     * The algorithm
     * @param searchable
     * @return
     */
    std::vector<Node> search (Searchable<Node>* searchable) override
    {
        // get the initial node
        State<Node> node = searchable->getInitialState();
        // create a queue for the algorithm
        list<State<Node>> queue;
        vector<State<Node>> possible_states;
        // mark the current node as visited
        node.setVisited(true);
        // enqueue the node
        queue.push_back(node);
        while(!queue.empty())
        {
            // Dequeue a vertex from queue
            node = queue.front();
            queue.pop_front();
            possible_states = searchable->getInitialState();
            for (int i = 0; i < possible_states.size(); i++)
            {
                State<Node> temp = possible_states[i];//temporary plaster
                if (temp.getCost()
            }
        }
    }

    int getNumberOfNodesEvaluated() override
    {
        return this->count;
    }
};

#endif //CLIENT_SERVER_BFS_H
