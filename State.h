//
// Created by gideon on 08/01/19.
//

#ifndef CLIENT_SERVER_STATE_H
#define CLIENT_SERVER_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T> come_from;
    //string str;

public:
    bool equal(State<T> s);
};


#endif //CLIENT_SERVER_STATE_H
