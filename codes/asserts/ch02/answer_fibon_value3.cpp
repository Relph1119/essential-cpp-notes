//
// Created by HRF on 2023/1/3.
// P33 用户可以询问“Fibonacci数列的第八个元素是什么？”，我们的程序应该回答：21
// P53 使用局部静态对象
//

#include <iostream>
#include <vector>

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

const vector<int> *fibon_seq(int size) {
    const int max_size = 1024;
    static vector<int> elems;

    if (size <= 0 || size > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can't fulfill request.\n";
    }

    // 如果size等于或小于elems.size()，就不必重新计算了
    for (int ix = elems.size(); ix < size; ++ix) {
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
    }
    return &elems;
}

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "invalid position: " << pos
             << " -- cannot handle request!\n";

        return false;
    }

    cout << "The fibonacci Sequenct for "
         << pos << " positions: \n\t";

    vector<int> vec = *fibon_seq(pos);

    for(int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << (!((ix + 1) % 10) ? "\n\t" : " ");
    }

    cout << endl;

    return true;
}