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
    bool is_visited;

public:
    State();
    State(Node state, double cost){
        this->node = state;
        this->is_visited = false;
        this->cost = cost;
    }

    bool operator==(State<Node> s){
        // TODO check if pointers comparison satisfies the equality requirements
        return (s.come_from == come_from && s.cost == cost && s.node == node);
    }

    Node getState() const{
        return node;
    }

    void setState(Node state){
        this->node = state;
    }

    double getCost() const{
        return cost;
    }

    void setCost(double cost){
        State::cost = cost;
    }

    const State<Node>* getComeFrom() const{
        return come_from;
    }

    void setComeFrom(const State<Node> *come_from){
        State::come_from = come_from;
    }

    bool isVisited() const{
        return this->is_visited;
    }

    void setVisited(bool b){
        this->is_visited = b;
    }
};

//template<class T>
//bool State<T>::operator==(State<T> s) {
//    // TODO check if pointers comparison satisfies the equality requirements
//    return (s.come_from == come_from && s.cost == cost && s.node == node);
//}

//template<class T>
//T State<T>::getState() const {
//    return node;
//}

//template<class T>
//void State<T>::setState(T state) {
//    this->node = state;
//}

//template<class T>
//double State<T>::getCost() const {
//    return cost;
//}

//template<class T>
//void State<T>::setCost(double cost) {
//    State::cost = cost;
//}

//template<class T>
//const State<T>* State<T>::getComeFrom() const {
//    return come_from;
//}

//template<class T>
//void State<T>::setComeFrom(const State<T> *come_from) {
//    State::come_from = come_from;
//}

//template<class Node>
//void State<Node>::setVisited(bool b) {
//    this->is_visited = b;
//}

//template<class Node>
//bool State<Node>::isVisited() const {
//    return this->is_visited;
//}

#endif //CLIENT_SERVER_STATE_H
