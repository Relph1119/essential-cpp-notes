//
// Created by HRF on 2023/1/5.
// P142
//

#include "libmat.h"
#include <iostream>

using namespace std;

int main() {
    AudioBook ab("Mason and Dixon",
                 "Thomas Pynchon", "Edwin Leonard");

    cout << "The title is " << ab.title() << '\n'
         << "The author is " << ab.author() << '\n'
         << "The narrator is " << ab.narrator() << endl;
    return 0;
}