//
// Created by HRF on 2023/1/4.
//
#include <iterator>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class EvenElem {
public:
    bool operator()(int elem) {
        return elem % 2 == 0;
    }
};

int main() {
    vector<int> input;
    istream_iterator<int> in(cin), eos;

    copy(in, eos, back_inserter(input));

    ofstream even_file("files/even_file.txt"), odd_file("files/odd_file.txt");

    if (!even_file || !odd_file) {
        cerr << "Oops! Unable to open the output files. Bailing out!";
        return -1;
    }

    ostream_iterator<int> even_iter(even_file, "\n");
    ostream_iterator<int> odd_iter(odd_file, "\n");

    auto division = stable_partition(input.begin(), input.end(), EvenElem());
    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);

    return 0;
}