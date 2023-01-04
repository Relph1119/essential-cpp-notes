//
// Created by HRF on 2023/1/4.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


extern bool calc_elements(vector<int> &vec, int pos);

void calc_elem(vector<int> &vec, int pos);

void display_elem(vector<int> &vec, const string &title, ostream &os = cout);

bool check_pos(int pos);

int main() {
    vector<int> pents;
    const string title = "Pentagonal Numeric Series";

    if (calc_elements(pents, 0))
        display_elem(pents, title);
    if (calc_elements(pents, 8))
        display_elem(pents, title);
    if (calc_elements(pents, 14))
        display_elem(pents, title);
    if (calc_elements(pents, 138))
        display_elem(pents, title);

    return 0;
}

/**
 * 检验元素个数是否合理
 * @param vec
 * @param pos
 * @return
 */
bool calc_elements(vector<int> &vec, int pos) {
    if (check_pos(pos)) {
        if (vec.size() < pos) {
            calc_elem(vec, pos);
            return true;
        }
    }
    return false;
}

/**
 * 检验元素个数是否合理
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
 * 计算Pentagonal数列的值
 * @param vec
 * @param pos
 * @return
 */
void calc_elem(vector<int> &vec, int pos) {
    for (int ix = vec.size() + 1; ix <= pos; ++ix) {
        vec.push_back((ix * (3 * ix - 1)) / 2);
    }
}

/**
 * 将给定的vector的所有元素一一打印出来
 * @param vec
 * @param title 存放在vector内的数列的类型
 * @param os
 */
void display_elem(vector<int> &vec, const string &title, ostream &os) {
    os << '\n' << title << "\n\t";
    for (int ix : vec) {
        os << ix << ' ';
    }
    os << endl;
}
