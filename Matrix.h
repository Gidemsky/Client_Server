
#ifndef CLIENT_SERVER_MATRRIX_H
#define CLIENT_SERVER_MATRRIX_H

#include <vector>

class Matrix {
    using Point = std::pair<int, int>;
    using MatrixVec = std::vector<std::vector<double>>;
    int row, col;
    MatrixVec _data;
    std::pair<int, int> p_start, p_goal;

public:
    /**
     * Ctor
     * @param vec
     */
    explicit Matrix(const MatrixVec &vec) {
        this->_data = vec;
        setPointPairs();
        this->row = static_cast<int>(_data.size());
        this->col = static_cast<int>(_data.front().size());
    }

    /**
     * Ctor
     */
    Matrix() {}

    const MatrixVec &get_data() const {
        return _data;
    }

    /**
     * Getter of the start point of the matrix
     * @return the point
     */
    const std::pair<int, int> &getP_start() const {
        return p_start;
    }

    /**
     * Getter of the goal point of the matrix
     * @return the point
     */
    const std::pair<int, int> &getP_goal() const {
        return p_goal;
    }

    /**
     * Setter of point pairs according to data
     */
    void setPointPairs() {
        std::vector<double> point_val = this->_data.back();
        int x = static_cast<int>(point_val[0]);
        int y = static_cast<int>(point_val[1]);
        this->_data.pop_back();
        this->p_goal.first = x;
        this->p_goal.second = y;
        point_val = this->_data.back();
        x = static_cast<int>(point_val[0]);
        y = static_cast<int>(point_val[1]);
        this->_data.pop_back();
        this->p_start.first = x;
        this->p_start.second = y;
    }

    /**
     * Operator & overloading
     * @param p
     * @return
     */
    double &operator[](const Point &p) {
        return _data[p.first][p.second];
    }

    /**
     * Operator [] overloading
     * @param p
     * @return
     */
    double operator[](const Point &p) const {
        return _data[p.first][p.second];
    }

    /**
     * Getter of the rows number
     * @return
     */
    int getRow() {
        return this->row;
    }

    /**
     * Getter of the columns number
     * @return
     */
    int getCol() {
        return this->col;
    }
};

#endif //CLIENT_SERVER_MATRRIX_H
