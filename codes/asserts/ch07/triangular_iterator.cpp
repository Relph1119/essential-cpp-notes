//
// Created by HRF on 2023/1/5.
//
#include "triangular_iterator.h"
#include "iterator_overflow.hpp"

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
    return _index == rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
    return !(*this == rhs);
}

int Triangular_iterator::operator*() const {
    check_integrity();
    return Triangular::_elems[_index];
}

inline void Triangular_iterator::check_integrity() const {
    if (_index >= Triangular::_max_elems)
        throw iterator_overflow(_index, Triangular::max_elems());

    if (_index >= Triangular::elem_size())
        Triangular::gen_elements(_index + 1);
}

Triangular_iterator &Triangular_iterator::operator++() {
    ++_index;
    check_integrity();
    return *this;
}

Triangular_iterator Triangular_iterator::operator++(int) {
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}