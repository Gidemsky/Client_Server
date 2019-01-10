//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SERVER_H
#define CLIENT_SERVER_SERVER_H

#include "ClientHandler.h"

class Server{
public:
    virtual void open(int port, ClientHandler* c) = 0; // getting port to listen, open the server and wait for clients
    virtual bool stop() = 0; // close the server
    virtual void start() = 0;
};

#endif //CLIENT_SERVER_SERVER_H
