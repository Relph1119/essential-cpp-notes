//
// Created by HRF on 2023/1/5.
//

#include <string>

using namespace std;

class GlobalWrapper {
public:
    static int tests_passed() { return _tests_passed; }

    static int tests_run() { return _tests_run; }

    static int version_number() { return _version_number; }

    static string version_stamp() { return _version_stamp; }

    static string programe_name() { return _programe_name; }

    static void programe_name(const string &npn) { _programe_name = npn; }

    static void version_stamp(const string &nstamp) { _version_stamp = nstamp; }

    static void version_number(int nval) { _version_number = nval; }

    static void tests_run(int nval) { _tests_run = nval; }

    static void tests_passed(int nval) { _tests_passed = nval; }

private:
    static string _programe_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
};

string GlobalWrapper::_programe_name;
string GlobalWrapper::_version_stamp;
int GlobalWrapper::_version_number;
int GlobalWrapper::_tests_run;
int GlobalWrapper::_tests_passed;