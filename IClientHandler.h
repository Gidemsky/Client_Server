//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_ICLIENTHANDLER_H
#define CLIENT_SERVER_ICLIENTHANDLER_H

#include "Matrix.h"
#include <iostream>
class IClientHandler {
public:
        virtual void handleClient(int sock) = 0;
};
#endif //CLIENT_SERVER_ICLIENTHANDLER_H