
#ifndef CLIENT_SERVER_STATE_H
#define CLIENT_SERVER_STATE_H

template <class Node>
class State {
private:
    Node node;
    double cost;    // price of the node
    State<Node>* come_from;
    bool is_visited;
    double h_score; // heuristic

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


    State<Node> & operator=(State<Node> s){
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

    /**
     * Setter of the heuristic
     * @param goal
     */
    void setHeuristic(State<Node>* goal) {
        int x = abs(this->getState().first - goal->getState().first);
        int y = abs(this->getState().second - goal->getState().second);
        this->h_score = x + y;
    }

    void setH() {
        this->h_score = 0;
    }

    /**
     * Getter of the heuristic
     * @return
     */
    double getHeuristic() {
        return this->h_score;
    }
};

#endif //CLIENT_SERVER_STATE_H
