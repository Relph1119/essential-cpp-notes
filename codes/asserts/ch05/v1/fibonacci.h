//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_FIBONACCI_H
#define ESSENTIAL_CPP_FIBONACCI_H

# include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
    explicit Fibonacci(int len = 1, int beg_pos = 1) : _length(len), _beg_pos(beg_pos) {}

    int elem(int pos) const override;

    const char *what_am_i() const override { return "Fibonacci"; }

    ostream &print(ostream &os = cout) const override;

    int length() const { return _length; }

    int beg_pos() const { return _beg_pos; }

protected:
    void gen_elems(int pos) const override;

    int _length;
    int _beg_pos;
    static vector<int> _elems;
};

#endif //ESSENTIAL_CPP_FIBONACCI_H
