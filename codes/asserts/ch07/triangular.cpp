//
// Created by HRF on 2023/1/5.
//

#include "triangular.h"

Triangular::Triangular() {
    _length = 1;
    _beg_pos = 1;
    _next = 0;
    int elem_cnt = _beg_pos + _length - 1;

    if (_elems.size() < elem_cnt) {
        gen_elements(elem_cnt);
    }
}

Triangular::Triangular(int len, int beg_pos)
: _length(len > 0 ? len : 1),
_beg_pos(beg_pos > 0 ? beg_pos : 1) {
    _next = _beg_pos - 1;
    int elem_cnt = _beg_pos + _length - 1;

    if (_elems.size() < elem_cnt) {
        gen_elements(elem_cnt);
    }
}

Triangular::Triangular(int len) {
    _length = len > 0 ? len : 1;
    _beg_pos = 1;
    _next = 0;
    int elem_cnt = _beg_pos + _length - 1;

    if (_elems.size() < elem_cnt) {
        gen_elements(elem_cnt);
    }
}

int Triangular::elem(int pos) {
    return _elems[pos - 1];
}

bool Triangular::next(int &value) {
    if (_next < _beg_pos + _length - 1) {
        value = _elems[_next++];
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, Triangular &rhs) {
    os << "( " << rhs.beg_pos() << ", " << rhs.length() << " ) ";

    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

Triangular &Triangular::copy(const Triangular &rhs) {
    if (this != &rhs) {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }
    return *this;
}


bool Triangular::is_elem(int value) {
    if (_elems.empty() || _elems[_elems.size() - 1] < value)
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    auto end_it = _elems.end();

    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elements(int length) {
    if (length < 0 || length > _max_elems) {
        cerr << "length invalid!" << endl;
    }

    if (_elems.size() < length) {
        int ix = !_elems.empty() ? (int) _elems.size() + 1 : 1;
        for (; ix <= length; ++ix) {
            _elems.push_back(ix * (ix + 1) / 2);
        }
    }
}

void Triangular::gen_elems_to_value(int value) {
    int ix = (int) _elems.size();
    if (!ix) {
        _elems.push_back(1);
        ix = 1;
    }

    while (_elems[ix - 1] < value && ix < _max_elems) {
        ++ix;
        _elems.push_back(ix * (ix + 1) / 2);
    }

    if (ix == _max_elems) {
        cerr << "Triangular Sequence: oops: value too large "
        << value << " -- exceeds max size of "
        << _max_elems << endl;
    }
}

istream &operator>>(istream &is, Triangular &rhs) {
    char ch1, ch2;
    int bp, len;

    is >> ch1 >> bp
    >> ch2 >> len;

    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();
    return is;
}

Triangular::Triangular(const Triangular &rhs) = default;

Triangular_iterator Triangular::end() const {
    return Triangular_iterator(_beg_pos + _length);
}

Triangular_iterator Triangular::begin() const {
    return Triangular_iterator(_beg_pos);
}

inline void Triangular::display(int length, int beg_pos, ostream &os) {
    Triangular tri(length, beg_pos);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();

    while (it != end_it) {
        os << *it << ' ';
        ++it;
    }
    os << endl;
}