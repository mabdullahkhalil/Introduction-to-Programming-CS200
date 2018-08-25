#ifndef operation_h
#define operation_h

#include <iostream>
#include <cstdlib>
#include <string>
#include "fraction.h"

using namespace std;


class operation{
private:
    fraction* operand;
    fraction result;
    int operandCount;
    string symbol;
public:
    operation(); // constructor
    
    ~operation(){}; // destructor
    
    fraction getoperand(int i){return operand[i];}
    fraction getresult(){return result;}
    string getsymbol(){return symbol;}
    void setpoerandcount(int i){operandCount=i;}
    
    // opeator oveloading
    void add();
    void subtract();
    void multiply();
    void divide();
    void post_in();
    void pre_in();
    void post_dec();
    void pre_dec();
    void compare();
    friend istream & operator >>(istream & is,operation& op1);
    friend ostream & operator <<(ostream & os,operation& op1);


};

#endif /* operation_h */
