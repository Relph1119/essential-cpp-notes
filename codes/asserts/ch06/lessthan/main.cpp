//
// Created by HRF on 2023/1/6.
//
#include <iostream>
#include <vector>
#include "lessthan.hpp"

using namespace std;

template<typename elemType>
elemType count_less_than(const vector<elemType> &vec, elemType comp) {
    LessThanPre<elemType> lt(comp);

    int count = 0;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (lt(vec[ix]))
            ++count;
    }
    return count;
}

template<typename elemType>
void print_less_than(const vector<elemType> &vec, elemType comp, ostream &os = cout) {
    LessThanPre<elemType> lt(comp);
    auto iter = vec.begin();
    auto it_end = vec.end();

    os << "elements less than " << lt.val() << endl;
    while ((iter = find_if(iter, it_end, lt)) != it_end) {
        os << *iter << ' ';
        ++iter;
    }
}

int main() {
    int ia[16] = {17, 12, 44, 9, 18, 45, 6, 14,
                  23, 67, 9, 0, 27, 55, 8, 16};
    vector<int> vec(ia, ia + 16);
    int comp_val = 20;

    cout << "Number of elements less than "
         << comp_val << " are "
         << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);
    return 0;
}