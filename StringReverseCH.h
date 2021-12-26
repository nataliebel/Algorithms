//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_STRINGREVERSECH_H
#define UNTITLED9_STRINGREVERSECH_H

#include "ClientHandler.h"
#include "Solver.h"
#include "string"
#include "CacheManager.h"
#include "Stringable.h"

using namespace std;

class StringReverseCH : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager<Stringable, Stringable> *cacheManager;
public:
    StringReverseCH(CacheManager<Stringable, Stringable> *cacheManger);

    string solveProblem(string &problem);

    void handleClient(int socket) override;
};

#endif //UNTITLED9_STRINGREVERSECH_H
