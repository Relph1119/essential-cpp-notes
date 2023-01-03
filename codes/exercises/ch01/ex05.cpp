//
// Created by HRF on 2023/1/3.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string user_name;

    cout << "Please enter your name: ";
    cin >> user_name;

    switch (user_name.size()) {
        case 0:
            cout << "The user name is empty.";
            break;
        case 1:
            cout << "Please enter more characters.";
            break;
        default:
            cout << "Hello, " << user_name
            << "-- happy to make your acquaintance!\n";
            break;
    }

    return 0;
}