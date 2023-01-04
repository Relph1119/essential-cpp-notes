//
// Created by HRF on 2023/1/4.
// P83 用户给予一个整数vector，必须返回一个新的vector，其中内含原vector之中小于10的所有数值
//

#include <iostream>
#include <vector>

using namespace std;

bool less_than(int v1, int v2) {
    return v1 < v2;
}

bool greater_than(int v1, int v2) {
    return v1 > v2;
}

vector<int> filter_ver1(const vector<int> &vec, int filter_value, bool(*pred)(int, int)) {
    vector<int> nvec;
    for (int ix : vec) {
        if (pred(ix, filter_value))
            nvec.push_back(ix);
    }
    return nvec;
}

vector<int> less_than_10(const vector<int> &vec) {
    return filter_ver1(vec, 10, less_than);
}

int main() {
    int ia[8] = {1, 1, 2, 3, 5, 8, 11, 13};
    vector<int> ivec(ia, ia + 8);

    vector<int> result = less_than_10(ivec);

    for (int val : result) {
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}
