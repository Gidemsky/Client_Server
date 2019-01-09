//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_CACHEMANAGER_H
#define CLIENT_SERVER_CACHEMANAGER_H

template <class Problem, class Solution>
class ICacheManager {
public:
    virtual Solution getSolution(Problem problem);
    virtual void saveSolution(Problem problem, Solution solution);
    virtual bool isSolutionExist(Problem problem);
};

#endif //CLIENT_SERVER_CACHEMANAGER_H
