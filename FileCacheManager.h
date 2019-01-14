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

#define END_OF_PROBLEM "$"
#define END_OF_SOLUTION "@"

class FileCacheManager: public ICacheManager<Stringable,Stringable>{
    map<string,string> data;
    fstream file;
public:
    FileCacheManager(int)   {

    }
    FileCacheManager(){
        loadToMap();
    }

    void save(Stringable* problem,Stringable* solution) override{
        string str_problem = problem->makeString();
        string str_solution = solution->makeString();
        //if problem exists
        if (this->data.count(str_problem)) {
            this->data.at(str_problem) = str_solution;
        } else
            this->data.insert(pair<string, string>(str_problem, str_solution));
    }

    bool isProblemExist(Stringable* problem) override{
        string str_problem = problem->makeString();
        return this->data.count(str_problem) != 0;
    }

    Stringable* search(Stringable* problem) override{
        if (isProblemExist(problem)) {
            return new StringableMatrix(this->data.at(problem->makeString()));
        }
    }

    void loadToMap(){
        this->file = fstream();
        this->file.open("blut.txt", ios::in|ios::out);
        if (!this->file) perror("cannot open file!");
        string line;
        bool isProblem = true;
        string problem;
        string solution;
        while (getline(this->file, line)) {
            if (line == END_OF_SOLUTION) {
                this->data.insert(pair<string, string>(problem, solution));
                isProblem = true;
                problem = "";
                solution = "";
                continue;
            }
            if (line == END_OF_PROBLEM) {
                isProblem = false;
                continue;
            }
            if (isProblem) problem += line;
            else solution += line;
        }
    }
    void saveMap(){
        this->file.open("data.txt", ios::app);
        for (pair<string, string> pr_sl:this->data) {
            saveObjectInFile(pr_sl.first, pr_sl.second);
        }
    }
    void saveObjectInFile(string problem,string solution){
        this->file << problem << endl;
        this->file << END_OF_PROBLEM << endl;
        this->file << solution << endl;
        this->file << END_OF_SOLUTION << endl;
    }
};

#endif //CLIENT_SERVER_FILECHACEMANAGER_H
