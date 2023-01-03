//
// Created by HRF on 2023/1/3.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_name, last_name;
    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Hello, " << first_name
         << "\nPlease enter your last name: ";

    cin >> last_name;

    cout << '\n'
         << "Hello, "
         << first_name << ' ' << last_name
         << " ... and goodbye!\n";
    return 0;
}

