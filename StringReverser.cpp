//
// Created by gideon on 12/01/19.
//

#include "StringReverser.h"
#include <algorithm>

string StringReverser::solve(string problem) {
    string rev = problem;
    reverse(rev.begin(), rev.end());
    return rev;
}