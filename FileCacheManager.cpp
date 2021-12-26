//
// Created by oriya on 1/3/19.
//

#include "FileCacheManager.h"
#include "MyString.h"

#define END_OF_PROBLEM "$"
#define END_OF_SOLUTION "@"
pthread_mutex_t lock;

void FileCacheManager::save(Stringable *problem, Stringable *solution) {
    pthread_mutex_lock(&lock);
    string str_problem = problem->toString();
    string str_solution = solution->toString();
    //if problem exists
    if (this->myData.count(str_problem)) {
        this->myData.at(str_problem) = str_solution;
    } else
        this->myData.insert(pair<string, string>(str_problem, str_solution));
    pthread_mutex_unlock(&lock);
}

bool FileCacheManager::isProblemExist(Stringable *problem) {
    string str_problem = problem->toString();
    return this->myData.count(str_problem) != 0;
}

Stringable *FileCacheManager::search(Stringable *problem) {

    if (isProblemExist(problem)) {

        return new MyString(this->myData.at(problem->toString()));
    }
}

void FileCacheManager::loadToMap() {
    fstream stream;
    stream.open(this->file, ios::in);
    if (!stream) perror("cannot open file!");
    string line;
    bool isProblem = true;
    string problem;
    string solution;
    while (getline(stream, line)) {
        if (line == END_OF_SOLUTION) {
            problem = problem.substr(0, problem.size() - 1);
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
        if (isProblem) problem += line += '\n';
        else solution += line += '\n';
    }
    stream.close();
}

FileCacheManager::FileCacheManager() {
    this->file = "blut.txt";
    loadToMap();
}

void FileCacheManager::saveMap() {
    fstream stream;
    stream.open(this->file, ios::out);
    int counter = 0;
    cout << this->myData.size() << endl;
    for (pair<string, string> pr_sl:this->myData) {
        saveObjectInFile(pr_sl.first, pr_sl.second, &stream);
        cout << counter << endl;
        counter++;
    }
    stream.close();
}

void FileCacheManager::saveObjectInFile(string problem, string solution, fstream *stream) {
    *stream << problem << endl;
    *stream << END_OF_PROBLEM << endl;
    *stream << solution << endl;
    *stream << END_OF_SOLUTION << endl;
    cout << problem << endl;
    cout << solution << endl;
}

FileCacheManager::~FileCacheManager() {
    this->saveMap();
}
