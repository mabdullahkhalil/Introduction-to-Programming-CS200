#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "square.h"

using namespace std;


class game{
    
private:
    square* s1;
    player* players;
    int size;
    
public:
    
    ~game(){};
    
    void settings(int s){
        players= new player[2];
        size=s;
        string name; char sym;
        cout<<"Enter first name of Player 1: ";
        cin>>name; players[0].set_fname(name);
        
        cout<<"Enter second name of the Player 1: ";
        cin>>name; players[0].set_sname(name);
        
        cout<<"Enter the symbol: ";
        cin>>sym;players[0].set_symbol(sym);
        
        cout<<"Enter first name of Player 2: ";
        cin>>name; players[1].set_fname(name);
        
        cout<<"Enter second name of the Player 2: ";
        cin>>name; players[1].set_sname(name);
        
        cout<<"Enter the symbol: ";
        cin>>sym; players[1].set_symbol(sym);
        
    }
    
    
    void start(int i, game obj){
        int check = 0;
        cout<<players[i].get_fname()<<" "<<players[i].get_sname()<<"'s turn."<<endl;
        int r,c;
        cout<<"Row: ";cin>>r;
        cout<<"Column: ";cin>>c;
        r=r-1;c=c-1;

      
        if (i==0) {check=1;}
        else if (i==1){check=0;}
        
        while(obj[r][c]!='-' && obj[r][c]==players[check].get_symbol()){

            cout<<"This place is already filled."<<endl;
            cout<<"Row: ";cin>>r;
            cout<<"Column: "; cin>>c;
            r=r-1;c=c-1;

            obj[r][c]=players[i].get_symbol();
        }
        
        if(obj[r][c]=='-'){
            obj[r][c]=players[i].get_symbol();
        }
        
    }
    
    
    bool checking_rows(game obj, int s,int f){
        int checker=0;
        char x=players[s].get_symbol();
        for(int i=0;i<obj.size;i++){
            checker=0;
            for(int j=0;j<obj.size;j++){
                if(obj[i][j]==x){
                    checker=checker+1;
                    if(checker==f){
                        cout<<players[s].get_fname()<<" "<<players[s].get_sname()<<" wins."<<endl;
                        return false;
                    }
                }
                else
                    checker=0;
            }
        }
        return true;
    }
    
    bool checking_columns(game obj, int s,int f){
        int checker=0;
        char x=players[s].get_symbol();
        for(int i=0;i<obj.size;i++){
            checker=0;
            for(int j=0;j<obj.size;j++){
                if(obj[j][i]==x){
                    checker=checker+1;
                    if(checker==f){
                        cout<<players[s].get_fname()<<" "<<players[s].get_sname()<<" wins."<<endl;
                        return false;
                    }
                }
                else
                    checker=0;
            }
        }
        return true;
    }
    
    
    bool checking_diagnolr(game obj, int s,int f){
        int checker=0;
        char x=players[s].get_symbol();
        for(int i=0;i<obj.size;i++){
                if(obj[i][i]==x){
                    checker=checker+1;
                    if(checker==f){
                        cout<<players[s].get_fname()<<" "<<players[s].get_sname()<<" wins."<<endl;
                        return false;
                    }
                }
                else
                    checker=0;
            
        }
        return true;
    }
    
    bool checking_diagnoll(game obj, int s,int f){
        int checker=0;
        char x=players[s].get_symbol();
        for(int i=0;i<obj.size;i++){
            if(obj[i][obj.size-1-i]==x){
                checker=checker+1;
                if(checker==f){
                    cout<<players[s].get_fname()<<" "<<players[s].get_sname()<<" wins."<<endl;
                    return false;
                }
            }
            else
                checker=0;
            
        }
        return true;
    }
    
    
    
    int r,c;
    game(int i=0, int j=0):r(i), c(j)
    {
        s1= new square[r];
    }
    
    square& operator [](const int& i)
    {
        return s1[i];
    }
    
    
    void printboard(game obj){
        for(int i=0; i<obj.size;i++){
            for(int j=0;j<obj.size;j++){
                cout<<obj[i][j]<<"  ";
            }
            cout<<endl;
        }	
    }    
    
};

