//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_MATRIX_H
#define UNTITLED9_MATRIX_H

#include <vector>
#include "Searchable.h"
#include "Point.h"

using namespace std;


template<class T>
class Matrix {
    vector<vector<State<T> *>> *matrix;
public:
    Matrix(vector<vector<State<T> *>> *matrix) {
        this->matrix = matrix;
    }

    Matrix(Matrix &matrix) {
        this->matrix = new vector<vector<State<T> *>>(matrix.getMatrix());
    }

    State<T> *&operator[](Point location) {
        return this->matrix->at(location.getI()).at(location.getJ());
    }

    vector<vector<State<T> *>> *getMatrix() {
        return this->matrix;
    }

    void setMatrix(const vector<vector<State<T>>> &matrix) {
        this->matrix = matrix;
    }

    int getNumOfVertex() {
        return this->matrix->size() * this->matrix->at(0).size();
    }

    int getNumOfRows() {
        return this->matrix->size();
    }

    int getNumOfColumns() {
        return this->matrix->at(0).size();
    }
};


#endif //UNTITLED9_MATRIX_H
