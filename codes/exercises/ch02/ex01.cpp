//
// Created by HRF on 2023/1/4.
//

#include <iostream>

using namespace std;

extern bool fibon_elem(int pos, int &elem);

int main() {

    int pos, elem;
    char ch;
    bool more = true;

    while (more) {
        cout << "Please enter a position: ";
        cin >> pos;

        if (fibon_elem(pos, elem))
            cout << "element # " << pos
            << " is " << elem << endl;
        else
            cout << "Sorry. Could not calculate element # " << pos << endl;

        cout << "Would you like to try again? (y/n) ";
        cin >> ch;
        if (ch != 'y' && ch != 'Y') {
            more = false;
        }
    }

    return 0;
}

bool fibon_elem(int pos, int &elem) {
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}