//
// Created by HRF on 2023/1/6.
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

    virtual bool pop(elemType &) = 0;

    virtual bool push(const elemType &) = 0;

    virtual bool peek(int index, elemType &) = 0;

    virtual int top() const = 0;

    virtual int size() const = 0;

    virtual bool empty() const = 0;

    virtual bool full() const = 0;

    virtual void print(ostream & = cout) const = 0;

    friend ostream &operator<<(ostream &os, const Stack &rhs) {
        rhs.print();
        return os;
    }
};

#endif //ESSENTIAL_CPP_STACK_H
