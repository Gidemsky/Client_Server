//
// Created by benda on 08/01/19.
//

#ifndef CLIENT_SERVER_FILECHACEMANAGER_H
#define CLIENT_SERVER_FILECHACEMANAGER_H

#include "ICacheManager.h"
#include <fstream>
#include <map>

using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public ICacheManager<Problem, Solution> {
public:
     fstream file;
     map<string, string> cache;

};

#endif //CLIENT_SERVER_FILECHACEMANAGER_H
