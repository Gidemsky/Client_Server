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

public:
    std::vector<Node> search (Searchable<Node>* searchable) override
    {
        // get the initial node
        Node node = searchable->getInitialNode();
        int size = 10;
        //searchable->getInitialState();

        // create a queue for the algorithm
        list<Node> queue;

        vector<bool> visited_;
        map<Node, bool> visited;
//        // mark all the vertices as not visited
//        for (int i = 0; i < size; i++) {
//            visited.push_back(false);
//        }

        typename::list<Node>::iterator it;

        // mark the current node as visited
        visited.insert(pair<Node, bool>(node, true));
        // enqueue the node
        queue.push_back(node);

        while(!queue.empty())
        {
            // Dequeue a vertex from queue
            node = queue.front();
            queue.pop_front();
            vector <State<Node>> possible_states =
                    searchable->getAllPossibleStates();
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (int i = 0; i < possible_states.size(); i++)
            {
                node = possible_states[i].getState();

                if (!visited.get(node))
                {
                    visited.get(node)->second = true;
                    //visited[*i] = true;
                    queue.push_back(node);
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override
    {
        return 0;
    }
};

#endif //CLIENT_SERVER_BFS_H
