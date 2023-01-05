//
// Created by HRF on 2023/1/5.
//

#include "user_profile.h"
#include <cstdlib>
#include <utility>

inline double UserProfile::guess_average() const {
    return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

UserProfile::UserProfile(string login, uLevel level)
        : _login(std::move(login)), _user_level(level),
          _times_logged(1), _guesses(0), _correct_guesses(0) {}

UserProfile::UserProfile()
        : _login("guest"), _user_level(uLevel::Beginner),
          _times_logged(1), _guesses(0), _correct_guesses(0) {
    static int id = 0;
    char buffer[16];

    _itoa_s(id++, buffer, 10);
    _login += buffer;
}

inline bool UserProfile::operator==(const UserProfile &rhs) {
    if (_login == rhs._login && _user_name == rhs._user_name) {
        return true;
    }
    return false;
}

inline bool UserProfile::operator!=(const UserProfile &rhs) {
    return !(*this == rhs);
}

inline string UserProfile::level() const {
    static string _level_table[] = {
            "Beginner", "Intermediate", "Advanced", "Guru"
    };
    return _level_table[_user_level];
}


map<string, UserProfile::uLevel> UserProfile::_level_map;

void UserProfile::init_level_map() {
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}

inline void UserProfile::reset_level(const string &level) {
    map<string, uLevel>::iterator it;
    if (_level_map.empty())
        init_level_map();

    _user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
}

istream &operator>>(istream &is, UserProfile &rhs) {
    string login, level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;
    rhs.reset_login(login);
    rhs.reset_level(level);

    rhs.reset_login_count(lcount);
    rhs.reset_guess_count(gcount);
    rhs.reset_guess_correct(gcorrect);

    return is;
}

ostream &operator<<(ostream &os, UserProfile &rhs) {
    os << rhs.login() << ' '
       << rhs.level() << ' '
       << rhs.login_count() << ' '
       << rhs.guess_count() << ' '
       << rhs.guess_correct() << ' '
       << rhs.guess_average() << endl;
    return os;
}
