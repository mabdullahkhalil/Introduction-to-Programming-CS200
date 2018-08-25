
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "fraction.h"
using namespace std;

fraction::fraction()
{
    numerator=new int;
    denominator=new int;
}

fraction::fraction(int n, int d){
    numerator=new int;
    denominator=new int;
    *numerator=n;
    *denominator=d;
}

void fraction::set_num(int n){
    numerator= new int;
    * numerator=n;
}


void fraction::set_den(int d){
    denominator= new int;
    *denominator=d;
}

fraction fraction::operator +( fraction frac1)
{
    fraction add;
    *add.numerator= (*numerator*frac1.get_den()) + (*denominator*frac1.get_num());
    *add.denominator= *denominator * frac1.get_den();
    
    return add;
}


fraction fraction::operator -( fraction frac1)
{
    fraction sub;
    *sub.numerator= (*numerator*frac1.get_den()) - (*denominator*frac1.get_num());
    *sub.denominator= *denominator * frac1.get_den();
    
    return sub;
}

fraction fraction::operator *( fraction frac1)
{
    fraction multiply;
    *multiply.numerator= (*numerator * frac1.get_num());
    *multiply.denominator= *denominator * frac1.get_den();
    
    return multiply;
}

fraction fraction::operator /( fraction frac1)
{
    fraction divide;
    *divide.numerator= (*numerator*frac1.get_den());
    *divide.denominator= *denominator * frac1.get_num();
    
    return divide;
}

void fraction::operator =( fraction frac1)
{
    *numerator=frac1.get_num();
    *denominator=frac1.get_den();
};

bool fraction::operator ==( fraction frac1)
{
    
    if(*numerator>frac1.get_num()){
        double n1= *numerator / frac1.get_num();
        double n2= *numerator % frac1.get_num();
        double d1= *denominator / frac1.get_den();
        double d2= *denominator % frac1.get_den();
        if(n1==d1 && n2==0 && d2==0)
        {
            return true;
        }
    }
    else if(*numerator<frac1.get_num()){
        double n1= frac1.get_num() / *numerator ;
        double n2= frac1.get_num() % *numerator ;
        double d1= frac1.get_den() / *denominator ;
        double d2= frac1.get_den() % *denominator;
        if(n1==d1 && n2==0 && d2==0)
        {
            return true;
        }
    }
    else if (*numerator==frac1.get_num() && *denominator==frac1.get_den()){
        return true;
    }
    
    return false;
}

fraction fraction::operator ++()
{
    fraction pre_in;
    *pre_in.numerator= *numerator+*denominator;
    *pre_in.denominator= *denominator;
    
    return pre_in;
}

fraction fraction::operator ++(int y)
{
    fraction post_in;
    *post_in.numerator=*numerator;
    *post_in.denominator=*denominator;
    return post_in;
}
fraction fraction::operator --()
{
    fraction post_dec;
    *post_dec.numerator= (*numerator-*denominator);
    *post_dec.denominator= *denominator;
    
    return post_dec;
}

fraction fraction::operator --(int y)
{
    fraction pre_dec;
    *pre_dec.numerator= *numerator;
    *pre_dec.denominator=*denominator;
    
    return pre_dec;
}

istream & operator >> (istream & is, fraction& frac1){
    cout<<"numerator: ";
    is >> *frac1.numerator;
    cout<<"denominator: ";
    is >> *frac1.denominator;
    return is;
}

ostream & operator << (ostream & os, fraction& frac1){
    os << *frac1.numerator<<"/"<< *frac1.denominator<<endl;
    return os;
}
