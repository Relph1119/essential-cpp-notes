//
// Created by HRF on 2023/1/4.
// P70 泛型编程：指针的算术运算
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename elemType>
elemType *find(const elemType *first, const elemType *last, const elemType &value) {
    if (!first || !last)
        return 0;

    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return 0;
}

template<typename elemType>
inline elemType * begin(const vector<elemType> &vec) {
    return vec.empty() ? 0:&vec[0];
}

template<typename elemType>
inline elemType * end(const vector<elemType> &vec) {
    return vec.empty() ? 0:&vec[vec.size() - 1];
}

int main() {
    int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};

    int *pi = find(ia, ia + 8, ia[3]);
    double *pd = find(da, da + 6, da[3]);
    string *ps = find(sa, sa + 4, sa[3]);

    cout << "pa should be 3 -- found: " << *pi << '\n'
         << "pd should be 3.0 -- found: " << *pd << '\n'
         << "ps should be tigger -- found: " << *ps << '\n';

    return 0;
}
