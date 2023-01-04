//
// Created by HRF on 2023/1/3.
// P33 用户可以询问“Fibonacci数列的第八个元素是什么？”，我们的程序应该回答：21
// P41 调用函数
//

#include <iostream>

using namespace std;

bool fibon_elem(int pos, int &elem);

bool print_sequence(int pos);

int main() {

    int pos;
    cout << "Please enter a position: ";
    cin >> pos;

    int elem;
    if (fibon_elem(pos, elem)) {
        cout << "element # " << pos
             << " is " << elem << endl;
        print_sequence(pos);
    } else
        cout << "Sorry. Could not calculate element # " << pos << endl;

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

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "invalid position: " << pos
             << " -- cannot handle request!\n";

        return false;
    }

    cout << "The fibonacci Sequenct for "
         << pos << " positions: \n\t";

    switch (pos) {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
        cout << elem << (!(ix % 10) ? "\n\t" : " ");
    }
    cout << endl;

    return true;
}