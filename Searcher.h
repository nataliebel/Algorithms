//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SEARCHER_H
#define UNTITLED9_SEARCHER_H

#include <string>
#include "Searchable.h"
#include "Stringable.h"

using namespace std;

template<class T>
class Searcher {
public:
    // the search method

    virtual Stringable *search(Searchable<T> *searchable) = 0;

    virtual // get how many nodes were evaluated by the algorithm
    int getCostOfNodesEvaluated() = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //UNTITLED9_SEARCHER_H
