//
// Created by HRF on 2023/1/6.
//

#include "matrix.hpp"

#include <fstream>

int main() {
    Matrix<float> identity(4, 4);
    cout << "identity: " << identity << endl;

    float ar[16] = {
            1., 0., 0., 0., 0., 1., 0., 0.,
            0., 0., 1., 0., 0., 0., 0., 1.};

    for (int i = 0, k = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            identity(i, j) = ar[k++];

    cout << "identity after set: " << identity << endl;

    Matrix<float> m(identity);
    cout << "m: memberwise initialized: " << m << endl;

    Matrix<float> m2(8, 12);
    cout << "m2: 8x12: " << m2 << endl;

    m2 = m;
    cout << "m2 after memberwise assigned to m: " << m2 << endl;

    float ar2[16] = {
            1.3f, 0.4f, 2.6f, 8.2f, 6.2f, 1.7f, 1.3f, 8.3f,
            4.2f, 7.4f, 2.7f, 1.9f, 6.3f, 8.1f, 5.6f, 6.6f};

    Matrix<float> m3(4, 4);

    for (int ix = 0, kx = 0; ix < 4; ++ix)
        for (int j = 0; j < 4; ++j)
            m3(ix, j) = ar2[kx++];

    cout << "m3: assigned random values: " << m3 << endl;

    Matrix<float> m4 = m3 * identity;
    cout << m4 << endl;

    Matrix<float> m5 = m3 + m4;
    cout << m5 << endl;

    m3 += m4;
    cout << m3 << endl;
}