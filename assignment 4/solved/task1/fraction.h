//
//  fraction.h
//  ass4
//
//  Created by Muhammad Abdullah Khalil on 11/22/16.
//  Copyright © 2016 Muhammad Abdullah Khalil. All rights reserved.
//

#ifndef fraction_h
#define fraction_h

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class fraction{
private:
    int* numerator;
    int* denominator;
    
public:
    //constructors
    fraction();
    fraction(int n, int d);
    
    ~fraction(){};//destructor

    
    //geterrs and seterrs
   	int get_num(){return *numerator;}
    int get_den(){return *denominator;}
    void set_num(int n);
    void set_den(int d);
    
    // operator overloadings
    fraction operator +( fraction frac1);
    fraction operator -( fraction frac1);
    fraction operator *( fraction frac1);
    fraction operator /( fraction frac1);
    void operator =( fraction frac1);
   	bool operator ==( fraction frac1);
    fraction operator ++();
    fraction operator ++(int n);
    fraction operator --();
    fraction operator --(int y);
    friend istream & operator >>(istream & is,fraction & frac1);
    friend ostream & operator <<(ostream & os,fraction & frac1);
    
};

#endif /* fraction_h */
