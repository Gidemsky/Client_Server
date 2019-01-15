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
#include "Searchable.h"

class ClientHandler : public IClientHandler {

    Solver<Searchable<std::pair<int,int>>* , std::vector <State<std::pair<int,int>*>>> *solver;
    ICacheManager<Stringable, Stringable> *cacheManager;
public:
    ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger);

    ICacheManager<Stringable, Stringable> *getCacheManager() const;

    string solveProblem(string &problem);

    void handleClient(int sock) override;
};


#endif //CLIENT_SERVER_MYCLIENTHANDLER_H
