//
// Created by oriya on 1/3/19.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string rev = problem;
    reverse(rev.begin(), rev.end());
    return rev;
}
