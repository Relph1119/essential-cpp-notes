//
// Created by HRF on 2023/1/6.
//

#ifndef ESSENTIAL_CPP_PEEKBACK_STACK_H
#define ESSENTIAL_CPP_PEEKBACK_STACK_H

#include "stack.h"

class Peekback_Stack: public Stack {
public:
    Peekback_Stack(int capacity = 0) : _top(0) {
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

    bool peek(int, elemType &);

private:
    vector<elemType> _stack;
    int _top;
};


#endif //ESSENTIAL_CPP_PEEKBACK_STACK_H
