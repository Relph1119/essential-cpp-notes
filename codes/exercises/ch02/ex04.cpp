//
// Created by HRF on 2023/1/4.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


extern bool calc_elements(int &elem, int pos);

const vector<int> *pentagonal_series(int pos);

void display_elem(int elem, int pos, ostream &os = cout);

bool check_pos(int pos);

int main() {
    int pents;
    if (calc_elements(pents, 8))
        display_elem(pents, 8);
    if (calc_elements(pents, 88))
        display_elem(pents, 88);
    if (calc_elements(pents, 12))
        display_elem(pents, 12);
    if (calc_elements(pents, 64))
        display_elem(pents, 64);

    return 0;
}

/**
 * 计算Pentagonal数列的值
 * @param vec
 * @param pos
 * @return
 */
bool calc_elements(int &elem, int pos) {
    if (!check_pos(pos)) {
        elem = 0;
        return false;
    }
    const vector<int> *pents = pentagonal_series(pos);
    elem = (*pents)[pos - 1];
    return true;
}

/**
 * 检验元素个数是否合理
 * @param vec
 * @param pos
 * @return
 */
inline bool check_pos(int pos) {
    if (pos <= 0 || pos > 64) {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    return true;
}

/**
 * Pentagonal数列求值
 * @param vec
 * @param pos
 * @return
 */
const vector<int> *pentagonal_series(int pos) {
    static vector<int> elems;
    if (check_pos(pos) && (pos > elems.size())) {
        for (int ix = elems.size() + 1; ix <= pos; ++ix) {
            elems.push_back((ix * (3 * ix - 1)) / 2);
        }
    }
    return &elems;
}

/**
 * 将给定的vector的所有元素一一打印出来
 * @param vec
 * @param title 存放在vector内的数列的类型
 * @param os
 */
void display_elem(int elem, int pos, ostream &os) {
    os << "element " << pos << " is " << elem << endl;
}