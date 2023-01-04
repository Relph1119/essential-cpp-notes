//
// Created by HRF on 2023/1/4.
// P95 从标准输入读取一串string元素，将它们存到vector内，并进行排序，最后再将这些字符串写回标准输出
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);

    return 0;
}