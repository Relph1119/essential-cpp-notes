//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_LIFO_STACK_H
#define ESSENTIAL_CPP_LIFO_STACK_H

#include "stack.h"

class LIFO_Stack : public Stack {
public:
    LIFO_Stack(int capacity = 0) : _top(0) {
        if (capacity)
            _stack.reserve(capacity);
    }

    int size() const { return _stack.size(); }

    bool empty() const { return !_top; }

    bool full() const { return size() >= _stack.max_size(); }

    int top() const { return _top; }

    void print(ostream &os = cout) const;

    bool pop(elemType &elem);

    bool push(const elemType &elem);

    bool peek(int, elemType &) { return false; }

private:
    vector<elemType> _stack;
    int _top;
};

#endif //ESSENTIAL_CPP_LIFO_STACK_H
