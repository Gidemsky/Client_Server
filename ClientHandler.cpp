
#include "ClientHandler.h"
#include "StringableMatrix.h"
#include "Separator.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"
#include "SolverSearcher.h"
#include "AStar.h"
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
#define INPUT_SIZE 256

using Point = std::pair<int, int>;

/**
 *
 * @param cacheManger
 */
ClientHandler::ClientHandler(ICacheManager<Stringable, Stringable> *cacheManger) {
    this->cacheManager = cacheManger;
}

/**
 * the function handles the client's connction in order to solve some problem
 * @param new_sock
 */
void ClientHandler::handleClient(int new_sock) {
    char buffer[INPUT_SIZE];
    ssize_t erez = 0;
    string buff, client_line;
    //reads from client as long as input is not stop
    while (buff.find(FINISH_MAT) == string::npos) {
        //pthread_mutex_lock(&lock);
        erez = read(new_sock, buffer, INPUT_SIZE);
        if (erez < 0) {
            perror("cannot read from client");
            exit(1);
        } else if (erez == 0) {
            perror("connection reset by peer");
            return;
        }
        buffer[erez] = 0;
        buff += string(buffer);
    }
    //saves the solution of the problem
    string path_result = solveProblem(buff);
    const char *chr = path_result.c_str();
    //writes the solution to the client
    int n = static_cast<int>(write(new_sock, chr, strlen(chr)));
    if (n < 0) {
        perror("ERROR writing to the socket");
        exit(1);
    }
}
/**
 * the main solution problem solver function using the A-Star algo
 * @param problem
 * @return
 */
string ClientHandler::solveProblem(string &problem) {
    Stringable *str = new StringableMatrix(problem);
    //checks if the solution exist
    if (this->getCacheManager()->isProblemExist(str)) {
        return this->getCacheManager()->search(str)->makeString();
    }
    //prepares the  string for the problem
    Separator separator(problem);
    //creates the matrixs
    Matrix *matrix = separator.matrixCreator();
    //then make ther matrix as searchable
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix, matrix->getP_start(), matrix->getP_goal());
    ISearcher<Point> *AStar = new ::AStar<Point>();
    this->solver = new SolverSearcher<Point>(AStar);
    //solve the problem using the A-star algorithems
    Stringable *sol = this->solver->solve(searchableMatrix);
    string str_sol = sol->makeString();
    this->cacheManager->save(str, sol);
    delete AStar;
    delete searchableMatrix;
    return str_sol;
}
/**
 * Getter of the cache manager
 * @return
 */
ICacheManager<Stringable, Stringable> *ClientHandler::getCacheManager() {
    return this->cacheManager;
}


