//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_MATRIX_H
#define ESSENTIAL_CPP_MATRIX_H

class Matrix {
public:
    Matrix(int row, int col) : _row(row), _col(col) {
        _pmat = new double [row * col];
    }
    Matrix::Matrix(const Matrix &rhs);
    ~Matrix() {
        delete [] _pmat;
    }
    Matrix & operator=(const Matrix &rhs);
private:
    int _row, _col;
    double * _pmat;
};

Matrix::Matrix(const Matrix &rhs): _row(rhs._row), _col(rhs._col) {
    int elem_cnt = _row * _col;
    _pmat = new double [elem_cnt];
    // 成员逐一初始化
    for (int ix = 0; ix < elem_cnt; ++ix) {
        _pmat[ix] = rhs._pmat[ix];
    }
}

Matrix & Matrix::operator=(const Matrix &rhs) {
    if (this != rhs) {
        _row = rhs._row;
        _col = rhs._col;
        int elem_cnt = _row * _col;
        delete [] _pmat;
        _pmat = new double [elem_cnt];
        for (int ix = 0; ix < elem_cnt; ++ix) {
            _pmat[ix] = this._pmat[ix];
        }
    }
    return *this;
}

#endif //ESSENTIAL_CPP_MATRIX_H
