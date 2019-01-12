
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
    SearchableMatrix(Matrix &matrix, Point entry, Point exit) {
        this->matrix = matrix;
        this->entry_point = entry;
        this->exit_point = exit;
    }

    State<Point> getInitialState() const override {
        State<Point> *initial_state = nullptr;
        initial_state->setComeFrom(nullptr);
        initial_state->setCost(matrix[entry_point]);
        initial_state->setState(entry_point);
    }

    Point getInitialNode() const override {
        return entry_point;
    }

    Point getGoalNode() const override {
        return exit_point;
    }

    /**
     * Check if the point is in the matrix.
     * @param p is the point.
     * @return true if it's in the matrix, false otherwise.
     */
    bool isPointInMatrix(Point p) {
        int last_x = matrix.getRow();
        int last_y = matrix.getCol();
        int x = p.first;
        int y = p.second;
        if (x < 0 || x > last_x || y < 0 || y > last_y) {
            return false;
        }
        return true;
    }

    std::vector<State<Point> *> getAllPossibleStates(State<Point> mat_state) override {
        std::vector<State<Point> *> pos_states;

        Point possible_point;

        int x_pos = mat_state.getState().first;
        int y_pos = mat_state.getState().second;

        int last_x_pos = matrix.getRow();
        int last_y_pos = matrix.getCol();

        State<Point> *state;

        //if it is possible to return current y position on the above row
        if (x_pos > 0) {
            possible_point = Point(x_pos - 1, y_pos);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        //next row
        if (x_pos < last_x_pos) {
            possible_point = Point(x_pos + 1, y_pos);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        //prev col
        if (y_pos > 0) {
            possible_point = Point(x_pos, y_pos - 1);
            if (matrix[possible_point] >= 0) {
                state = new State<Point>(possible_point, this->matrix[possible_point]);
                pos_states.push_back(state);
            }
        }

        //next col
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
