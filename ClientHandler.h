
#ifndef CLIENT_SERVER_MYCLIENTHANDLER_H
#define CLIENT_SERVER_MYCLIENTHANDLER_H

#include <unistd.h>
#include "IClientHandler.h"
#include "Stringable.h"
#include "Solver.h"
#include "ICacheManager.h"
#include "Searchable.h"

using Point = std::pair<int, int>;

class ClientHandler : public IClientHandler {
    Solver<Searchable<Point>*, Stringable*> *solver;
    ICacheManager<Stringable, Stringable> *cacheManager;
public:
    ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger);

    ICacheManager<Stringable, Stringable> *getCacheManager();

    string solveProblem(string &problem);

    void handleClient(int sock) override;

    ~ClientHandler() {
        delete this->solver;
    }
};


#endif //CLIENT_SERVER_MYCLIENTHANDLER_H
