//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SERVER_H
#define CLIENT_SERVER_SERVER_H

#include "ClientHandler.h"

class Server{
public:
    //virtual void open(int port, ClientHandler* c); // getting port to listen, open the server and wait for clients
    virtual bool stop(); // close the server
    virtual void start();
};

#endif //CLIENT_SERVER_SERVER_H
