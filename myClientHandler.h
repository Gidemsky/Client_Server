//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_MYCLIENTHANDLER_H
#define CLIENT_SERVER_MYCLIENTHANDLER_H


#include <unistd.h>

class myClientHandler {

    struct Server
    {
        char* read();
    };

    struct CLientHandler
    {
        char input[256];
        void handle(int s)
        {
            read(s, input, 255);
        }
    };

};


#endif //CLIENT_SERVER_MYCLIENTHANDLER_H
