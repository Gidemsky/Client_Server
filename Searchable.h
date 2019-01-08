//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_ISEARCHABLE_H
#define CLIENT_SERVER_ISEARCHABLE_H

#include "State.h"
#include <vector>
#include <set>

template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual std::vector<State<T>*> getAllPossibleState() = 0;
};

#endif //CLIENT_SERVER_ISEARCHABLE_H
