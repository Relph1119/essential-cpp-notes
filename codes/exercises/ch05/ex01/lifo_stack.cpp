//
// Created by HRF on 2023/1/5.
//

#include "lifo_stack.h"

bool LIFO_Stack::pop(elemType &elem) {
    if (empty())
        return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool LIFO_Stack::push(const elemType &elem) {
    if (full())
        return false;
    _stack.push_back(elem);
    ++_top;
    return true;
}

void LIFO_Stack::print(ostream &os) const {
    auto rit = _stack.rbegin(), rend = _stack.rend();

    os << "\n\t";
    while (rit !=rend)
        os << *rit++ << "\n\t";

    os << endl;
}