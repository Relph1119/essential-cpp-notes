//
// Created by HRF on 2023/1/4.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class LessThan {
public:
    bool operator()(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
};

template<typename T>
void display_vector(const vector<T> &vec, ostream &os = cout, int len = 8) {
    auto iter = vec.begin(), end_it = vec.end();
    int elem_cnt = 1;
    while (iter != end_it) {
        os << *iter++
           << (!(elem_cnt++ % len) ? '\n' : ' ');
    }
    os << endl;
}

int main() {
    ifstream ifile("files/column.txt");
    ofstream ofile("files/MooCat.sort");

    if(!ifile || !ofile) {
        cerr << "Unable to open file -- bailing out!\n";
        return -1;
    }

    vector<string> text;
    string word;

    while (ifile >> word) {
        text.push_back(word);
    }

    sort(text.begin(), text.end(), LessThan());
    display_vector(text, ofile);

    return 0;
}


