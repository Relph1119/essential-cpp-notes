//
// Created by HRF on 2023/1/4.
// P83 用户给予一个整数vector，必须返回一个新的vector，其中内含原vector之中小于10的所有数值
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred) {
    while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}

int main() {
    const int elem_size = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for value less than 8\n";
    filter(ia, ia + elem_size, ia2, elem_size, less<int>());

    cout << "filtering integer vector for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());

    return 0;
}
