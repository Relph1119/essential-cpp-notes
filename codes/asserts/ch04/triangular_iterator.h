//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H
#define ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H

#include <vector>
#include <iostream>
#include "triangular.h"

using namespace std;

class Triangular;

class Triangular_iterator {
public:
    explicit Triangular_iterator(int index) : _index(index - 1) {}
    bool operator==(const Triangular_iterator &) const;
    bool operator!=(const Triangular_iterator &) const;
    int operator*() const;
    Triangular_iterator &operator++();
    Triangular_iterator operator++(int);
private:
    void check_integrity() const;
    int _index;
    Triangular *_tri;
};

#endif //ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H