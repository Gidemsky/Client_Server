//
// Created by benda on 08/01/19.
//

#ifndef CLIENT_SERVER_FILECHACEMANAGER_H
#define CLIENT_SERVER_FILECHACEMANAGER_H

#include <map>
#include <fstream>
#include "ICacheManager.h"
#include "Stringable.h"
#include "StringableMatrix.h"
#include <vector>

class FileCacheManager: public ICacheManager<Stringable,Stringable>{
    map<string,string> data;
    fstream file;
    vector<StringableMatrix> stringables;
public:
    FileCacheManager();

    void save(Stringable* problem,Stringable* solution) override;

    bool isProblemExist(Stringable* problem) override;

    Stringable* search(Stringable* problem) override;

    void loadToMap();

    void saveMap();

    void saveObjectInFile(string problem,string solution);

};

#endif //CLIENT_SERVER_FILECHACEMANAGER_H
