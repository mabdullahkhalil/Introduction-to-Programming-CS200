#ifndef stack_h
#define stack_h

#include <iostream>
#include "operation.h"
using namespace std;


class stack{
    
private:
    operation* list;
    int size;
    
public:
    stack();
    ~stack(){};
    
    void push(operation& obj);
    void pop();
    void print_stack();
    
};

#endif /* stack_h */
