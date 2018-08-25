#include <iostream>

using namespace std;

class square{
private:
    char *sq;
public:
    int length;
    
    square(int size = 0): length(size)
    {
        sq=new char(length);
    }
    
    char& operator [](const int& k)
    {
        return sq[k];
    };
    
    
    
    
};

