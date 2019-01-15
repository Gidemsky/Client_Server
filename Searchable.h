
#ifndef CLIENT_SERVER_ISEARCHABLE_H
#define CLIENT_SERVER_ISEARCHABLE_H

#include "State.h"
#include <vector>

template <class Node>
class Searchable {
public:
    virtual State<Node> *getInitialState() const = 0;

    virtual Node getInitialNode() const = 0;

    virtual Node getGoalNode() const = 0;

    virtual State<Node> *getGoalState() const = 0;

    virtual std::vector<State<Node> *> getAllPossibleStates(State<Node> *) = 0;

};

#endif //CLIENT_SERVER_ISEARCHABLE_H
