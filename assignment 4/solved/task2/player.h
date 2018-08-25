#include <iostream>
using namespace std;

class player{
    
private:
    string first_name;
    string second_name;
    char symbol;
    
public:
   player(){
        first_name="abdullah";
        second_name="khalil";
        symbol='x';
    }
    string get_fname(){return first_name;}
    string get_sname(){return second_name;}
    char get_symbol(){return symbol;}
    void set_fname(string x){first_name=x;}
    void set_sname(string y){second_name=y;}
    void set_symbol(char z){symbol=z;}
    
};
