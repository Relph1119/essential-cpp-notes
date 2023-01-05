//
// Created by HRF on 2023/1/5.
//

#include "stack.h"

bool Stack::pop(elemType &elem) {
    if (empty())
        return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool Stack::push(const elemType &elem) {
    if (full())
        return false;
    _stack.push_back(elem);
    ++_top;
    return true;
}

void Stack::print(ostream &os) const {
    auto rit = _stack.rbegin(), rend = _stack.rend();

    os << "\n\t";
    while (rit !=rend)
        os << *rit++ << "\n\t";

    os << endl;
}