//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_SEARCHABLEMATRIX_H
#define UNTITLED9_SEARCHABLEMATRIX_H

#include "Searchable.h"
#include "Matrix.h"
#include "Stringable.h"
#include "Point.h"


class SearchableMatrix : public Searchable<Point>, Stringable {
    Matrix<Point> *matrix;
    unsigned long rows;
    unsigned long columns;
public:
    SearchableMatrix(State<Point> *innitialState, State<Point> *goalState,
                     vector<vector<State<Point> *>> *searchable);

    SearchableMatrix(SearchableMatrix &sm);

    State<Point> *getInitialState() override;

    State<Point> *getGoalState() override;

private:
    string &toString() override;

public:
    virtual vector<State<Point> *> &getAllPossibleStates(State<Point> s);

    Matrix<Point> *getMatrix() const;

    void setMatrix(Matrix<Point> *matrix);

    unsigned long getRows() const;

    void setRows(unsigned long rows);

    unsigned long getColumns() const;

    void setColumns(unsigned long columns);

    ~SearchableMatrix();
};

#endif //UNTITLED9_SEARCHABLEMATRIX_H

