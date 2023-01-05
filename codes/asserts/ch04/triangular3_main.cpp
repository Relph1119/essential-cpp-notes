//
// Created by HRF on 2023/1/5.
// P129 重载iostream运算符
//

#include <iostream>
#include "triangular.h"

using namespace std;

vector<int> Triangular::_elems;

int main() {
    Triangular tri(6, 3);
    cout << tri << '\n';

    Triangular tri2;
    cin >> tri2;

    cout << tri2;
}