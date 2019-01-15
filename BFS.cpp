//
// Created by gideon on 08/01/19.
//

#include "BFS.h"



//string AStar::search(SearchableInterface *searchable) {
//    double sumUntil;
//    priorityQueue->setCompareType(CMP_BY_FCOST);
//    State *node_current;
//    set<State *> closed;
//    State *initial = searchable->getInitialState();
//    State *goal = searchable->getGoalState();
//    initial->setFCost(initial->getHCost());
//    priorityQueue->push(initial);
//
//
//    while (!priorityQueue->isEmpty()) {
//        node_current = popPriorityQueue();
//        node_current->setIsVisited(true);
//        // push to close?isVisited?
//        if (*node_current == *goal) {
//            return searchable->backTrace(node_current, &evaluatedNodes, &finalRouteSum);
//        }
//
//        list<State *> succerssors = searchable->getAllPossibleStates(node_current);
//        list<State *>::iterator it = succerssors.begin();
//
//        for (; it != succerssors.end(); it++) {
//            sumUntil = node_current->getSumRoute() + (*it)->getCost();
//
//            if (priorityQueue->contains(*it)) {
//                if ((*it)->getSumRoute() <= sumUntil) {
//                    continue;
//                }
//            } else if (closed.find(*it) != closed.end()) {
//                if ((*it)->getSumRoute() <= sumUntil) {
//                    continue;
//                }
//                closed.erase(*it);
//                (*it)->setIsVisited(false);
//                priorityQueue->push(*it);
//            } else {
//                priorityQueue->push(*it);
//            }
//            (*it)->setSumRoute(sumUntil);
//            (*it)->setCameFrom(node_current);
//        }
//        closed.insert(node_current);
//        priorityQueue->adjust();
//    }
//    if (node_current != goal) {
//        throw "no route";
//    }
//}
//
//AStar::AStar() {}
//
//function A*(start,goal)
//closedset := the empty set // The set of nodes already evaluated.
//        openset := {start} // The set of tentative nodes to be evaluated, initially containing the start node
//came_from := the empty map // The map of navigated nodes.
//
//        g_score[start] := 0 // Cost from start along best known path.
//// Estimated total cost from start to goal through y.
//f_score[start] := g_score[start] + heuristic_cost_estimate(start, goal)
//
//while openset is not empty
//        current := the node in openset having the lowest f_score[] value
//if current = goal
//return reconstruct_path(came_from, goal)
//
//remove current from openset
//add current to closedset
//for each neighbor in neighbor_nodes(current)
//tentative_g_score := g_score[current] + dist_between(current,neighbor)
//if neighbor in closedset or tentative_g_score >= g_score[neighbor]
//continue
//if neighbor not in openset or tentative_g_score < g_score[neighbor]
//        came_from[neighbor] := current
//        g_score[neighbor] := tentative_g_score
//        f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
//if neighbor not in openset
//add neighbor to openset
//
//return failure
//
//        function reconstruct_path(came_from, current_node)
//if current_node in came_from
//        p := reconstruct_path(came_from, came_from[current_node])
//return (p + current_node)
//else
//return current_node