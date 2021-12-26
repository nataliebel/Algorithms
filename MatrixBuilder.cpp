//
// Created by oriya on 1/10/19.
//

#include "MatrixBuilder.h"


SearchableMatrix *MatrixBuilder::create(vector<vector<double> > *matrix, Point *initial, Point *goal) {
    int j = 0;
    int i = 0;
    vector<vector<double> > *initial_matrix = matrix;
    double goal_cost = initial_matrix->at(goal->getI()).at(goal->getJ());
    //State<Point> *goalState = new State<Point>(goal, goal_cost);
    double init_cost = initial_matrix->at(initial->getI()).at(initial->getJ());

    vector<vector<State<Point> *>> *searchable = new vector<vector<State<Point> *>>();
    vector<State<Point> *> temp;
    State<Point> *s;
    Point *p;
    for (vector<double> victor:*initial_matrix) {
        for (double cost:victor) {
            //create state
            p = new Point(i, j);
            s = new State<Point>(p, cost);
            temp.push_back(s);
            j++;
        }
        searchable->push_back(temp);
        temp = vector<State<Point> *>();
        j = 0;
        i++;
    }
    State<Point> *innitialState = searchable->at(initial->getI()).at(initial->getJ());
    State<Point> *goalState = searchable->at(goal->getI()).at(goal->getJ());
    SearchableMatrix *searchableMatrix = new SearchableMatrix(innitialState, goalState, searchable);
    return searchableMatrix;
}
