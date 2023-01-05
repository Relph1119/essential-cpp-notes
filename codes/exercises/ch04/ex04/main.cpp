//
// Created by HRF on 2023/1/5.
//
#include "user_profile.h"
#include <iostream>

using namespace std;

int main() {
    UserProfile anon;
    cout << anon;

    UserProfile anno_too;
    cout << anno_too;

    UserProfile anna("Annal", UserProfile::Guru);
    cout << anna;
    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();
    cout << anna;

    cin >> anna;
    cout << anna;
    return 0;
}