//
// Created by HRF on 2023/1/5.
// P141 AudioBook继承关系
//

#include "libmat.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook ab("Man Without Qualities",
                 "Robert Musil", "Kenneth Meyer");
    print(ab);

    return 0;
}