//
// Created by gideon on 12/01/19.
//

#ifndef CLIENT_SERVER_STRINGREVERSER_H
#define CLIENT_SERVER_STRINGREVERSER_H

#include "string"
#include "Solver.h"
#include <bits/stdc++.h>

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    string solve(string problem) override;
};


#endif //CLIENT_SERVER_STRINGREVERSER_H
