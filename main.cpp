#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "StringReverseCH.h"
#include "FileCacheManager.h"
#include "Separator.h"
#include "SearchableMatrix.h"
#include "Searchable.h"



using Point = std::pair<int, int>;


void bfsTest() {
    string str = "1 , 2 , 3|4,5,6|7,8,9|0,1|2,2|   end";
    Separator separator(str);
    Matrix* matrix = separator.matrixCreator();
    Searchable<Point> *searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());

}

void Test() {
    string str = "1 , 2 , 3|4,5,6|7,8,9|0,1|2,2|   end";
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
    Separator separator(str);
    Matrix* matrix = separator.matrixCreator();
    SearchableMatrix* searchableMatrix;
    searchableMatrix = new SearchableMatrix(
            *matrix ,matrix->getP_start(),matrix->getP_goal());
}

int main() {
    Test();
    //bfsTest();
    return 0;
}