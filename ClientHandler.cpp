//
// Created by gideon on 08/01/19.
//

#include "ClientHandler.h"
#include "StringReverser.h"
#include "StringableMatrix.h"
#include "Separator.h"
#include "SearchableMatrix.h"
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
    Separator separator(buff);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    int i = 0;
//    DFS<Point> *dfs = new DFS<Point>();
//    dfs->search(searchableMatrix);
}
