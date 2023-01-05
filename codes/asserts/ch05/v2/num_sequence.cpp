//
// Created by HRF on 2023/1/5.
//

#include "num_sequence.h"

bool num_sequence::check_integrity(int pos, int size) const {
    if (pos <= 0 || pos > max_elems()) {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }

    if (pos > size) {
        gen_elems(pos);
    }
    return true;
}

ostream &operator<<(ostream &os, const num_sequence &ns) {
    return ns.print(os);
}

int num_sequence::elem(int pos) const {
    if (!check_integrity(pos, _relems.size()))
        return 0;
    if (pos > _relems.size())
        gen_elems(pos);

    return _relems[pos - 1];
}

ostream & num_sequence::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _relems.size()) {
        gen_elems(end_pos);
    }

    os << "( " << beg_pos() << ", " << length() << " ) ";

    while (elem_pos < end_pos) {
        os << _relems[elem_pos++] << ' ';
    }
    os << endl;
    return os;
}
