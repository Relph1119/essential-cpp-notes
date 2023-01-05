//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_FIBONACCI_H
#define ESSENTIAL_CPP_FIBONACCI_H

#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
    explicit Fibonacci(int len = 1, int beg_pos = 1);

    const char *what_am_i() const override { return "Fibonacci"; }

protected:
    void gen_elems(int pos) const override;

    static vector<int> _elems;
};

#endif //ESSENTIAL_CPP_FIBONACCI_H
