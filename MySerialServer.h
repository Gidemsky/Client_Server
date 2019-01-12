//
// Created by gideon on 09/01/19.
//

#ifndef CLIENT_SERVER_MYSERIALSERVER_H
#define CLIENT_SERVER_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public Server{
    int port;
    ClientHandler* clientHandler;
public:
    void open(int port, ClientHandler* clientHandler);

    bool stop() override;

    static void* start(void* myParams);
};


#endif //CLIENT_SERVER_MYSERIALSERVER_H
