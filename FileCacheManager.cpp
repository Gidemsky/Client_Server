//
// Created by gideon on 15/01/19.
//

#include "FileCacheManager.h"
#include "StringableMatrix.h"

#define END_OF_PROBLEM "$"
#define END_OF_SOLUTION "@"

FileCacheManager::FileCacheManager() {
    loadToMap();
}

void FileCacheManager::save(Stringable *problem, Stringable *solution) {
    string str_problem = problem->makeString();
    string str_solution = solution->makeString();
    //if problem exists
    if (this->data.count(str_problem)) {
        this->data.at(str_problem) = str_solution;
    } else {
        this->data.insert(pair<string, string>(str_problem, str_solution));

    }
    delete problem;
    delete solution;

}

bool FileCacheManager::isProblemExist(Stringable *problem) {
    string str_problem = problem->makeString();
    return this->data.count(str_problem) != 0;
}

Stringable *FileCacheManager::search(Stringable *problem) {
    if (isProblemExist(problem)) {
        string str = problem->makeString();
        delete problem;
        return new StringableMatrix(this->data.at(str));
    }
}

void FileCacheManager::loadToMap() {
    this->file = fstream();
    this->file.open("problem_solution.txt", ios::in|ios::out);
    if (!this->file) perror("cannot open file!");
    string line;
    bool isProblem = true;
    string problem;
    string solution;
    while (getline(this->file, line)) {
        if (line == END_OF_SOLUTION) {
            problem=problem.substr(0,problem.size()-1);
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
        if (isProblem) problem += line+='\n';
        else solution += line+='\n';
    }
}

void FileCacheManager::saveMap() {
    this->file.open("problem_solution.txt", ios::app);
    for (pair<string, string> pr_sl:this->data) {
        saveObjectInFile(pr_sl.first, pr_sl.second);
    }
}

void FileCacheManager::saveObjectInFile(string problem, string solution) {
    this->file << problem << endl;
    this->file << END_OF_PROBLEM << endl;
    this->file << solution << endl;
    this->file << END_OF_SOLUTION << endl;
}

