//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_MYCLIENTHANDLER_H
#define UNTITLED9_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "string"
#include "Solver.h"
#include "Stringable.h"
#include "CacheManager.h"
#include "Searchable.h"
#include "Dfs.h"
#include "Point.h"

using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<Searchable<Point> *, Stringable *> *solver;
    CacheManager<Stringable, Stringable> *cacheManager;
public:
    MyClientHandler(CacheManager<Stringable, Stringable> *cacheManager);

    vector<vector<double>> &cast_to_num_matrix(vector<string> &matrix_lines);

    Point *lexer_point(string &str);

    void handleClient(int socket) override;

    Solver<Searchable<Point> *, Stringable *> *getSolver() const;

    void setSolver(Solver<Searchable<Point> *, Stringable *> *solver);

    Searchable<Point> *cast_to_matrix(string &problem);

    CacheManager<Stringable, Stringable> *getCacheManager() const;

    string &solveProblem(string &problem);

    void setCacheManager(CacheManager<Stringable, Stringable> *cacheManager);
};

#endif //UNTITLED9_MYCLIENTHANDLER_H


