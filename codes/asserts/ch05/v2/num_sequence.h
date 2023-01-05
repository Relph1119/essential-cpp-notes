//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_NUM_SEQUENCE_H
#define ESSENTIAL_CPP_NUM_SEQUENCE_H

#include <vector>
#include <iostream>

using namespace std;

class num_sequence {
public:
    virtual ~num_sequence() = default;;

    // 返回确切的数列类型
    virtual const char *what_am_i() const = 0;

    // 返回pos位置上的元素
    int elem(int pos) const;

    // 将所有元素写入os
    ostream &print(ostream &os = cout) const;

    int length() const { return _length; }

    int beg_pos() const { return _beg_pos; }

    static int max_elems() { return 64; }

    friend ostream &operator<<(ostream &os, const num_sequence &ns);

protected:
    // 产生直到pos位置的所有元素
    virtual void gen_elems(int pos) const = 0;

    // 检查pos是否为有效位置
    bool check_integrity(int pos, int size) const;

    num_sequence(int len, int bp, vector<int> &re) : _length(len), _beg_pos(bp), _relems(re){}

    int _length;
    int _beg_pos;
    vector<int> &_relems;
};

#endif //ESSENTIAL_CPP_NUM_SEQUENCE_H
