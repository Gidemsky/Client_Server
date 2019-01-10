#include <iostream>
#include "Separator.h"

#define FILE_NAME_INDEX 1

#include <iostream>
#include <vector>
#include "MySerialServer.h"
//#include "StringReverseCH.h"
#include "FileCacheManager.h"
//#include "MaxtrixBuilder.h"

int main() {
//    MySerialServer s = MySerialServer();
//    CacheManager<Stringable,Stringable>* cacheManager=new FileCacheManager();
//    ClientHandler *c = new StringReverseCH(cacheManager);
//    s.open(5400, c);
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
//    Separator builder = MatrixBuilder();
//    SearchableMatrix searchamat= builder.create(v, start, end);
    return 0;
}