//
// Created by HRF on 2023/1/6.
//
#include <exception>
#include <sstream>
#include <string>

class iterator_overflow : public exception {
public:
    iterator_overflow(int index, int max) : _index(index), _max(max) {}

    int index() const { return _index; }

    int max() const { return _max; }

    const char *what() const;

private:
    int _index;
    int _max;
};

const char *iterator_overflow::what() const {
    ostringstream ex_msg;
    static string msg;

    // 将输出信息写到内存的ostringstream对象中
    // 将整数值转为字符串表示
    ex_msg << "Internal error: curent index "
           << _index << " exceeds maximum bound: "
           << _max;

    // 获取string对象
    msg = ex_msg.str();

    // 获取const char*表述式
    return msg.c_str();
}

