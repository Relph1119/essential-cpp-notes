//
// Created by HRF on 2023/1/6.
// P187~P189 PrintIt类模板化实现
//
#include "print_it.hpp"
#include <string>

int main() {
    PrintIt<ostream> to_standard_out(cout);
    to_standard_out.print("hello");
    to_standard_out.print(1024);

    string my_string("i am a string");
    to_standard_out.print(my_string);

    return 0;
}