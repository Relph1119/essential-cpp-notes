//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_MATRIX_H
#define ESSENTIAL_CPP_MATRIX_H

#include <iostream>

using namespace std;

typedef float elemType;

class Matrix {
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
public:
    Matrix(const elemType*);
    Matrix(elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.,
           elemType=0., elemType=0., elemType=0., elemType=0.);

    int rows() const {return 4;}
    int cols() const {return 4;}

    ostream & print (ostream &os) const;
    void operator+=(const Matrix &);
    elemType operator()(int row, int column) const {
        return _matrix[row][column];
    }

    elemType & operator()(int row, int column) {
        return _matrix[row][column];
    }

    friend ostream & operator<<(ostream &os, const Matrix &m);
private:
    elemType _matrix[4][4]{};
};

#endif //ESSENTIAL_CPP_MATRIX_H
