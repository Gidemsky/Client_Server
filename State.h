
#ifndef CLIENT_SERVER_STATE_H
#define CLIENT_SERVER_STATE_H

template <class Node>
class State {
private:
    Node node;
    double cost;    // price of the node
    State<Node>* come_from;
    bool is_visited;
    double shortestPathVal;


public:
    State() {
        this->come_from = nullptr;
        this->is_visited = false;
    }

    State(Node state, double cost){
        this->node = state;
        this->is_visited = false;
        this->cost = cost;
    }

    bool& operator==(const State<Node>& s){
        return (s.come_from == come_from && s.cost == cost && s.node == node);
    }

    bool operator == (State<Node>* b) {
        return shortestPathVal == b->getShortestPathVal();
    }

    State<Node> & operator=(const State<Node>& s){
        this->node = s.getState();
        this->cost = s.getCost();
        this->come_from = s.getComeFrom();
        this->is_visited = false;
        return *this;
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
        this->cost = cost;
    }

    State<Node>* getComeFrom() {
        return this->come_from;
    }

    void setComeFrom(State<Node> *come_from){
        this->come_from = come_from;
    }

    bool isVisited() const{
        return this->is_visited;
    }

    void setVisited(bool b){
        this->is_visited = b;
    }

    double getShortestPathVal(){
        return shortestPathVal;
    }

    void setShortestPathVal(double shortestPath) {
        shortestPathVal = shortestPath;
    }
};

#endif //CLIENT_SERVER_STATE_H
