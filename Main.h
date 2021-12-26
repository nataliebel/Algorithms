//
// Created by oriya on 1/15/19.
//

#ifndef UNTITLED9_MAIN_H
#define UNTITLED9_MAIN_H

#include "Stringable.h"
#include "CacheManager.h"
#include "Server.h"
#include "MyClientHandler.h"
#include "FileCacheManager.h"


class Main {
    FileCacheManager *cacheManager;
    Server *server;
    MyClientHandler *c;
public:
    Main();

    void run();

    int getNumberOfNodesEvaluated(string path);

    ~Main();
};

#endif //UNTITLED9_MAIN_H
