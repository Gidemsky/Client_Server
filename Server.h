//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SERVER_H
#define CLIENT_SERVER_SERVER_H

#include "ClientHandler.h"

//namespace server_side{
//    class Server;
//}

class Server{
public:
    virtual void open(int port, ClientHandler* c); // getting port to listen, open the server and wait for clients
    virtual void stop(); // close the server
};
`
#endif //CLIENT_SERVER_SERVER_H
