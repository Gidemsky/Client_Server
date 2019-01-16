//
// Created by gideon on 08/01/19.
//

#include "ClientHandler.h"
#include "StringReverser.h"
#include "StringableMatrix.h"
#include "Separator.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "SolverSearcher.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <netinet/in.h>

#define FINISH_MAT "end"

using Point = std::pair<int, int>;

ClientHandler::ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger) {
    this->cacheManager = cacheManger;
}

void ClientHandler::handleClient(int new_sock) {
    //TO DO : WHAT IS THE SIZE OF INPUT?
    char buffer[256];
    ssize_t erez = 0;
    string buff, client_line;
    //reads from client as long as input is not stop
    while (buff.find(FINISH_MAT) == string::npos) {
        //pthread_mutex_lock(&lock);
        erez = read(new_sock, buffer, 256);
        if (erez < 0) {
            perror("cannot read from client");
            exit(1);
        }   else if (erez == 0) {
            perror("connection reset by peer");
            return;
        }
        buffer[erez] = 0;
        buff += string(buffer);
    }
    string path_result = solveProblem(buff);
    const char *chr = path_result.c_str();
    int n = static_cast<int>(write(new_sock, chr, strlen(chr)));
    if (n<0){
        perror("ERROR writing to the socket");
        exit(1);
    }
}

string ClientHandler::solveProblem(string &problem) {
    Stringable *str = new StringableMatrix(problem);
    //checks if the solutioh exist TODO:check if it works
    if (this->getCacheManager()->isProblemExist(str)) {
        return this->getCacheManager()->search(str)->makeString();
    }
    Separator separator(problem);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    ISearcher<Point> *bfs=new BestFirstSearch<Point>();
    this->solver = new SolverSearcher<Point>(bfs);
    Stringable *sol = this->solver->solve(searchableMatrix);
    string str_sol = sol->makeString();
    this->cacheManager->save(str, sol);
    return str_sol;
}

ICacheManager<Stringable, Stringable> *ClientHandler::getCacheManager() {
    return this->cacheManager;
}


