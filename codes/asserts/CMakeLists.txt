project(codes-asserts)

# 第1章
# P5 第一个完整的C++程序
add_executable(as-01-01 ch01/first_demo.cpp)
# P7~P26 数字回答
add_executable(as-01-02 ch01/guess_value.cpp)

# 第2章
# P33 Fibonacci数列的位置询问
add_executable(as-02-01 ch02/answer_fibon_value.cpp)
# P41 Fibonacci数列的位置询问：调用函数
add_executable(as-02-02 ch02/answer_fibon_value2.cpp)
# P41 实现一个可对vector内的整数值加以排序的函数
add_executable(as-02-03 ch02/sort_vector.cpp)
# P53 Fibonacci数列的位置询问：使用局部静态对象
add_executable(as-02-04 ch02/answer_fibon_value3.cpp)
# P55 Fibonacci数列的位置询问：将各个小工作分解成独立函数
add_executable(as-02-05 ch02/answer_fibon_value4.cpp)

# 第3章
# P70 泛型编程：指针的算术运算
add_executable(as-03-01 ch03/generic_find.cpp)
# P75 使用泛型指针
add_executable(as-03-02 ch03/generic_iterator_find.cpp)
# P83 用户给予一个整数vector，必须返回一个新的vector，其中内含原vector之中小于10的所有数值
add_executable(as-03-03 ch03/less_than_10.cpp)
# P87 使用泛型方法，找到小于10的所有数值
add_executable(as-03-04 ch03/filter_ver2.cpp)
add_executable(as-03-05 ch03/filter_ver3.cpp)
# P95 从标准输入读取一串string元素，将它们存到vector内，并进行排序，最后再将这些字符串写回标准输出
add_executable(as-03-06 ch03/iostream_iterator.cpp)

# 第4章
add_executable(as-04-01 ch04/stack.cpp)
# P113 Triangular类的实现
add_executable(as-04-02 ch04/triangular1_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
# P117 使用is_elem()函数
add_executable(as-04-03 ch04/triangular2_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
# P125 实现一个Iterator类
add_executable(as-04-04 ch04/triangular_iterator_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
# P126 实现function object
add_executable(as-04-05 ch04/lessthan_function_object.cpp)
# P129 重载iostream运算符
add_executable(as-04-06 ch04/triangular3_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)

# 第5章
# P138 LibMat类与Book类继承关系
add_executable(as-05-01 ch05/libmat_main.cpp)
# P139 Book类继承关系
add_executable(as-05-02 ch05/book_main.cpp)
# P141 AudioBook继承关系
add_executable(as-05-03 ch05/audiobook_main1.cpp)
# P142 AudioBook继承关系：添加narrator属性
add_executable(as-05-04 ch05/audiobook_main2.cpp)
# P154 num_sequence基类和Fibonacci派生类
add_executable(as-05-05 ch05/v1/fibonacci_main.cpp ch05/v1/fibonacci.cpp ch05/v1/num_sequence.cpp)
# P158 改造num_sequence基类，使其更抽象
add_executable(as-05-06 ch05/v2/fibonacci_main.cpp ch05/v2/fibonacci.cpp ch05/v2/num_sequence.cpp)

# 第6章
# P169~P179 实现二叉树
add_executable(as-06-01 ch06/binary_tree/main.cpp)
# P181~P185 num_sequence类的模板化实现
add_executable(as-06-02 ch06/num_sequence/main.cpp)
# P185~P187 LessThan类模板化实现
add_executable(as-06-03 ch06/lessthan/main.cpp)
# P187~P189 PrintIt类模板化实现
add_executable(as-06-04 ch06/print_it/main.cpp)

# 第7章
# P201 iterator_overflow异常类实现
add_executable(as-07-01 ch07/triangular_iterator_main.cpp ch07/triangular.cpp ch07/triangular_iterator.cpp ch07/iterator_overflow.hpp)