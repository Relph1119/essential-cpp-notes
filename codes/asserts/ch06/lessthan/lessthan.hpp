//
// Created by HRF on 2023/1/6.
// P186 模板类的LessThan
//
#include <iostream>
#include <algorithm>

using namespace std;

template<typename elemType, typename Comp=less<elemType>>
class LessThanPre {
public:
    explicit LessThanPre(const elemType &val) : _val(val) {}

    bool operator()(const elemType &val) const {
        Comp comp;
        return comp(val, _val);
    }
    void val(const elemType &newval) { _val = newval; }

    elemType val() const { return _val; }

private:
    elemType _val;
};

