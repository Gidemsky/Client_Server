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
    State() {
        this->come_from = nullptr;
    }

    State(Node state, double cost){
        this->node = state;
        this->is_visited = false;
        this->cost = cost;
    }

    bool& operator==(const State<Node>& s){
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

#endif //CLIENT_SERVER_STATE_H
