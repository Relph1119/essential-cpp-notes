//
// Created by HRF on 2023/1/5.
//

#include "fibonacci.h"

vector<int> Fibonacci::_elems;

void Fibonacci::gen_elems(int pos) const {
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() <= pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix - 2];
        int n_1 = _elems[ix - 1];

        for (; ix < pos; ++ix) {
            int elem = n_2 + n_1;
            _elems.push_back(elem);
            cout << "\ngen_elems: " << elem;
            n_2 = n_1;
            n_1 = elem;
        }
        cout << endl;
    }
}

Fibonacci::Fibonacci(int len, int beg_pos) : num_sequence(len, beg_pos, _elems) {}