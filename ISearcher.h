
#ifndef CLIENT_SERVER_SEARCHER_H
#define CLIENT_SERVER_SEARCHER_H

#include "Searchable.h"
#include "State.h"
#include "Stringable.h"

template<class Node>
class ISearcher {
public:
    virtual std::vector<State<Node> *> search(Searchable<Node> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //CLIENT_SERVER_SEARCHER_H
