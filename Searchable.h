//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_ISEARCHABLE_H
#define CLIENT_SERVER_ISEARCHABLE_H

#include "State.h"
#include <vector>

template <class Node>
class Searchable {
public:
    virtual State<Node> getInitialState() const = 0;
    virtual Node getInitialNode() const = 0;
    virtual Node getGoalNode() const = 0;
    virtual std::vector<State<Node>*> getAllPossibleStates(State<Node> state) = 0;//why const doesnt good
    //virtual int size() const = 0; //TODO: check if it is template
};

#endif //CLIENT_SERVER_ISEARCHABLE_H