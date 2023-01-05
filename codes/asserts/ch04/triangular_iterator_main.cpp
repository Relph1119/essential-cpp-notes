//
// Created by HRF on 2023/1/5.
// P125 实现一个Iterator类
//

#include "triangular_iterator.h"
#include <iostream>

vector<int> Triangular::_elems;

int main() {
    Triangular tri(20);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();

    cout << "Triangular Series of " << tri.length() << " elements\n";
//    cout << tri << endl;
    while (it != end_it) {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;

    return 0;
}