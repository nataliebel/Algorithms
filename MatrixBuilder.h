//
// Created by oriya on 1/10/19.
//

#ifndef UNTITLED9_MAXTRIXBUILDER_H
#define UNTITLED9_MAXTRIXBUILDER_H

#include "SearchableMatrix.h"
#include "Point.h"

class MatrixBuilder{
public:
    SearchableMatrix* create(vector<vector<double > >*matrix,Point* initial,Point* goal);
};
#endif //UNTITLED9_MAXTRIXBUILDER_H
