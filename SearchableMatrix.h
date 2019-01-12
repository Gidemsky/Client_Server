
#ifndef CLIENT_SERVER_SEARCHABLEMATRIX_H
#define CLIENT_SERVER_SEARCHABLEMATRIX_H

#include "Matrix.h"
#include "Searchable.h"

class SearchableMatrix : public Searchable<std::pair<int, int>> {
    Matrix matrix;
    using Point = std::pair<int, int>;
    Point entry_point;
    Point exit_point;

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
    }

    /**
     * Getter of the initial state
     * @return the initial state
     */
    State<Point>* getInitialState() const override {
        State<Point> *initial_state =
                new State<Point>();
        initial_state->setCost(matrix[entry_point]);
        initial_state->setState(entry_point);
        return initial_state;
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
        int last_x_pos = matrix.getRow();
        int last_y_pos = matrix.getCol();
        // if it is possible to return current y position on the above row
        if (x_pos > 0) {
            possible_point = Point(x_pos - 1, y_pos);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        // next row
        if (x_pos < last_x_pos) {
            possible_point = Point(x_pos + 1, y_pos);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        // prev col
        if (y_pos > 0) {
            possible_point = Point(x_pos, y_pos - 1);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        // next col
        if (y_pos < last_y_pos) {
            possible_point = Point(x_pos, y_pos + 1);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }
        return pos_states;
    }
};

#endif //CLIENT_SERVER_SEARCHABLEMATRIX_H
