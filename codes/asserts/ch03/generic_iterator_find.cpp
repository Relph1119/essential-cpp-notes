//
// Created by HRF on 2023/1/4.
// P75 使用泛型指针
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os = cout) {
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_it = vec.end();

    // 如果vec是空的，iter便等于end_it，于是for循环不会被执行
    for (;iter != end_it; ++iter) {
        os << *iter << ' ';
    }
    os << endl;
}

template<typename IteratorType, typename elemType>
IteratorType my_find(IteratorType first, IteratorType last, const elemType &value) {
    for(; first != last; ++first) {
        if (value == *first)
            return first;
    }
    return last;
}

int main() {
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = my_find(ia, ia+asize, 13);
    if (pia != ia + asize)
        cout << "Found it, with " << *pia << endl;

    vector<int>::iterator it;
    it = my_find(ivec.begin(), ivec.end(), 13);
    if (it != ivec.end())
        cout << "Found it, with " << *it  << endl;

    list<int>::iterator iter;
    iter = my_find(ilist.begin(), ilist.end(), 13);
    if (iter != ilist.end())
        cout << "Found it, with " << *iter << endl;

    return 0;
}