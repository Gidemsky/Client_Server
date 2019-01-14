//
// Created by gideon on 09/01/19.
//

#ifndef CLIENT_SERVER_MYSERIALSERVER_H
#define CLIENT_SERVER_MYSERIALSERVER_H


#include "Server.h"


class ParallelServer: public Server{
    int port{};
    IClientHandler* clientHandler{};
public:
    void open(int port, IClientHandler* clientHandler) override;
    static void start(int, IClientHandler *);
    bool stop() override;

};


#endif //CLIENT_SERVER_MYSERIALSERVER_H
