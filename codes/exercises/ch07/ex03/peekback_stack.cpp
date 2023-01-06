//
// Created by HRF on 2023/1/6.
//

#include "peekback_stack.h"

bool Peekback_Stack::peek(int index, elemType &elem) {
    if (empty())
        return false;
    if (index < 0 || index >= size())
        return false;
    elem = _stack[index];
    return true;
}