//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SEARCHER_H
#define CLIENT_SERVER_SEARCHER_H

#include "Searchable.h"
#include "State.h"

template <class Node>
class ISearcher {
public:
    virtual std::vector <State<Node>> search (Searchable<Node>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //CLIENT_SERVER_SEARCHER_H
