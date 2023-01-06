//
// Created by HRF on 2023/1/6.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<int len, int beg_pos>
class num_sequence;

template<int len, int beg_pos>
ostream &operator<<(ostream &os, const num_sequence<len, beg_pos> &ns);

template<int len, int beg_pos>
class fibonacci {
public:
    virtual ~fibonacci() = default;;

    int elem(int pos) const;

    const char *what_am_i() const;

    static int max_elems() { return _max_elems; }

    ostream &print(ostream &os = cout) const;

protected:
    virtual void gen_elems(int pos) const = 0;

    bool check_integrity(int pos, int size) const;

    explicit fibonacci(vector<int> *pe) : _pelems(pe) {}

    static const int _max_elems = 1024;
    vector<int> *_pelems;
};

template<int length, int beg_pos = 1>
class Fibonacci : public fibonacci<length, beg_pos> {
public:
    Fibonacci() : fibonacci<length, beg_pos>(&_elems) {}

protected:
    virtual void gen_elems(int pos) const;

    static vector<int> _elems;
};

template<int len, int beg_pos>
ostream &operator<<(ostream &os,
                    const fibonacci<len, beg_pos> &ns) {
    return ns.print(os);
}

template<int len, int beg_pos>
int fibonacci<len, beg_pos>::elem(int pos) const {
    if (!check_integrity(pos, _pelems->size()))
        return 0;

    return (*_pelems)[pos - 1];
}

template<int length, int beg_pos>
const char *fibonacci<length, beg_pos>::what_am_i() const {
    return typeid(*this).name();
}

template<int length, int beg_pos>
bool fibonacci<length, beg_pos>::check_integrity(int pos, int size) const {
    if (pos <= 0 || pos > max_elems()) {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }

    if (pos > size)
        gen_elems(pos);

    return true;
}

template<int length, int beg_pos>
ostream &fibonacci<length, beg_pos>::print(ostream &os) const {
    int elem_pos = beg_pos - 1;
    int end_pos = elem_pos + length;

    if (!check_integrity(end_pos, _pelems->size()))
        return os;

    os << "( "
       << beg_pos << " , "
       << length << " ) ";

    while (elem_pos < end_pos)
        os << (*_pelems)[elem_pos++] << ' ';

    return os;
}

template<int length, int beg_pos>
vector<int> Fibonacci<length, beg_pos>::_elems;

template<int length, int beg_pos>
void Fibonacci<length, beg_pos>::
gen_elems(int pos) const {
    if (pos <= 0 || pos > this->max_elems())
        return;

    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }

    if (_elems.size() < pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix - 2],
                n_1 = _elems[ix - 1];

        int elem;
        for (; ix < pos; ++ix) {
            elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}
