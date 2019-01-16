
#ifndef CLIENT_SERVER_MYSERIALSERVER_H
#define CLIENT_SERVER_MYSERIALSERVER_H

#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <cerrno>
#include <stack>
#include <string>
#include <iostream>
#include <netinet/in.h>

class ParallelServer : public Server {
    int port{};
    IClientHandler *clientHandler{};
public:
    void open(int port, IClientHandler *clientHandler) override;

    static void start(int, IClientHandler *);

    bool stop() override;
};

#endif //CLIENT_SERVER_MYSERIALSERVER_H
