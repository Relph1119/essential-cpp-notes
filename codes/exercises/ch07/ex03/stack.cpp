//
// Created by HRF on 2023/1/5.
//

#include "stack.h"
#include "stack_exception.hpp"

void Stack::pop(elemType &elem) {
    if (empty())
        throw PopOnEmpty();
    elem = _stack[--_top];
    _stack.pop_back();
}

void Stack::push(const elemType &elem) {
    if (full())
        throw PushOnFull();
    _stack.push_back(elem);
    ++_top;
}

void Stack::print(ostream &os) const {
    auto rit = _stack.rbegin(), rend = _stack.rend();

    os << "\n\t";
    while (rit !=rend)
        os << *rit++ << "\n\t";

    os << endl;
}