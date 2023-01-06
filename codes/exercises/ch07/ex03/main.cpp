//
// Created by HRF on 2023/1/5.
//
#include "peekback_stack.h"
#include "stack.h"
#include "stack_exception.hpp"
#include <iostream>

using namespace std;

void peek(Stack &st, int index) {
    string t;
    if(st.peek(index, t))
        cout << "peek: " << t;
    else
        cout << "peek failed!";
    cout << endl;
}

// 输入：once upon a time
int main() {
    Stack st;
    string str;
    cout << "Please input a sentence (# to quit): " << endl;
    while (cin >> str && str != "#" && !st.full())
        st.push(str);
    cout << "\n" << "About to call peek() with Stack" << endl;
    peek(st, st.top() - 1);
    cout << st;

    Peekback_Stack pst;
    while (!st.empty()) {
        string t;
        try {
            st.pop(t);
        } catch (PopOnEmpty &poe) {
            cout << poe.what() << endl;
            return -1;
        }
        pst.push(t);
    }

    cout << "About to call peek() with Peekback_Stack" << endl;
    peek(pst, pst.top() - 1);
    cout << pst;

    return 0;
}