//
// Created by oriya on 1/9/19.
//

#include "SearchableMatrix.h"


SearchableMatrix::SearchableMatrix(State<Point> *innitialState, State<Point> *goalState,
                                   vector<vector<State<Point> *>> *searchable) : Searchable(innitialState, goalState,
                                                                                            searchable) {

    this->matrix = new Matrix<Point>(searchable);
    this->columns = this->matrix->getNumOfColumns();
    this->rows = this->matrix->getNumOfRows();
}

State<Point> *SearchableMatrix::getInitialState() {
    return this->innitialState;
}

State<Point> *SearchableMatrix::getGoalState() {
    return this->goalState;
}

vector<State<Point> *> &SearchableMatrix::getAllPossibleStates(State<Point> s) {
    Point *index = s.getState();
    vector<State<Point> *> *victor = new vector<State<Point> *>();
    State<Point> *possible;
    Point location(0, 0);
    //i=column down
    if (index->getI() < this->columns - 1) {
        location = Point(index->getI() + 1, index->getJ());
        possible = (*this->getMatrix())[location];
        if (possible->getCost() != -1) {
            victor->push_back(possible);
        }
    }
    //up
    if (index->getI() > 0) {
        location = Point(index->getI() - 1, index->getJ());
        possible = (*this->getMatrix())[location];
        if (possible->getCost() != -1) {
            victor->push_back(possible);
        }
    }
    //left
    if (index->getJ() > 0) {
        location = Point(index->getI(), index->getJ() - 1);
        possible = (*this->getMatrix())[location];
        if (possible->getCost() != -1) {
            victor->push_back(possible);
        }
    }
    //right
    if (index->getJ() < this->rows - 1) {
        location = Point(index->getI(), index->getJ() + 1);
        possible = (*this->getMatrix())[location];
        if (possible->getCost() != -1) {
            victor->push_back(possible);
        }
    }
    return *victor;
}

Matrix<Point> *SearchableMatrix::getMatrix() const {
    return this->matrix;
}

void SearchableMatrix::setMatrix(Matrix<Point> *matrix) {
    SearchableMatrix::matrix = matrix;
}

string &SearchableMatrix::toString() {
    string *str_matrix;
    for (vector<State<Point> *> line:*this->matrix->getMatrix()) {
        for (State<Point> *node:line) {
            *str_matrix += to_string(node->getCost());
        }
    }
    return *str_matrix;
}

SearchableMatrix::SearchableMatrix(SearchableMatrix &sm) : Searchable(sm) {
    this->matrix = sm.getMatrix();
    this->rows = sm.getMatrix()->getNumOfRows();
    this->columns = sm.getMatrix()->getNumOfColumns();
}

unsigned long SearchableMatrix::getRows() const {
    return rows;
}

void SearchableMatrix::setRows(unsigned long rows) {
    SearchableMatrix::rows = rows;
}

unsigned long SearchableMatrix::getColumns() const {
    return columns;
}

void SearchableMatrix::setColumns(unsigned long columns) {
    SearchableMatrix::columns = columns;
}

 SearchableMatrix:: ~SearchableMatrix() {
    delete (this->matrix);
}
