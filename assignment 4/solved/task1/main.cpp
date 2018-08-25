#include <iostream>
#include "operation.h"
#include "stack.h"

//#include <conio.h>
using namespace std;


int main(){
    
    
    operation o;
    stack s;
    
    int input;
    
    while (true) {
        cout<<"``````````````````````````"<<endl;
        cout<<"Press 1 to add."<<endl;
        cout<<"Press 2 to subtract. "<<endl;
        cout<<"Press 3 to multiply."<<endl;
        cout<<"Press 4 to divide."<<endl;
        cout<<"Press 5 to compare."<<endl;
        cout<<"Press 6 to pre-increment."<<endl;
        cout<<"Press 7 to post-increment."<<endl;
        cout<<"Press 8 to pre-decrement."<<endl;
        cout<<"Press 9 to post decrement."<<endl;
        cout<<"Press 10 to pop."<<endl;
        cout<<"Press 11 to print stack. "<<endl;
        cout<<"``````````````````````````"<<endl;
        
        
        cin>>input;
        
        switch (input) {
            case 1:
                o.setpoerandcount(2);
                cin>>o;
                o.add();
                cout<<o;
                s.push(o);
                break;
                
            case 2:
                o.setpoerandcount(2);
                cin>>o;
                o.subtract();
                cout<<o;
                s.push(o);
                break;
                
            case 3:
                o.setpoerandcount(2);
                cin>>o;
                o.multiply();
                cout<<o;
                s.push(o);
                break;
                
            case 4:
                o.setpoerandcount(2);
                cin>>o;
                o.divide();
                cout<<o;
                s.push(o);
                break;
                
            case 5:
                o.setpoerandcount(2);
                cin>>o;
                o.compare();
                cout<<o;
                s.push(o);
                break;
                
            case 6:
                o.setpoerandcount(1);
                o.pre_in();
                cout<<o;
                s.push(o);
                break;
                
            case 7:
                o.setpoerandcount(1);
                o.post_in();
                cout<<o;
                s.push(o);
                break;
                
            case 8:
                o.setpoerandcount(1);
                o.pre_dec();
                cout<<o;
                s.push(o);
                break;
                
            case 9:
                o.setpoerandcount(1);
                o.post_dec();
                cout<<o;
                s.push(o);
                break;
                
            case 10:
                s.pop();
                break;
                
            case 11:
                s.print_stack();
                break;
                
        }
        
        
        
        
    }
    
    
    
}
