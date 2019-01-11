//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_CACHEMANAGER_H
#define CLIENT_SERVER_CACHEMANAGER_H

template<class Problem, class Solution>
class ICacheManager {
public:
    virtual void save(Problem* problem,Solution* soulution) = 0;

    virtual bool isProblemExist(Problem* problem)=0;

    virtual Solution* search(Problem* problem) = 0;
};

#endif //CLIENT_SERVER_CACHEMANAGER_H
