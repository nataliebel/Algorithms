//
// Created by oriya on 1/13/19.
//

#include <algorithm>
#include "Solution.h"


string &Solution::toString() {
    string * solution=new string();

}

Solution::Solution(vector<State<Point>> *vec) {
    this->vec = vec;
}

string* Solution::getPath(vector<State<Point>*>* pathVec) {
    //Up, Down, Left, Right
    string *path = new string();
    for (int i = 0; i < (pathVec->size() - 1); ++i) {
        int i1 = pathVec->at(i)->getState()->getI();
        int j1 = pathVec->at(i)->getState()->getJ();
        int i2 = pathVec->at(i+1)->getState()->getI();
        int j2 = pathVec->at(i+1)->getState()->getJ();
        if ((i1 == i2) && (j1 == (j2 + 1))) {
            *path += "Right";
        } else if ((i1 == i2) && (j1 == (j2 - 1))) {
            *path += "Left";
        } else if ((i1 == (i2 + 1)) && (j1 == j2)) {
            *path += "Down";
        } else if ((i1 == (i2 - 1)) && (j1 == j2)) {
            *path += "Up";
        }
    }
    reverse(path->begin(), path->end());
    return path;

}
