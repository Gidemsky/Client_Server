
#ifndef CLIENT_SERVER_SERVER_H
#define CLIENT_SERVER_SERVER_H

#include "IClientHandler.h"

class Server{
public:
    virtual void open(int port, IClientHandler* c) = 0; // getting port to listen, open the server and wait for clients
    virtual bool stop() = 0; // close the server
    static void* start(void* myParams);
};

#endif //CLIENT_SERVER_SERVER_H
