//
// Created by HRF on 2023/1/5.
// P138 LibMat类与Book类继承关系
//

#include "libmat.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\n" << "Creating a LibMat object to print()\n";
    LibMat libMat;
    print(libMat);

    cout << "\n" << "Creating a Book object to print()\n";
    Book b("The Castle", "Franz Kafka");
    print(b);

    return 0;
}