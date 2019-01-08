//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_SEARCHER_H
#define CLIENT_SERVER_SEARCHER_H

#include "Searchable.h"
#include "State.h"

template <class T>
class ISearcher {
public:
    virtual std::vector<State<T>*> search (Searchable<T>* searchable) = 0;

    virtual int getNumberOfNudesEvaluated() = 0;
};

#endif //CLIENT_SERVER_SEARCHER_H
