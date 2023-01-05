//
// Created by HRF on 2023/1/6.
//

#include "peekback_stack.h"

void Peekback_Stack::print(ostream &os) const {
    auto rit = _stack.rbegin(), rend = _stack.rend();

    os << "\n\t";
    while (rit != rend)
        os << *rit++ << "\n\t";

    os << endl;
}

bool Peekback_Stack::pop(elemType &elem) {
    if (empty())
        return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool Peekback_Stack::push(const elemType &elem) {
    if (full())
        return false;
    _stack.push_back(elem);
    ++_top;
    return true;
}

bool Peekback_Stack::peek(int index, elemType &elem) {
    if (empty())
        return false;
    if (index < 0 || index >= size())
        return false;
    elem = _stack[index];
    return true;
}