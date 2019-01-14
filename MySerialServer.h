//
// Created by gideon on 09/01/19.
//

#ifndef CLIENT_SERVER_MYSERIALSERVER_H
#define CLIENT_SERVER_MYSERIALSERVER_H


#include "Server.h"


class MySerialServer: public Server{
    int port{};
    ClientHandler* clientHandler{};
public:
    void open(int port, ClientHandler* clientHandler) override;
    static void start(int, ClientHandler *);

    bool stop() override;

};


#endif //CLIENT_SERVER_MYSERIALSERVER_H
