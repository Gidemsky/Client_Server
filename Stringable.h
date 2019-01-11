//
// Created by gideon on 11/01/19.
//

#ifndef CLIENT_SERVER_STRINGABLE_H
#define CLIENT_SERVER_STRINGABLE_H

#include "string"

using namespace std;

class Stringable {
public:
    virtual string makeString()=0;
};

#endif //CLIENT_SERVER_STRINGABLE_H
