//
// Created by HRF on 2023/1/5.
//

#ifndef ESSENTIAL_CPP_STACK_H
#define ESSENTIAL_CPP_STACK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string elemType;

class Stack {
public:
    virtual ~Stack() = default;

    explicit Stack(int capacity = 0) : _top(0) {
        if (capacity)
            _stack.reserve(capacity);
    }

    int size() const { return _stack.size(); }

    bool empty() const { return !_top; }

    bool full() const { return size() >= _stack.max_size(); }

    int top() const { return _top; }

    void print(ostream &os = cout) const;

    void pop(elemType &elem);

    void push(const elemType &elem);

    virtual bool peek(int, elemType &){ return false; };

    friend ostream &operator<<(ostream &os, const Stack &rhs) {
        rhs.print();
        return os;
    }

protected:
    vector<elemType> _stack;
private:
    int _top;
};

#endif //ESSENTIAL_CPP_STACK_H
