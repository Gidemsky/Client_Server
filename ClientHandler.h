//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_ICLIENTHANDLER_H
#define CLIENT_SERVER_ICLIENTHANDLER_H

#include <iostream>
using namespace std;
class ClientHandler{
public:
    virtual void clientHandler(int socket) = 0;
};

#endif //CLIENT_SERVER_ICLIENTHANDLER_H
