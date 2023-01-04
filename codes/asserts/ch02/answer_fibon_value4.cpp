//
// Created by HRF on 2023/1/3.
// P33 用户可以询问“Fibonacci数列的第八个元素是什么？”，我们的程序应该回答：21
// P55 将各个小工作分解成独立函数
//

#include <iostream>
#include <vector>

using namespace std;

bool fibon_elem(int pos, int &elem);

bool print_sequence(int pos);
bool is_size_ok(int size);
const vector<int> *fibon_seq(int size);

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

/**
 * 返回Fibonacci数列中位置为pos的元素
 * 如果程序无法支持该位置上的元素，便返回false
 * @param pos
 * @param elem
 * @return
 */
inline bool fibon_elem(int pos, int &elem) {
    const vector<int> *pseq = fibon_seq(pos);

    if(!pseq) {
        elem = 0;
        return false;
    }

    elem = (*pseq)[pos - 1];
    return true;
}

bool is_size_ok(int size) {
    const int max_size = 1024;
    if (size <= 0 || size > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can't fulfill request.\n";
        return false;
    }
    return true;
}


/**
 * 计算Fibonacci数列中的size个元素，并返回持有这些元素的静态容器地址
 * @param size
 * @return
 */
const vector<int> *fibon_seq(int size) {
    static vector<int> elems;

    if (!is_size_ok(size)) {
        return nullptr;
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

    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << (!((ix + 1) % 10) ? "\n\t" : " ");
    }

    cout << endl;

    return true;
}