#include <iostream>
#include <vector>
#include "ParallelServer.h"
#include "ClientHandler.h"
#include "StringReverseCH.h"
#include "FileCacheManager.h"
#include "Separator.h"
#include "SearchableMatrix.h"
#include "Searchable.h"
#include "BFS.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "StringableMatrix.h"
#include "SolverSearcher.h"
#include "AStar.h"

using Point = std::pair<int, int>;
string string_mat = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|3,3|end";

void dfsTest() {
    string string_mat1 = "1,2,3|4,5,6|7,8,9|0,0|2,2|end";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    DFS<Point> *dfs = new DFS<Point>();
    dfs->search(searchableMatrix);
}

void bfsTest() {
    string string_mat1 = "1,2,3|4,5,6|7,8,9|0,0|1,1|end";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BFS<Point> *bfs = new BFS<Point>();
    bfs->search(searchableMatrix);
}


void Test() {
    string string_mat2 = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|2,2|end";
    ParallelServer s = ParallelServer();
    ICacheManager<Stringable,Stringable>* cacheManager=new FileCacheManager();
    IClientHandler *c = new StringReverseCH(cacheManager);
    s.open(5400, c);
//    pthread_exit(NULL);
//    vector<vector<double>> v;
//    vector<double> myV;
//    int j = 0;
//    for (double i = 0; i < 3; ++i) {
//        for (j; j < 3; ++j) {
//            myV.push_back(j);
//        }
//        v.push_back(myV);
//    }
    Separator separator(string_mat2);
    Matrix* matrix = separator.matrixCreator();
    SearchableMatrix* searchableMatrix;
    searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
}


void bestFirstTest() {
    string string_mat1 = "1,270,100,100 \n 70,100,9,10 \n 100,11,9,2 \n0,0\n2,3\nend";
    ICacheManager<Stringable, Stringable> *cacheManager = new FileCacheManager();
    ClientHandler *clnt_hand = new ClientHandler(cacheManager);
    clnt_hand->solveProblem(string_mat1);

}

//template <class Node>
void aStarTest() {
    string string_mat1 = "1,70,100,100 \n 70,100,9,10 \n 100,11,9,2 \n0,0\n2,3\nend";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    AStar<Point> *a = new AStar<Point>();
    a->search(searchableMatrix);
}

void bestTest() {
    string string_mat1 = "1, 10, 1, 1, 1, 10 \n 1, 10, 1, 50, 1, 10 \n 1, 1, 1, 20, 1, 10 \n 1, 2, 2, 100, 1, 10 \n 10, 10, 10, 10, 10, 10\n0,0\n3, 4\nend";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BestFirstSearch<Point> *a = new BestFirstSearch<Point>();
    auto t = a->search(searchableMatrix);
    int zibi = 0;
}

int main() {
//    IClientHandler* handler = new myClientHandler(new FileCacheManager(7));
//    MySerialServer server;
//    server.open(5432, handler);


    //Test();
    //bestFirstTest();
    //bfsTest();
    //aStarTest();
    bestTest();
    return 0;
}