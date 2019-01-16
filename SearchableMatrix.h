
#ifndef CLIENT_SERVER_SEARCHABLEMATRIX_H
#define CLIENT_SERVER_SEARCHABLEMATRIX_H

#include "Matrix.h"
#include "Searchable.h"
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class SearchableMatrix : public Searchable<std::pair<int, int>> {
    using Point = std::pair<int, int>;
    Matrix matrix;
    State<Point> *initial_state;
    Point entry_point;
    Point exit_point;
    std::vector<Point> created_point;
    State<Point> *goal_state;
    vector<State<Point> *> states;

public:
    /**
     * Ctor
     * @param matrix
     * @param entry
     * @param exit
     */
    SearchableMatrix(Matrix &matrix, Point entry, Point exit) {
        this->matrix = matrix;
        this->entry_point = entry;
        this->exit_point = exit;
        this->initial_state = new State<Point>();
        this->goal_state = new State<Point>();
        this->created_point.push_back(entry);
    }

    /**
     * Getter of the initial state
     * @return the initial state
     */
    State<Point> *getInitialState() const override {
        this->initial_state->setCost(matrix[entry_point]);
        this->initial_state->setState(entry_point);
        this->initial_state->setVisited(true);//TODO: check if needed
        this->initial_state->setHeuristic(this->getGoalState());
        return initial_state;
    }

    /**
     * Getter of the goal state
     * @return the goal state
     */
    State<Point> *getGoalState() const override {
        this->goal_state->setCost(matrix[exit_point]);
        this->goal_state->setState(exit_point);
        this->goal_state->setVisited(false);
        this->initial_state->setH();
        return goal_state;
    }

    /**
     * Getter of the initial node
     * @return the initial node
     */
    Point getInitialNode() const override {
        return entry_point;
    }

    /**
     * Getter of the node
     * @return the node
     */
    Point getGoalNode() const override {
        return exit_point;
    }

    /**
     * Check the bounds of the point. if the point in bounds
     * return true, otherwise false.
     * @param p is the point
     * @return true or false
     */
    bool check_bounds(Point p) {
        return p.first >= 0 && p.second >= 0 && p.first < matrix.getRow() && p.second < matrix.getCol();
    }

    /**
     * Getter of the possible states of a state.
     * @param mat_state is the state to find his possible states.
     * @return vector of all the possible states.
     */
    vector<State<Point> *> getAllPossibleStates(State<Point> *mat_state, int) {
        vector<State<Point> *> pos_states;
        Point possible_point = mat_state->getState();
        // the state location
        // the matrix bounds
        // if it is possible to return current y position on the above row
        list<Point> directions = {{0,  1},
                                  {1,  0},
                                  {-1, 0},
                                  {0,  -1}};
        for (auto &pnt : directions) {
            Point p = {possible_point.first + pnt.first, possible_point.second + pnt.second};
            if (check_bounds(p) && matrix[p] != -1) {
                State<Point> *state = new State<Point>(p, matrix[p]);
                state->setHeuristic(this->getGoalState());
                pos_states.push_back(state);
                this->states.push_back(state);
            }
        }
        return pos_states;
    }

    /**
     * Getter of the possible states
     * @param mat_state
     * @return vector with the possible states
     */
    std::vector<State<Point> *> getAllPossibleStates(State<Point> *mat_state) {
        // the vector to return
        std::vector<State<Point> *> pos_states;
        State<Point> *state;
        Point possible_point;
        // the state location
        int x_pos = mat_state->getState().first;
        int y_pos = mat_state->getState().second;
        // the matrix bounds
        int last_x_pos = matrix.getRow() - 1;
        int last_y_pos = matrix.getCol() - 1;
        // if it is possible to return current y position on the above row
        if (x_pos > 0) {
            possible_point = Point(x_pos - 1, y_pos);
            if (find(this->created_point.begin(), this->created_point.end(), possible_point) ==
                this->created_point.end()) {
                if (matrix[possible_point] >= 0) {
                    state = new State<Point>(possible_point, this->matrix[possible_point]);
                    pos_states.push_back(state);
                    this->created_point.push_back(possible_point);
                    this->states.push_back(state);
                }
            }
        }
        // next row
        if (x_pos < last_x_pos) {
            possible_point = Point(x_pos + 1, y_pos);
            if (find(this->created_point.begin(), this->created_point.end(), possible_point) ==
                this->created_point.end()) {
                if (matrix[possible_point] >= 0) {
                    state = new State<Point>(possible_point, this->matrix[possible_point]);
                    pos_states.push_back(state);
                    this->created_point.push_back(possible_point);
                    this->states.push_back(state);
                }
            }
        }
        // prev col
        if (y_pos > 0) {
            possible_point = Point(x_pos, y_pos - 1);
            if (find(this->created_point.begin(), this->created_point.end(), possible_point) ==
                this->created_point.end()) {
                if (matrix[possible_point] >= 0) {
                    state = new State<Point>(possible_point, this->matrix[possible_point]);
                    pos_states.push_back(state);
                    this->created_point.push_back(possible_point);
                    this->states.push_back(state);
                }
            }
        }
        // next col
        if (y_pos < last_y_pos) {
            possible_point = Point(x_pos, y_pos + 1);
            if (find(this->created_point.begin(), this->created_point.end(), possible_point) ==
                this->created_point.end()) {
                if (matrix[possible_point] >= 0) {
                    state = new State<Point>(possible_point, this->matrix[possible_point]);
                    pos_states.push_back(state);
                    this->created_point.push_back(possible_point);
                    this->states.push_back(state);
                }
            }
        }
        return pos_states;
    }

    /**
     * Destructor
     */
    ~SearchableMatrix() {
        for (int i = 0; i < this->states.size(); i++) {
            delete this->states[i];
        }
        delete initial_state;
        delete goal_state;
    }
};

#endif //CLIENT_SERVER_SEARCHABLEMATRIX_H
