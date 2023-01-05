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

    // 返回pos位置上的元素
    virtual int elem(int pos) const = 0;
    // 返回确切的数列类型
    virtual const char* what_am_i() const = 0;
    // 将所有元素写入os
    virtual ostream & print(ostream &os=cout) const = 0;
    // 返回所支持的最大位置值
    static int max_elems() { return _max_elems;}
    friend ostream & operator<<(ostream &os, const num_sequence &ns);
protected:
    // 产生直到pos位置的所有元素
    virtual void gen_elems(int pos) const = 0;
    // 检查pos是否为有效位置
    bool check_integrity(int pos, int size) const;
    const static int _max_elems = 1024;
};

#endif //ESSENTIAL_CPP_NUM_SEQUENCE_H
