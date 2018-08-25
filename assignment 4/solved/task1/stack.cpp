//
//  stack.cpp
//  ass4
//
//  Created by Muhammad Abdullah Khalil on 11/24/16.
//  Copyright © 2016 Muhammad Abdullah Khalil. All rights reserved.
//

#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(){
    list= new operation[size+1];
    size=0;
}

/*stack::~stack(){
     delete [] list;
}*/

void stack::push(operation& obj){
    list[size]=obj;
    
    size=size+1;
    
    operation* resize=new operation[size+1];
    for(int i=0;i <size;i++){
        resize[i]=list[i];
    }
    list=resize;
    resize=NULL;
}

void stack::pop(){
    cout<<list[size-1];
}

void stack::print_stack(){
    for (int i=0; i<size; i++)
    {
        cout<<list[i];
        cout<<"\n ```````````````` \n";
    }
}

