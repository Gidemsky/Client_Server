//
// Created by gideon on 10/01/19.
//

#ifndef CLIENT_SERVER_STRINGREVERSECH_H
#define CLIENT_SERVER_STRINGREVERSECH_H

#include "ClientHandler.h"
#include "Solver.h"
#include "string"
#include "ICacheManager.h"

class StringReverseCH : public ClientHandler {
    Solver<std::string, std::string> *solver;
    ICacheManager<std::string, std::string> *cacheManager;
public:
    StringReverseCH(ICacheManager<std::string, std::string> *cacheManger);

    std::string solveProblem(std::string &problem);

    void handleClient(int socket) override;
};


#endif //CLIENT_SERVER_STRINGREVERSECH_H
