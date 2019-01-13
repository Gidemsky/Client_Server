#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "StringReverseCH.h"
#include "FileCacheManager.h"
#include "Separator.h"
#include "SearchableMatrix.h"
#include "Searchable.h"
#include "BFS.h"
#include "BreadthFirstSearch.h"


using Point = std::pair<int, int>;
string string_mat = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|2,2|end";

void bfsTest() {
    string string_mat1 = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|2,2|end";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BFS<Point> *bfs = new BFS<Point>();
    bfs->search(searchableMatrix);
}

void breadthFirstSearch() {
    string string_mat1 = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|2,2|end";
    Separator separator(string_mat1);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
    BreadthFirstSearch<Point> *breadfs = new BreadthFirstSearch<Point>();
    breadfs->search(searchableMatrix);
}

void Test() {
    string string_mat2 = "1,2,3,4|5,6,7,8|9,10,11,12|13,14,15,16|0,0|2,2|end";
    MySerialServer s = MySerialServer();
    ICacheManager<Stringable,Stringable>* cacheManager=new FileCacheManager();
    ClientHandler *c = new StringReverseCH(cacheManager);
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

int main() {
    //Test();
    //bfsTest();
    breadthFirstSearch();
    return 0;
}