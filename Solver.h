//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SOLVER_H
#define UNTITLED9_SOLVER_H

template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};

#endif //UNTITLED9_SOLVER_H
