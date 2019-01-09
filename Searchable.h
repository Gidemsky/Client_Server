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
    virtual State<T> getInitialState() const = 0;
    virtual T getInitialNode() const = 0;
    virtual T getGoalNode() const = 0;
    virtual std::vector<State<T>> getAllPossibleStates(State<T> ) const = 0;
};

#endif //CLIENT_SERVER_ISEARCHABLE_H
