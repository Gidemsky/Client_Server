//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_BFS_H
#define CLIENT_SERVER_BFS_H

#include "ISearcher.h"
#include <sys/socket.h>
#include <unistd.h>

template<class Node>
class BFS : public ISearcher<Node> {
    Searchable<Node>* searchable;

public:
    std::vector<Node> search (Searchable<Node>* searchable) override
    {
        searchable->getInitialState();
    }

    int getNumberOfNodesEvaluated() override
    {
        return 0;
    }
};


#endif //CLIENT_SERVER_BFS_H
