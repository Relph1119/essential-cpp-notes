//
// Created by HRF on 2023/1/6.
// P181~P185 num_sequence类的模板化实现
//

#include "fibonacci.hpp"
#include <iostream>

using namespace std;

int main() {
    Fibonacci<8> fib1;
    Fibonacci<8, 8> fib2;
    Fibonacci<12, 8> fib3;

    cout << "fib1: " << fib1 << '\n'
         << "fib2: " << fib2 << '\n'
         << "fib3: " << fib3 << endl;

    return 0; // quiets vc++
}