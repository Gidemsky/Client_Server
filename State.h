//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_STATE_H
#define CLIENT_SERVER_STATE_H

template <class Node>
class State {
private:
    Node node;
    double cost;    // price of the node
    const State<Node>* come_from;
    //string str;

public:
    bool operator==(State<Node> s);

    //getter and setters
    Node getState() const;

    void setState(Node state);

    double getCost() const;

    void setCost(double cost);

    const State<Node>* getCome_from() const;

    void setCome_from(const State<Node>* come_from);
};

template<class T>
bool State<T>::operator==(State<T> s) {
    // TODO check if pointers comparison satisfies the equality requirements
    return (s.come_from == come_from && s.cost == cost && s.node == node);
}

template<class T>
T State<T>::getState() const {
    return node;
}

template<class T>
void State<T>::setState(T state) {
    this->node = state;
}

template<class T>
double State<T>::getCost() const {
    return cost;
}

template<class T>
void State<T>::setCost(double cost) {
    State::cost = cost;
}

template<class T>
const State<T>* State<T>::getCome_from() const {
    return come_from;
}

template<class T>
void State<T>::setCome_from(const State<T>* come_from) {
    State::come_from = come_from;
}



#endif //CLIENT_SERVER_STATE_H
