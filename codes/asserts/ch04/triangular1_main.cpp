//
// Created by HRF on 2023/1/5.
// P113 Triangular类的实现
//

#include <iostream>
#include "triangular.h"

using namespace std;

int sum(Triangular trian) {
    if (!trian.length()) {
        return 0;
    }

    int val, sum = 0;
    trian.next_reset();
    while (trian.next(val)) {
        sum += val;
    }
    return sum;
}

vector<int> Triangular::_elems;

int main() {
    Triangular tri(4);
    cout << tri << " -- sum of elements: " << sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: " << sum(tri2) << endl;

    Triangular tri3(4, 8);
    cout << tri3 << " -- sum of elements: " << sum(tri3) << endl;
    return 0;
}