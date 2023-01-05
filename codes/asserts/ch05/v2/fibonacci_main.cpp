//
// Created by HRF on 2023/1/5.
// P154
//

#include "fibonacci.h"
#include <iostream>

using namespace std;

int main() {
    Fibonacci fib;
    cout << "fib: beginning at element 1 for 1 element: "
         << fib << endl;

    Fibonacci fib2(16);
    cout << "fib2: beginning at element 1 for 16 element: "
         << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib3: beginning at element 1 for 16 element: "
         << fib3 << endl;
    return 0;
}