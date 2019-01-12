#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "StringReverseCH.h"
#include "FileCacheManager.h"
#include "Separator.h"
#include "SearchableMatrix.h"

using Point = std::pair<int, int>;

int main() {
    string str = "1 , 2 , 3|4,5,6|7,8,9|0,1|2,2|   end";
    MySerialServer s;
    ICacheManager<Stringable,Stringable>* cacheManager=new FileCacheManager();
    ClientHandler *c = new StringReverseCH(cacheManager);
    s.open(5400, c);
//    pthread_exit(NULL);
    vector<vector<double>> v;
    vector<double> myV;
    int j = 0;
    for (double i = 0; i < 3; ++i) {
        for (j; j < 3; ++j) {
            myV.push_back(j);
        }
        v.push_back(myV);
    }
//    Point start = Point(0, 0);
//    Point end = Point(2, 2);
    Separator separator(str);
    Matrix* matrix = separator.matrixCreator();
    SearchableMatrix* searchableMatrix;
    searchableMatrix = new SearchableMatrix(
                matrix->get_data(),matrix->getP_start(),matrix->getP_goal());
    return 0;
}