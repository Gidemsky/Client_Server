//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_BFS_H
#define CLIENT_SERVER_BFS_H

#include "ISearcher.h"
#include <sys/socket.h>
#include <unistd.h>

struct Server
{
    char* read();
};

struct CLientHandler
{
    char input[256];
    void handle(int s)
    {
        read(s, input, 255);
    }
};

template<class Node>
class BFS : public ISearcher<Node>{
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
