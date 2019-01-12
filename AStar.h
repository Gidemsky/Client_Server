//
// Created by benda on 12/01/19.
//

#ifndef CLIENT_SERVER_ASTAR_H
#define CLIENT_SERVER_ASTAR_H

#include "ISearcher.h"

using namespace std;

template<class Node>
class AStar : public ISearcher<Node> {
    // members
    Searchable<Node> *searchable;
    int count;

public:
    virtual vector<Node> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated();
};

template<class Node>
vector<Node> AStar<Node>::search(Searchable<Node> *searchable) {

}

template<class Node>
int AStar<Node>::getNumberOfNodesEvaluated() {
    return this->count;
}


#endif //CLIENT_SERVER_ASTAR_H
