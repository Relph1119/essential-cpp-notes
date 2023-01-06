//
// Created by HRF on 2023/1/6.
//

#include <iostream>

using namespace std;

template <typename OutStream>
class PrintIt {
public:
    PrintIt(OutStream &os) : _os(os) {}

    template<typename elemType>
    void print(const elemType &elem, char delimiter = '\n') {
        _os << elem << delimiter;
    }

private:
    OutStream &_os;
};