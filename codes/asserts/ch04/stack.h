//
// Created by HRF on 2023/1/5.
// P100 实现stack
// 需求描述：
// （1）基本需求：允许叠放许多数值，并以LIFO的顺序取出，以pushing方式将新数值叠放到堆栈内，并以popping方式取出stack内最后一个被pushed的数值
// （2）询问stack空间是否已满，是否为空
// （3）询问stack的元素个数
// （4）提供查看能力，观察stack内最后一个被pushed的数值
//

#ifndef ESSENTIAL_CPP_STACK_H
#define ESSENTIAL_CPP_STACK_H

#include <string>
#include <vector>

using namespace std;

class Stack {
public:
    bool push(const string &elem);

    bool pop(string &elem);

    bool peek(string &elem);

    bool empty();

    bool full();

    int size() {
        return _stack.size();
    }

private:
    vector<string> _stack;
};

inline bool Stack::empty() {
    return _stack.empty();
}

bool Stack::pop(string &elem) {
    if (empty()) {
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

inline bool Stack::full() {
    return _stack.size() == _stack.max_size();
}

bool Stack::peek(string &elem) {
    if (empty()) {
        return false;
    }

    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full()) {
        return false;
    }

    _stack.push_back(elem);
    return true;
}

#endif //ESSENTIAL_CPP_STACK_H
