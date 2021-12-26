//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SOLVERSEARCHER_H
#define UNTITLED9_SOLVERSEARCHER_H

#include "Solver.h"
#include "Searcher.h"
#include "Dfs.h"

class SolverSearcher: public Solver<Searchable<Point>* ,Stringable*>{
    Searcher<Point>* searcher;
public:
    Searcher<Point> *getSearcher() const {
        return searcher;
    }

    void setSearcher(Searcher<Point> *searcher) {
        SolverSearcher::searcher = searcher;
    }

    SolverSearcher(Searcher<Point>* searcher){
        this->searcher=searcher;
    }
    Stringable* solve(Searchable<Point>* searchable) override{
        return this->searcher->search( searchable);
    }
};
#endif //UNTITLED9_SOLVERSEARCHER_H
