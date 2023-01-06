//
// Created by HRF on 2023/1/6.
//
#include <exception>
#include <string>

class StackException : public logic_error {
public:
    StackException(const char *what) : logic_error(what), _what(what) {}
    const char *what() const {return _what.c_str();}
protected:
    string _what;
};

class PopOnEmpty : public StackException {
public:
    PopOnEmpty() : StackException("Pop on Empty Stack") {}
};

class PushOnFull : public StackException {
public:
    PushOnFull() : StackException("Push on Full Stack") {}
};


