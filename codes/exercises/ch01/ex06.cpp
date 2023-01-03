//
// Created by HRF on 2023/1/3.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int array_size = 128;
    int ia[array_size];
    int ival, icnt = 0;
    vector<int> ivec;

    while (cin >> ival && ival != '#' && icnt < array_size) {
        ia[icnt++] = ival;
        ivec.push_back(ival);
    }


    int asum = 0;
    for (int ix = 0; ix < icnt; ++ix) {
        asum += ia[ix];
    }
    int array_average = asum / icnt;
    int vsum = 0;
    for (int val : ivec) {
        vsum += val;
    }
    int vector_average = vsum / icnt;

    cout << "[Vector] Sum of " << ivec.size()
         << " elements: " << vsum
         << ". Average: " << vector_average << endl;
    cout << "[Array] Sum of " << icnt
         << " elements: " << asum
         << ". Average: " << array_average << endl;

    return 0;
}