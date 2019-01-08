//
// Created by gideon on 08/01/19.
//

#include "State.h"

template<class T>
bool State<T>::equal(State<T> s) {
    return s == (this->state);
}
