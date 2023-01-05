//
// Created by HRF on 2023/1/5.
// P117 使用is_elem()函数
//

#include <iostream>
#include "triangular.h"

using namespace std;

vector<int> Triangular::_elems;

int main() {
    char ch;
    bool more = true;

    while (more) {
        cout << "Enter value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::is_elem(ival);

        cout << ival
             << (is_elem ? " is " : " is not ")
             << "an element in the Triangular series.\n"
             << "Another value? (y/n) ";

        cin >> ch;
        if (ch == 'n' || ch == 'N') {
            more = false;
        }
    }
    return 0;
}