//
// Created by benda on 08/01/19.
//

#ifndef CLIENT_SERVER_FILECHACEMANAGER_H
#define CLIENT_SERVER_FILECHACEMANAGER_H

#include "ICacheManager.h"
#include <fstream>
#include <map>

#define END_OF_PROBLEM "$"
#define END_OF_SOLUTION "@"

using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public ICacheManager<Problem, Solution> {
    map<string,string> myData;
    fstream file;
public:
    FileCacheManager(){
        loadToMap();
    }
    void save(string problem,string solution){
        string str_problem = problem;
        string str_solution = solution;
        //if problem exists
        if (this->myData.count(str_problem)) {
            this->myData.at(str_problem) = str_solution;
        } else
            this->myData.insert(pair<string, string>(str_problem, str_solution));
    }

    bool isProblemExist(string problem){
        string str_problem = problem;
        return this->myData.count(str_problem) != 0;
    }

    string search(string problem) override{
        if (isProblemExist(problem)) {
            return problem;
        }
    };//TODO:stringable

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
                this->myData.insert(pair<string, string>(problem, solution));
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

    }
    void saveObjectInFile(string problem,string solution){
        this->file << problem << endl;
        this->file << END_OF_PROBLEM << endl;
        this->file << solution << endl;
        this->file << END_OF_SOLUTION << endl;
    }
};

#endif //CLIENT_SERVER_FILECHACEMANAGER_H
