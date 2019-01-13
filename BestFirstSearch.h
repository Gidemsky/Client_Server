//
// Created by gideon on 13/01/19.
//

#ifndef CLIENT_SERVER_BREADTHFIRSTSEARCH_H
#define CLIENT_SERVER_BREADTHFIRSTSEARCH_H

#include <list>
#include <algorithm>
#include "ISearcher.h"

using namespace std;

template<class Node>
class BestFirstSearch : public ISearcher<Node> {
private:
    int count = 0;
public:

    /**
     * Ctor
     */
    BestFirstSearch() {
        this->count = 0;
    }

    virtual vector<State<Node> *> search(Searchable<Node> *searchable);

    virtual int getNumberOfNodesEvaluated() {
        return this->count;
    }
};

template<class Node>
/**
 * The algorithm
 * @tparam Node
 * @param searchable
 * @return
 */
vector<State<Node> *> BestFirstSearch<Node>::search(Searchable<Node> *searchable) {

}
#endif //CLIENT_SERVER_BREADTHFIRSTSEARCH_H
