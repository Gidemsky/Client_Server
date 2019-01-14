//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MYCLIENTHANDLER_H
#define CLIENT_SERVER_MYCLIENTHANDLER_H

#include <unistd.h>
#include "IClientHandler.h"
#include "Stringable.h"
#include "Solver.h"
#include "ICacheManager.h"

class ClientHandler : public IClientHandler {
    Solver<string, string> *solver;
    ICacheManager<Stringable, Stringable> *cacheManager;
public:
    ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger)
    {

    }

    string solveProblem(string &problem);

    void handleClient(int sock) override;
};


#endif //CLIENT_SERVER_MYCLIENTHANDLER_H
