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

#define END "end"

using Point = std::pair<int, int>;

ClientHandler::ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger) {
    this->cacheManager = cacheManger;

    //this->solver = new SolverSearcher
}

void ClientHandler::handleClient(int new_sock) {
    //TO DO : WHAT IS THE SIZE OF INPUT?
    char buffer[256];
    ssize_t erez = 0;
    string buff, client_line;
    //reads from client as long as input is not stop
    while (buff.find(END) == string::npos) {
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
    int i = 0;
//    DFS<Point> *dfs = new DFS<Point>();
//    dfs->search(searchableMatrix);
}

string ClientHandler::solveProblem(string &problem) {
    Stringable *str = new StringableMatrix(problem);
    if (this->getCacheManager()->isProblemExist(str)) {
        return this->getCacheManager()->search(str)->makeString();
    }
    Separator separator(problem);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    string *solution;
    //Searchable<Point> *searchable = cast_to_matrix(problem);
//    Searcher<Point> *dfs = new DfsAlgo(((SearchableMatrix *) searchable)->getMatrix()->getNumOfVertex(),
//                                       ((SearchableMatrix *) searchable)->getMatrix()->getNumOfColumns());
    ISearcher<Point> *bfs=new BestFirstSearch<Point>();
    this->solver = new SolverSearcher<Point>(bfs);
    //Stringable *str_able = this->solver->solve(searchable);
    //string b=str_able->makeString();
//    reverse(b.begin(),b.end());
//    solution=&b;
//    this->cacheManager->save(str, str_able);
    return *solution;
}
