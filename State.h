
#ifndef CLIENT_SERVER_STATE_H
#define CLIENT_SERVER_STATE_H

template<class Node>
class State {
private:
    Node node;
    double cost; // price of the node
    State<Node> *come_from;
    bool is_visited;
    double h_score; // heuristic

public:
    /**
     * Ctor
     */
    State() {
        this->come_from = nullptr;
        this->is_visited = false;
    }

    /**
     * Ctor
     * @param state is the node
     * @param cost is the price
     */
    State(Node state, double cost) {
        this->node = state;
        this->is_visited = false;
        this->cost = cost;
    }

    /**
     * Operator == overloading
     * @param s is the state to check
     * @return true or false
     */
    bool &operator==(const State<Node> &s) {
        return (s.come_from == come_from && s.cost == cost && s.node == node);
    }

    /**
     * Operator = overloading
     * @param s is the state to take the data
     * @return
     */
    State<Node> &operator=(State<Node> s) {
        this->node = s.getState();
        this->cost = s.getCost();
        this->come_from = s.getComeFrom();
        this->is_visited = false;
        return *this;
    }

    /**
     * Getter of the node of the state
     * @return the node
     */
    Node getState() const {
        return node;
    }

    /**
     * Setter of the node to the state
     * @param state is the state set
     */
    void setState(Node state) {
        this->node = state;
    }

    /**
     * Getter of the state's price
     * @return the price
     */
    double getCost() const {
        return cost;
    }

    /**
     * Setter of the state's price
     * @param cost is the price to set
     */
    void setCost(double cost) {
        this->cost = cost;
    }

    /**
     * Getter of the come from of the state
     * @return the state
     */
    State<Node> *getComeFrom() {
        return this->come_from;
    }

    /**
     * Setter of the come from of the state
     * @param come_from is the state to set as come from
     */
    void setComeFrom(State<Node> *come_from) {
        this->come_from = come_from;
    }

    /**
     * Getter of is visited
     * @return true or false
     */
    bool isVisited() const {
        return this->is_visited;
    }

    /**
     * Setter of is visited
     * @param b is the bool to set
     */
    void setVisited(bool b) {
        this->is_visited = b;
    }

    /**
     * Setter of the heuristic
     * @param goal
     */
    void setHeuristic(State<Node> *goal) {
        int x = abs(this->getState().first - goal->getState().first);
        int y = abs(this->getState().second - goal->getState().second);
        this->h_score = x + y;
    }

    /**
     * Initialize heuristic with 0
     */
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
