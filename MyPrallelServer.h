//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MYPRALLELSERVER_H
#define CLIENT_SERVER_MYPRALLELSERVER_H


#include "Server.h"

class MyPrallelServer : public Server{
private:

public:
    void *readFromServer(void *pparams);
};


#endif //CLIENT_SERVER_MYPRALLELSERVER_H
