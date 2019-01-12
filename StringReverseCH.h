//
// Created by gideon on 12/01/19.
//

#ifndef CLIENT_SERVER_STRINGREVERSECH_H
#define CLIENT_SERVER_STRINGREVERSECH_H

#include "ClientHandler.h"
#include "Solver.h"
#include "string"
#include "ICacheManager.h"
#include "Stringable.h"

using namespace std;

class StringReverseCH : public ClientHandler {
    Solver<string, string> *solver;
    ICacheManager<Stringable, Stringable> *cacheManager;
public:
    StringReverseCH(ICacheManager<Stringable, Stringable> *cacheManger);

    string solveProblem(string &problem);

    void handleClient(int socket) override;
};


#endif //CLIENT_SERVER_STRINGREVERSECH_H
