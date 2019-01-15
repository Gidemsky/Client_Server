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

string randMat (int row, int col){
    string mat;
    for (int i=0 ; i<row ; i++){
        for (int j=0; j<col ; j++){
            int r = rand() % 12;
            if (row*col % 9 == 0) r = -1;
            mat.append(to_string(r) + ",");
        }
        mat.pop_back();
        mat.append("\n");
    }
    mat.append("0,0 \n");
    mat.append(to_string(row-1) + "," + to_string(col-1));
    return mat;
}
void dfsTest(string mat) {
    //string string_mat1 = "1,2,3|4,5,6|7,8,9|0,0|2,2|end";
    Separator separator(mat);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    DFS<Point> *dfs = new DFS<Point>();
    auto t = dfs->search(searchableMatrix);
    cout << "DFS: " << dfs->getNumberOfNodesEvaluated() << endl;
}

void bfsTest(string mat) {
//    string string_mat1 = "1,2,3|4,5,6|7,8,9|0,0|1,1|end";
    Separator separator(mat);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BFS<Point> *bfs = new BFS<Point>();
    auto t = bfs->search(searchableMatrix);
    cout << "BFS: " << bfs->getNumberOfNodesEvaluated() << endl;
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


void solutionTest() {
    string string_mat1 = "1,270,100,100 \n 70,100,9,10 \n 100,11,9,2 \n0,0\n2,3\nend";
    ICacheManager<Stringable, Stringable> *cacheManager = new FileCacheManager();
    ClientHandler *clnt_hand = new ClientHandler(cacheManager);
    clnt_hand->solveProblem(string_mat1);
}

//template <class Node>
void aStarTest(string mat) {
    Separator separator(mat);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    AStar<Point> *a = new AStar<Point>();
    auto t = a->search(searchableMatrix);
    int zibi = 0;
    cout << "A*: " << a->getNumberOfNodesEvaluated() << endl;
}

void bestTest(string mat) {
    //string string_mat1 = "1, 100, 1, 1, 1, 10 \n 1, 100, 1, 50, 1, 10 \n 1, 1, 10, 20, 1, 10 \n 1, 2, 2, 100, 1, 10 \n 10, 10, 10, 10, 10, 10\n0,0\n4, 5\nend";
    Separator separator(mat);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BestFirstSearch<Point> *a = new BestFirstSearch<Point>();
    auto t = a->search(searchableMatrix);
    int zibi = 0;
    cout << "BestFirst: " << a->getNumberOfNodesEvaluated() << endl;
}

int main() {
//    IClientHandler* handler = new myClientHandler(new FileCacheManager(7));
//    MySerialServer server;
//    server.open(5432, handler);
    string mat1 = randMat(50, 50) + "\n 50, 50 \n end" ;
    string mat3 = "1,70,100,100 \n 70,100,9,10 \n 100,11,9,2 \n0,0\n2,3\nend";
    string mat = "6,6,9,1,11,3,5,2,4,-1\n-1,-1,3,8,1,3,1,7,4,2\n9,2,2,11,4,8,6,2,1,1\n-1,6,7,5,2,5,2,8,2,2\n1,-1,3,5,2,3,5,9,1,7\n11,7,7,-1,7,1,5,1,2,-1\n6,1,-1,1,6,11,7,3,7,1\n1,9,6,11,11,1,6,3,1,7\n1,5,-1,7,8,11,1,-1,5,4\n8,7,3,1,1,5,11,1,7,8\n 0,0 \n 7, 9 \n end";
    string mat2 = "1, 100, 1, 1, 1, 10 \n 1, 100, 1, 50, 1, 10 \n 1, 1, 10, 20, 1, 10 \n 1, 2, 2, 100, 1, 10 \n 10, 10, 10, 10, 10, 10\n0,0\n4, 5\nend";
    bestTest(mat);
    aStarTest(mat);
    bfsTest(mat);
    dfsTest(mat);
    return 0;
}