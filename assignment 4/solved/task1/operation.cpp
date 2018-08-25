#include <stdio.h>
#include<iostream>
#include "operation.h"

using namespace std;

operation::operation(){
    operand= new fraction[2];
    operandCount=0;
    symbol=" ";
}

/*operation::~operation(){
    delete [] operand;
}*/



void operation::add(){
    symbol="+";
    result=operand[0]+operand[1];
}

void operation::subtract(){
    symbol="-";
    result=operand[0]-operand[1];
}

void operation::multiply(){
    symbol="*";
    result=operand[0]*operand[1];
}


void operation::divide(){
    symbol="/";
    result=operand[0]/operand[1];
}


void operation::compare(){
    symbol="==";
    if (operand[0]==operand[1])
    {
        result=operand[0];
    }
    else
    {
        result.set_den(0);
        result.set_num(0);
    }
}

void operation::pre_in(){
    symbol="++";
    cin>>operand[0];
    operand[1].set_num(0); operand[1].set_den(0);
    result= ++operand[0];
}

void operation::post_in(){
    symbol="++";
    cin>>operand[0];
    operand[1].set_num(0); operand[1].set_den(0);

    result= operand[0]++;
}

void operation::pre_dec(){
    symbol="--";
    cin>>operand[0];
    operand[1].set_num(0); operand[1].set_den(0);

    result= --operand[0];
}

void operation::post_dec(){
    symbol="--";
    cin>>operand[0];
    operand[1].set_num(0); operand[1].set_den(0);
    result=operand[0]--;
}


istream & operator >> (istream & is, operation& op1){
    if (op1.operandCount==1) {
        is >> op1.operand[op1.operandCount-1];

    }
    else if (op1.operandCount==2){
        is >> op1.operand[op1.operandCount-2];
        is >> op1.operand[op1.operandCount-1];
    }
    return is;
}

ostream & operator << (ostream & os, operation& op1){
    
    if (op1.operandCount==1) {
        os<<"Symbol: "<<op1.symbol<<endl;
        os<<"Operand 1:  "<<op1.getoperand(0).get_num()<<"/"<<op1.getoperand(0).get_den()<<endl;
        os<<"Result:  "<<op1.getresult().get_num()<<"/"<<op1.getresult().get_den()<<endl;
        
    }
    else if (op1.operandCount==2){
        os<<"Symbol: "<<op1.symbol<<endl;
        os<<"Operand 1:  "<<op1.getoperand(op1.operandCount-2).get_num()<<"/"<<op1.getoperand(op1.operandCount-2).get_den()<<endl;
        os<<"Operand 2:  "<<op1.getoperand(op1.operandCount-1).get_num()<<"/"<<op1.getoperand(op1.operandCount-1).get_den()<<endl;
        os<<"Result:  "<<op1.getresult().get_num()<<"/"<<op1.getresult().get_den()<<endl;
    }
    return os;
}
