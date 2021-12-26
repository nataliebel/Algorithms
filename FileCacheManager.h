//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_FILECACHEMANAGER_H
#define UNTITLED9_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include "CacheManager.h"
#include "Stringable.h"
#include <iostream>

using namespace std;


class FileCacheManager : public CacheManager<Stringable, Stringable> {
    map<string, string> myData;
    string file;
public:
    FileCacheManager();

    void save(Stringable *problem, Stringable *solution) override;

    bool isProblemExist(Stringable *problem) override;

    Stringable *search(Stringable *problem) override;

    void loadToMap();

    void saveMap();

    void saveObjectInFile(string problem, string solution, fstream *stream);

    ~FileCacheManager();
};

#endif //UNTITLED9_FILECACHEMANAGER_H
