project(codes-asserts)

# 第1章
add_executable(as-01-01 ch01/first_demo.cpp)
add_executable(as-01-02 ch01/guess_value.cpp)

# 第2章
add_executable(as-02-01 ch02/answer_fibon_value.cpp)
add_executable(as-02-02 ch02/answer_fibon_value2.cpp)
add_executable(as-02-03 ch02/sort_vector.cpp)
add_executable(as-02-04 ch02/answer_fibon_value3.cpp)
add_executable(as-02-05 ch02/answer_fibon_value4.cpp)

# 第3章
add_executable(as-03-01 ch03/generic_find.cpp)
add_executable(as-03-02 ch03/generic_iterator_find.cpp)
add_executable(as-03-03 ch03/less_than_10.cpp)
add_executable(as-03-04 ch03/filter_ver2.cpp)
add_executable(as-03-05 ch03/filter_ver3.cpp)
add_executable(as-03-06 ch03/iostream_iterator.cpp)

# 第4章
add_executable(as-04-01 ch04/stack.cpp)
add_executable(as-04-02 ch04/triangular1_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
add_executable(as-04-03 ch04/triangular2_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
add_executable(as-04-04 ch04/triangular_iterator_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)
add_executable(as-04-05 ch04/lessthan_function_object.cpp)
add_executable(as-04-06 ch04/triangular3_main.cpp ch04/triangular.cpp ch04/triangular_iterator.cpp)

# 第5章
add_executable(as-05-01 ch05/libmat_main.cpp)
add_executable(as-05-02 ch05/book_main.cpp)
add_executable(as-05-03 ch05/audiobook_main1.cpp)
add_executable(as-05-04 ch05/audiobook_main2.cpp)
add_executable(as-05-05 ch05/v1/fibonacci_main.cpp ch05/v1/fibonacci.cpp ch05/v1/num_sequence.cpp)
add_executable(as-05-06 ch05/v2/fibonacci_main.cpp ch05/v2/fibonacci.cpp ch05/v2/num_sequence.cpp)

# 第6章
add_executable(as-06-01 ch06/binary_tree/main.cpp)
add_executable(as-06-02 ch06/num_sequence/main.cpp)
add_executable(as-06-03 ch06/lessthan/main.cpp)
add_executable(as-06-04 ch06/print_it/main.cpp)