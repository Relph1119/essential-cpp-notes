//
// Created by HRF on 2023/1/5.
//

#include "stack.h"
#include <iostream>
#include <string>

int main() {
    Stack st;
    string str;

    cout << "Please input a sentence (# to end): \n";
    while (cin >> str && str != "#" && !st.full()) {
        st.push(str);
    }

    if (st.empty()) {
        cout << "\n" << "Oops: no strings were read -- bailing out\n ";
        return 0;
    }

    st.peek(str);
    if (st.size() == 1 && str.empty()) {
        cout << "\n" << "Oops: no strings were read -- bailing out\n ";
        return 0;
    }

    cout << "\n" << "Read in " << st.size() << " strings!\n";
    cin.clear();

    cout << "What word to search for? ";
    cin >> str;

    bool found = st.find(str);
    int count = found? st.count(str) : 0;

    cout << str << (found? " is " : " isn\'t ") << "in the stack. ";
    if (found) {
        cout << "It occurs " << count << " times.\n";
    }

    return 0;
}
