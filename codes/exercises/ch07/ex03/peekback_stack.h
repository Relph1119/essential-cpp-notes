//
// Created by HRF on 2023/1/6.
//

#ifndef ESSENTIAL_CPP_PEEKBACK_STACK_H
#define ESSENTIAL_CPP_PEEKBACK_STACK_H

#include "stack.h"

class Peekback_Stack: public Stack {
public:
    bool peek(int, elemType &) override;
};


#endif //ESSENTIAL_CPP_PEEKBACK_STACK_H
