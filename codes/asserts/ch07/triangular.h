//
// Created by HRF on 2023/1/5.
// P104 实现Triangular，并实现构造函数和析构函数
//

#ifndef ESSENTIAL_CPP_TRIANGULAR_H
#define ESSENTIAL_CPP_TRIANGULAR_H

#include <vector>
#include <iostream>
#include "triangular_iterator.h"

using namespace std;

class Triangular {
    friend class Triangular_iterator;
public:
    typedef Triangular_iterator iterator;

    inline Triangular_iterator begin() const;

    inline Triangular_iterator end() const;

    Triangular();

    explicit Triangular(int len);

    Triangular(int len, int beg_pos);

    Triangular(const Triangular &rhs);

    int length() const { return _length; }

    int beg_pos() const { return _beg_pos; }

    void beg_pos(int bp) { _beg_pos = bp; }

    void length(int len) { _length = len; }

    static int elem(int pos);

    bool next(int &val);

    void next_reset() { _next = _beg_pos - 1; }

    friend ostream &operator<<(ostream &os, Triangular &rhs);

    friend istream &operator>>(istream &is, Triangular &rhs);

    Triangular &copy(const Triangular &rhs);

    static bool is_elem(int value);

    static void gen_elements(int length);

    static void gen_elems_to_value(int value);

    static void display(int length, int beg_pos, ostream &os = cout);

    static int elem_size() { return (int) _elems.size(); }

    static int max_elems() { return _max_elems; }

private:
    // 元素个数
    int _length;
    // 起始位置
    int _beg_pos;
    // 下一个迭代目标
    // 对_next所做的改变并不会破坏class object的常量性
    mutable int _next;
    static const int _max_elems = 1024;
    static vector<int> _elems;
};



#endif //ESSENTIAL_CPP_TRIANGULAR_H
