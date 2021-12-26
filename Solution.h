//
// Created by oriya on 1/13/19.
//

#ifndef UNTITLED9_SOLUTION_H
#define UNTITLED9_SOLUTION_H

#include "Stringable.h"
#include "SearchableMatrix.h"

class Solution : public Stringable {
    vector<State<Point>> *vec;
public:
    Solution(vector<State<Point>> *vec);

    string &toString() override;

    string *getPath(vector<State<Point> *> *pathVec);
};


#endif //UNTITLED9_SOLUTION_H
