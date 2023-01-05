//
// Created by HRF on 2023/1/5.
//

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

void fill_stack(Stack &stack, istream &is = cin) {
    string str;
    while (is >> str && !stack.full()) {
        stack.push(str);
    }
    cout << "Read in " << stack.size() << " elements\n";
}
