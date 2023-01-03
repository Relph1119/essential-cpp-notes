//
// Created by HRF on 2023/1/3.
// P5 第一个完整的C++程序
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string user_name;
    cout << "Please enter your first name: ";
    cin >> user_name;
    cout << '\n'
         << "Hello, "
         << user_name
         << " ... and goodbye!\n";
    return 0;
}
