#include <iostream>
#include <cstring>
#include<cstdlib>
#include<ctime>
#include <string>
#include<sstream> // checked this from internet. took help.
#include <fstream>


using namespace std;

void draw(string l1,string l2,string l3,string l4,string r1,string r2,string r3,string r4);

int main() {
    srand(time(NULL));
    string l1="  ";
    string l2="  ";
    string l3="  ";
    string l4="  "; // elements in the left free cells
    string r1="  ",r2="  ",r3="  ",r4="  "; // elements in the right free cells.
    string cards[52];
    
    string shape[4]={"H","S","C","D"};
    string num[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int m=0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<13; j++)
        {
            cards[m]=num[j]+shape[i];
            m++;
        }
    }
    
    
    string temp;
    int index;
    
    for (int i=0; i<52; i++)
    {
        index = rand() % 52;
        temp=cards[i];
        cards[i]=cards[index];
        cards[index]=temp;
    }
    
    
    
    int arrsize[8]={7,7,7,7,6,6,6,6};
    
    string** array=new string*[8];
    
    for (int i=0; i<8; i++)
    {
        if(i<4){
            array[i]=new string[arrsize[i]];
        }
        else if (i>=4)
        {
            array[i]= new string[arrsize[i]];
        }
    }
    
    for (int i=0; i<7; i++)
    {
        array[0][i]=cards[i];
        array[1][i]=cards[i+7];
        array[2][i]=cards[i+14];
        array[3][i]=cards[i+21];
        if (i<6)
        {
            array[4][i]=cards[i+28];
            array[5][i]=cards[i+34];
            array[6][i]=cards[i+40];
            array[7][i]=cards[i+46];
        }
    }
    
    int number_of_cards_moving=0;
    
    //making dynamic arrays for the home cards.
    int homesize[4]={1,1,1,1};
    string** home= new string*[4];
    home[0]=new string[1];
    home[1]=new string[1];
    home[2]=new string[1];
    home[3]=new string[1];
    
    ifstream inp;
    ofstream of;
    
    // main function
    int maininput;
    cout<<"1. Play the saved game."<<endl;
    cout<<"2. Play a new game."<<endl;
    cin>>maininput;
    bool running=true;
    while (running==true) {
        while (maininput==1 && running==true) {
            inp.open("input.txt");
            for(int j=0;j<8;j++){
                inp>>arrsize[j];
            }
            for (int i=0; i<8; i++) {
                for (int j=0; j<arrsize[i]; j++)
                {
                    inp>>array[i][j];
                }
                cout<<endl;
            }
            
            inp>>l1;inp>>l2;inp>>l3;inp>>l4;inp>>r1;inp>>r2;inp>>r3;inp>>r4;
            
            if (l1=="O") {
                l1="  ";
            }
            if (l2=="O") {
                l2="  ";
            }
            if (l3=="O") {
                l3="  ";
            }
            if (l4=="O") {
                l4="  ";
            }
            if (r1=="O") {
                r1="  ";
            }
            if (r2=="O") {
                r2="  ";
            }
            if (r3=="O") {
                r3="  ";
            }
            if (r4=="O") {
                r4="  ";
            }
            inp.close();
            maininput=2;
        }
        
        
        
        while (maininput==2 && running==true)
        {
            draw(l1,l2,l3,l4,r1,r2,r3,r4); //draw function
            int y=0;
            for (int j=0; j<8; j++) {
                cout<<"    ";
                {
                    if (j<arrsize[0]) {
                        if (array[0][y][1]=='0') {
                            cout<<array[0][y]<<"         ";
                        }
                        else
                            cout<<array[0][y]<<"          ";
                    }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[1]) {
                        if (array[1][y][1]=='0') {
                            cout<<array[1][y]<<"         ";
                        }
                        else
                            cout<<array[1][y]<<"          ";
                    }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[2]) {
                        if (array[2][y][1]=='0') {
                            cout<<array[2][y]<<"         ";
                        }
                        else
                            cout<<array[2][y]<<"          ";
                    }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[3]) {
                        if (array[3][y][1]=='0') {
                            cout<<array[3][y]<<"             ";
                        }
                        else
                            cout<<array[3][y]<<"              ";
                    }
                    else
                        cout<<"                ";
                }
                {
                    if (j<arrsize[4]) {
                        if (array[4][y][1]=='0') {
                            cout<<array[4][y]<<"         ";
                        }
                        else
                            cout<<array[4][y]<<"          ";                }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[5]) {
                        if (array[5][y][1]=='0') {
                            cout<<array[5][y]<<"         ";
                        }
                        else
                            cout<<array[5][y]<<"          ";                }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[6]) {
                        if (array[6][y][1]=='0') {
                            cout<<array[6][y]<<"         ";
                        }
                        else
                            cout<<array[6][y]<<"          ";                }
                    else
                        cout<<"            ";
                }
                {
                    if (j<arrsize[7]) {
                        if (array[7][y][1]=='0') {
                            cout<<array[7][y]<<"         ";
                        }
                        else
                            cout<<array[7][y]<<"          ";                }
                    else
                        cout<<"            ";
                }
                y++;
                cout<<endl;
                
                
            }
            cout<<"____________________________________________"<<endl;
            cout<<"|    Press 1 for column to column move.    |"<<endl;
            cout<<"|    Press 2 for column to free cell move. |"<<endl;
            cout<<"|    Press 3 for free cell to column move. |"<<endl;
            cout<<"|    Press 4 for column to home move.      |"<<endl;
            cout<<"|    Press 5 for free cell to home move.   |"<<endl;
            cout<<"|    Press 6 to save the game.             |"<<endl;
            cout<<"|__________________________________________|"<<endl<<endl;
            
            cout<<"what do u want to do: ";
            int input;
            cin>>input;
            if (input==1)
            {
                //enter the number of cards to be moved
                //enter the column number as source
                //enter the destination column
                
                int source_column,destination_column,cards_moving;
                cout<<"enter the column number as source: "; cin>>source_column;
                cout<<"enter the destination column: "; cin>>destination_column;
                cout<<"enter the number of cards to be moved: "; cin>>cards_moving;
                
                source_column=source_column-1;
                destination_column=destination_column-1;
                
                
                
                if (cards_moving==1 && number_of_cards_moving<5 )
                {
                    string* temporary_destination=new string[arrsize[destination_column]+cards_moving];
                    string* temporary_source=new string[arrsize[source_column]-cards_moving];
                    
                    int u=0;
                    
                    //reading the old array;
                    for (int i=0; i<arrsize[destination_column]; i++)
                    {
                        temporary_destination[u]=array[destination_column][i];
                        u++;
                    }
                    
                    u=u-1;
                    
                    for (int i=0; i<13; i++)
                    {
                        stringstream td1, td2;
                        string cd1, cd2;
                        td1<<temporary_destination[u][0] ;
                        td1>>cd1;
                        td2<<array[source_column][arrsize[source_column]-1][0];
                        td2>>cd2;
                        
                        if (cd1=="1" ) {
                            cd1="10";
                        }
                        if (cd2=="1") {
                            cd2="10";
                        }
                        
                        if (cd1==num[i+1] && cd2==num[i])
                        {
                            if (array[source_column][arrsize[source_column]-1][1]=='H' || array[source_column][arrsize[source_column]-1][1]=='D'||array[source_column][arrsize[source_column]-1][2]=='H' || array[source_column][arrsize[source_column]-1][2]=='D')
                            {
                                if (temporary_destination[u][1]=='S' || temporary_destination[u][1]=='C' || temporary_destination[u][2]=='S' || temporary_destination[u][2]=='C')
                                {
                                    for (int i=0; i<cards_moving; i++)
                                    {
                                        temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                        u--;
                                    }
                                    for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                    {
                                        temporary_source[i]=array[source_column][i];
                                    }
                                    
                                    array[destination_column]=temporary_destination;
                                    array[source_column]=temporary_source;
                                    temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                    temporary_source=NULL;
                                    arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                    arrsize[source_column]=arrsize[source_column]-cards_moving;
                                    i=12;
                                }
                            }
                            else if (array[source_column][arrsize[source_column]-1][1]=='S' || array[source_column][arrsize[source_column]-1][1]=='C' ||array[source_column][arrsize[source_column]-1][2]=='S' || array[source_column][arrsize[source_column]-1][2]=='C')
                            {
                                if (temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' || temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D')
                                {
                                    for (int i=0; i<cards_moving; i++)
                                    {
                                        temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                        u--;
                                    }
                                    for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                    {
                                        temporary_source[i]=array[source_column][i];
                                    }
                                    
                                    array[destination_column]=temporary_destination;
                                    array[source_column]=temporary_source;
                                    temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                    temporary_source=NULL;
                                    arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                    arrsize[source_column]=arrsize[source_column]-cards_moving;
                                    i=12;
                                }
                            }
                        }
                        
                        
                    }
                }
                
                else if (cards_moving==2 && number_of_cards_moving<4)
                {
                    string* temporary_destination=new string[arrsize[destination_column]+cards_moving];
                    string* temporary_source=new string[arrsize[source_column]-cards_moving];
                    
                    int u=0;
                    
                    //reading the old array;
                    for (int i=0; i<arrsize[destination_column]; i++)
                    {
                        temporary_destination[u]=array[destination_column][i];
                        u++;
                        
                    }
                    
                    u=u-1;
                    
                    
                    stringstream s1, s2;
                    string ss1, ss2;
                    s1<<array[source_column][arrsize[source_column]-1][0];
                    s1>>ss1;
                    s2<<array[source_column][arrsize[source_column]-2][0];
                    s2>>ss2;
                    
                    if (ss1=="1" ) {
                        ss1="10";
                    }
                    if (ss2=="1") {
                        ss2="10";
                    }
                    
                    int cardreading=0;
                    
                    for (int i=0; i<13; i++) {
                        if (ss1==num[i] && ss2==num[i+1]) {
                            if (array[source_column][arrsize[source_column]-1][1]=='H' || array[source_column][arrsize[source_column]-1][1]=='D' ||array[source_column][arrsize[source_column]-1][2]=='H' || array[source_column][arrsize[source_column]-1][2]=='D') {
                                if (array[source_column][arrsize[source_column]-2][1]=='S' || array[source_column][arrsize[source_column]-2][1]=='C' || array[source_column][arrsize[source_column]-2][2]=='S' || array[source_column][arrsize[source_column]-2][2]=='C') {
                                    cardreading=cardreading+1;
                                    
                                }
                            }
                            else if (array[source_column][arrsize[source_column]-1][1]=='S' || array[source_column][arrsize[source_column]-1][1]=='C' ||array[source_column][arrsize[source_column]-1][2]=='S' || array[source_column][arrsize[source_column]-1][2]=='C')
                            {
                                if (array[source_column][arrsize[source_column]-2][1]=='H' || array[source_column][arrsize[source_column]-2][1]=='D' || array[source_column][arrsize[source_column]-2][2]=='H' || array[source_column][arrsize[source_column]-2][2]=='D') {
                                    cardreading=cardreading+1;
                                    
                                }
                            }
                        }
                    }
                    
                    
                    
                    
                    if (cardreading==1) {
                        for (int i=0; i<13; i++)
                        {
                            stringstream td1, td2;
                            string cd1, cd2;
                            td1<<temporary_destination[u][0] ;
                            td1>>cd1;
                            td2<<array[source_column][arrsize[source_column]-2][0];
                            td2>>cd2;
                            
                            if (cd1=="1" ) {
                                cd1="10";
                            }
                            if (cd2=="1") {
                                cd2="10";
                            }
                            
                            if (cd1==num[i+1] && cd2==num[i])
                            {
                                cout<<"array[source_column][arrsize[source_column]-2][1] "<<array[source_column][arrsize[source_column]-2][1]<<endl;
                                if (array[source_column][arrsize[source_column]-2][1]=='H' || array[source_column][arrsize[source_column]-2][1]=='D' ||array[source_column][arrsize[source_column]-2][2]=='H' || array[source_column][arrsize[source_column]-2][2]=='D')
                                {
                                    if (temporary_destination[u][1]=='S' || temporary_destination[u][1]=='C' || temporary_destination[u][2]=='S' || temporary_destination[u][2]=='C')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                                else if (array[source_column][arrsize[source_column]-2][1]=='S' || array[source_column][arrsize[source_column]-2][1]=='C' ||array[source_column][arrsize[source_column]-2][2]=='S' || array[source_column][arrsize[source_column]-2][2]=='C')
                                {
                                    if (temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ||temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                            }
                            
                            
                        }
                    }
                    else cout<<"Invalid Move....... "<<endl;
                    
                }
                
                else if (cards_moving==3 && number_of_cards_moving<3)
                {
                    string* temporary_destination=new string[arrsize[destination_column]+cards_moving];
                    string* temporary_source=new string[arrsize[source_column]-cards_moving];
                    
                    int u=0;
                    
                    //reading the old array;
                    for (int i=0; i<arrsize[destination_column]; i++)
                    {
                        temporary_destination[u]=array[destination_column][i];
                        u++;
                        
                    }
                    
                    u=u-1;
                    
                    
                    stringstream s1, s2,s3;
                    string ss1, ss2,ss3;
                    s1<<array[source_column][arrsize[source_column]-1][0];
                    s1>>ss1;
                    s2<<array[source_column][arrsize[source_column]-2][0];
                    s2>>ss2;
                    s3<<array[source_column][arrsize[source_column]-3][0];
                    s3>>ss3;
                    
                    if (ss1=="1" ) {
                        ss1="10";
                    }
                    if (ss2=="1") {
                        ss2="10";
                    }
                    if (ss3=="1") {
                        ss3="10";
                    }
                    
                    string one=array[source_column][arrsize[source_column]-1];
                    string two=array[source_column][arrsize[source_column]-2];
                    string three=array[source_column][arrsize[source_column]-3];
                    
                    int cardreading=0;
                    for (int i=0; i<13; i++) {
                        if (ss1==num[i] && ss2==num[i+1] && ss3==num[i+2])
                        {
                            if (one[1]=='H' || one[1]=='D'||one[2]=='H' || one[2]=='D' )
                            {
                                if (two[1]=='S' || two[1]=='C' || two[2]=='S' || two[2]=='C')
                                {
                                    if (three[1]=='H' || three[1]=='D' || three[2]=='H' || three[2]=='D') {
                                        cardreading=cardreading+1;
                                        i=12;
                                    }
                                }
                            }
                            else if (one[1]=='S' || one[1]=='C' || one[2]=='S' || one[2]=='C')
                            {
                                if (two[1]=='H' || two[1]=='D' || two[2]=='H' || two[2]=='D')
                                {
                                    if (three[1]=='S' || three[1]=='C' || three[2]=='S' || three[2]=='C')
                                    {
                                        cardreading=cardreading+1;
                                        i=12;
                                    }
                                }
                            }
                        }
                    }
                    
                    
                    
                    
                    if (cardreading==1) {
                        for (int i=0; i<13; i++)
                        {
                            stringstream td1, td2;
                            string cd1, cd2;
                            td1<<temporary_destination[u][0] ;
                            td1>>cd1;
                            td2<<array[source_column][arrsize[source_column]-3][0];
                            td2>>cd2;
                            
                            if (cd1==num[i+1] && cd2==num[i])
                            {
                                cout<<"array[source_column][arrsize[source_column]-3][1] "<<array[source_column][arrsize[source_column]-3][1]<<endl;
                                if (three[1]=='H' || three[1]=='D' || three[2]=='H' || three[2]=='D')
                                {
                                    if (temporary_destination[u][1]=='S' || temporary_destination[u][1]=='C' || temporary_destination[u][2]=='S' || temporary_destination[u][2]=='C')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                                if (three[1]=='S' || three[1]=='C' || three[2]=='S' || three[2]=='C')
                                {
                                    if (temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ||temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                            }
                            
                            
                        }
                    }
                    else cout<<"Invalid Move....... "<<endl;
                    
                }
                
                else if (cards_moving==4 && number_of_cards_moving<2)
                {
                    string* temporary_destination=new string[arrsize[destination_column]+cards_moving];
                    string* temporary_source=new string[arrsize[source_column]-cards_moving];
                    
                    int u=0;
                    
                    //reading the old array;
                    for (int i=0; i<arrsize[destination_column]; i++)
                    {
                        temporary_destination[u]=array[destination_column][i];
                        u++;
                        
                    }
                    
                    u=u-1;
                    
                    
                    stringstream s1, s2,s3,s4;
                    string ss1, ss2,ss3,ss4;
                    s1<<array[source_column][arrsize[source_column]-1][0];
                    s1>>ss1;
                    s2<<array[source_column][arrsize[source_column]-2][0];
                    s2>>ss2;
                    s3<<array[source_column][arrsize[source_column]-3][0];
                    s3>>ss3;
                    s4<<array[source_column][arrsize[source_column]-4][0];
                    s4>>ss4;
                    
                    if (ss1=="1" ) {
                        ss1="10";
                    }
                    if (ss2=="1") {
                        ss2="10";
                    }
                    if (ss3=="1") {
                        ss3="10";
                    }
                    if (ss4=="1" ) {
                        ss4="10";
                    }
                    
                    string one=array[source_column][arrsize[source_column]-1];
                    string two=array[source_column][arrsize[source_column]-2];
                    string three=array[source_column][arrsize[source_column]-3];
                    string four=array[source_column][arrsize[source_column]-4];
                    
                    int cardreading=0;
                    for (int i=0; i<13; i++) {
                        if (ss1==num[i] && ss2==num[i+1] && ss3==num[i+2] && ss4==num[i+3])
                        {
                            if (one[1]=='H' || one[1]=='D'||one[2]=='H' || one[2]=='D' )
                            {
                                if (two[1]=='S' || two[1]=='C' || two[2]=='S' || two[2]=='C')
                                {
                                    if (three[1]=='H' || three[1]=='D' || three[2]=='H' || three[2]=='D')
                                    {
                                        if (four[1]=='H' || four[1]=='D' || four[2]=='H' || four[2]=='D')
                                        {
                                            cardreading=cardreading+1;
                                            i=12;
                                        }
                                    }
                                }
                            }
                            else if (one[1]=='S' || one[1]=='C' || one[2]=='S' || one[2]=='C')
                            {
                                if (two[1]=='H' || two[1]=='D' || two[2]=='H' || two[2]=='D')
                                {
                                    if (three[1]=='S' || three[1]=='C' || three[2]=='S' || three[2]=='C')
                                    {
                                        if (four[1]=='H' || four[1]=='D' || four[2]=='H' || four[2]=='D')
                                        {
                                            cardreading=cardreading+1;
                                            i=12;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    
                    
                    
                    if (cardreading==1) {
                        for (int i=0; i<13; i++)
                        {
                            stringstream td1, td2;
                            string cd1, cd2;
                            td1<<temporary_destination[u][0] ;
                            td1>>cd1;
                            td2<<array[source_column][arrsize[source_column]-4][0];
                            td2>>cd2;
                            
                            if (cd1==num[i+1] && cd2==num[i])
                            {
                                cout<<"array[source_column][arrsize[source_column]-3][1] "<<array[source_column][arrsize[source_column]-4][1]<<endl;
                                if ((four[1]=='H' || four[1]=='D' || four[2]=='H' || four[2]=='D'))
                                {
                                    if (temporary_destination[u][1]=='S' || temporary_destination[u][1]=='C' || temporary_destination[u][2]=='S' || temporary_destination[u][2]=='C')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                                else if ((four[1]=='S' || four[1]=='C' || four[2]=='S' || four[2]=='C'))
                                {
                                    if (temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ||temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                            }
                        }
                        
                        
                        
                        
                        
                    }
                    else cout<<"Invalid Move....... "<<endl;
                    
                }
                
                else if (cards_moving==5 && number_of_cards_moving<1)
                {
                    string* temporary_destination=new string[arrsize[destination_column]+cards_moving];
                    string* temporary_source=new string[arrsize[source_column]-cards_moving];
                    
                    int u=0;
                    
                    //reading the old array;
                    for (int i=0; i<arrsize[destination_column]; i++)
                    {
                        //   cout<<"u= "<<u<<endl;
                        temporary_destination[u]=array[destination_column][i];
                        u++;
                        // cout<<"u++ "<<u<<endl;
                        
                    }
                    
                    u=u-1;
                    
                    
                    stringstream s1, s2,s3,s4,s5;
                    string ss1, ss2,ss3,ss4,ss5;
                    s1<<array[source_column][arrsize[source_column]-1][0];
                    s1>>ss1;
                    s2<<array[source_column][arrsize[source_column]-2][0];
                    s2>>ss2;
                    s3<<array[source_column][arrsize[source_column]-3][0];
                    s3>>ss3;
                    s4<<array[source_column][arrsize[source_column]-4][0];
                    s4>>ss4;
                    s5<<array[source_column][arrsize[source_column]-5][0];
                    s5>>ss5;
                    
                    if (ss1=="1" ) {
                        ss1="10";
                    }
                    if (ss2=="1") {
                        ss2="10";
                    }
                    if (ss3=="1") {
                        ss3="10";
                    }
                    if (ss4=="1" ) {
                        ss4="10";
                    }
                    if (ss5=="1" ) {
                        ss5="10";
                    }
                    
                    string one=array[source_column][arrsize[source_column]-1];
                    string two=array[source_column][arrsize[source_column]-2];
                    string three=array[source_column][arrsize[source_column]-3];
                    string four=array[source_column][arrsize[source_column]-4];
                    string five=array[source_column][arrsize[source_column]-5];
                    
                    int cardreading=0;
                    for (int i=0; i<13; i++) {
                        if (ss1==num[i] && ss2==num[i+1] && ss3==num[i+2] && ss3==num[i+3] && ss3==num[i+4])
                        {
                            if (one[1]=='H' || one[1]=='D'||one[2]=='H' || one[2]=='D' )
                            {
                                if (two[1]=='S' || two[1]=='C' || two[2]=='S' || two[2]=='C')
                                {
                                    if (three[1]=='H' || three[1]=='D' || three[2]=='H' || three[2]=='D')
                                    {
                                        if (four[1]=='H' || four[1]=='D' || four[2]=='H' || four[2]=='D')
                                        {
                                            if (five[1]=='H' || five[1]=='D' || five[2]=='H' || five[2]=='D')
                                            {
                                                cardreading=cardreading+1;
                                                i=12;
                                            }
                                        }
                                    }
                                }
                            }
                            else if (one[1]=='S' || one[1]=='C' || one[2]=='S' || one[2]=='C')
                            {
                                if (two[1]=='H' || two[1]=='D' || two[2]=='H' || two[2]=='D')
                                {
                                    if (three[1]=='S' || three[1]=='C' || three[2]=='S' || three[2]=='C')
                                    {
                                        if (four[1]=='H' || four[1]=='D' || four[2]=='H' || four[2]=='D')
                                        {
                                            if (five[1]=='H' || five[1]=='D' || five[2]=='H' || five[2]=='D')
                                            {
                                                cardreading=cardreading+1;
                                                i=12;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    
                    
                    
                    if (cardreading==1) {
                        for (int i=0; i<13; i++)
                        {
                            stringstream td1, td2;
                            string cd1, cd2;
                            td1<<temporary_destination[u][0] ;
                            td1>>cd1;
                            td2<<array[source_column][arrsize[source_column]-5][0];
                            td2>>cd2;
                            
                            if (cd1==num[i+1] && cd2==num[i])
                            {
                                cout<<"array[source_column][arrsize[source_column]-3][1] "<<array[source_column][arrsize[source_column]-5][1]<<endl;
                                if ((five[1]=='H' || five[1]=='D' || five[2]=='H' || five[2]=='D'))
                                {
                                    if (temporary_destination[u][1]=='S' || temporary_destination[u][1]=='C' || temporary_destination[u][2]=='S' || temporary_destination[u][2]=='C')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                                else if ((five[1]=='C' || five[1]=='S' || five[2]=='C' || five[2]=='S'))
                                {
                                    if (temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ||temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D')
                                    {
                                        for (int i=cards_moving-1; i>=0; i--)
                                        {
                                            temporary_destination[u+1]=array[source_column][arrsize[source_column]-i-1];
                                            u++;
                                        }
                                        for (int i=0; i<arrsize[source_column]-cards_moving; i++)
                                        {
                                            temporary_source[i]=array[source_column][i];
                                        }
                                        
                                        array[destination_column]=temporary_destination;
                                        array[source_column]=temporary_source;
                                        temporary_destination=NULL;   //setting the two temorary arrays to NULL;
                                        temporary_source=NULL;
                                        arrsize[destination_column]=arrsize[destination_column]+cards_moving;
                                        arrsize[source_column]=arrsize[source_column]-cards_moving;
                                        i=12;
                                    }
                                }
                            }
                        }
                    }
                    else cout<<"Invalid Move....... "<<endl;
                    
                }
                else
                    cout<<"Invalid movement.... too many cards"<<endl;
                
            }
            
            
            else if (input==2)
            {
                int cols,free_cell;
                cout<<"Enter the column number: "; cin>>cols;
                
                cols=cols-1;
                
                
                
                
                string* temporary_source=new string[arrsize[cols]-1];
                
                for (int i=0; i<arrsize[cols]-1; i++) {
                    temporary_source[i]=array[cols][i];
                }
                bool x=true;
                
                while(x==true)
                {
                    cout<<"Enter the free cell number: "; cin>>free_cell;
                    
                    if (free_cell==1 && l1=="  ")
                    {
                        l1=array[cols][arrsize[cols]-1];
                        x=false;
                        break;
                    }
                    
                    else if (free_cell==2 && l2=="  ")
                    {
                        l2=array[cols][arrsize[cols]-1];
                        x=false;
                        break;
                    }
                    
                    else if (free_cell==3 && l3=="  ")
                    {
                        l3=array[cols][arrsize[cols]-1];
                        x=false;
                        break;
                    }
                    
                    else if (free_cell==4 && l4=="  ")
                    {
                        l4=array[cols][arrsize[cols]-1];
                        x=false;
                        break;
                    }
                    
                    else
                        cout<<"Error: the place is already filled. Retry!"<<endl;
                }
                
                arrsize[cols]=arrsize[cols]-1;
                array[cols]=temporary_source;
                
                temporary_source=NULL;
                
                number_of_cards_moving=number_of_cards_moving+1;
            }
            
            else if (input==3)
            {
                
                if (l1=="  " && l2=="  " && l3=="  " && l4=="  ")
                {
                    cout<<"All the cells are empty. "<<endl;
                }
                else
                {
                    int cols,fc;
                    cout<<"Enter the column number: "; cin>>cols;
                    
                    cols=cols-1;
                    
                    
                    
                    
                    string* temporary_destination=new string[arrsize[cols]+1];
                    int u=0;
                    for (int i=0; i<arrsize[cols]; i++) {
                        temporary_destination[u]=array[cols][i];
                        u++;
                    }
                    u=u-1;
                    bool x=true;
                    
                    while(x==true)
                    {
                        cout<<"Enter the free cell number: "; cin>>fc;
                        
                        stringstream ll1,ll2,ll3,ll4, dt;
                        string check_l1,check_l2,check_l3,check_l4, check_tempporarydest;
                        dt<<temporary_destination[u][0];
                        dt>>check_tempporarydest;
                        ll1<< l1[0];
                        ll1>>check_l1;
                        ll2<< l2[0];
                        ll2>>check_l2;
                        ll3<< l3[0];
                        ll3>>check_l3;
                        ll4<< l4[0];
                        ll4>>check_l4;
                        
                        if (l1=="1") {l1="10";}
                        if (l2=="1") {l2="10";}
                        if (l3=="1") {l3="10";}
                        if (l4=="1") {l4="10";}
                        
                        if (check_tempporarydest=="1") {
                            check_tempporarydest="10";
                        }
                        int checkempty=0;
                        
                        for (int i=0; i<13; i++) {

                            if (fc==1 && l1!="  " && check_l1==num[i] && check_tempporarydest==num[i+1])
                            {
                                if (l1[2]=='S' || l1[1]=='C' || l1[2]=='C' || l1[1]=='S') {
                                    if (temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D' || temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ) {
                                        temporary_destination[u+1]=l1;
                                        l1="  ";i=12;checkempty=1;
                                        arrsize[cols]=arrsize[cols]+1;
                                        array[cols]=temporary_destination;
                                        
                                        temporary_destination=NULL;
                                        x=false;
                                        break;
                                    }
                                }
                                
                            }
                            
                            else if (fc==2 && l2!="  " && check_l2==num[i] && check_tempporarydest==num[i+1])
                            {
                                if (l2[2]=='S' || l2[1]=='C' || l2[2]=='C' || l2[1]=='S') {
                                    if (temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D' || temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ) {
                                        temporary_destination[u+1]=l2;
                                        l2="  ";
                                        x=false;i=12;checkempty=1;
                                        arrsize[cols]=arrsize[cols]+1;
                                        array[cols]=temporary_destination;
                                        
                                        temporary_destination=NULL;
                                        break;
                                    }
                                }
                                
                            }
                            
                            else  if (fc==3 && l3!="  " && check_l3==num[i] && check_tempporarydest==num[i+1])
                            {
                                if (l3[2]=='S' || l3[1]=='C' || l3[2]=='C' || l3[1]=='S') {
                                    if (temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D' || temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ) {
                                        temporary_destination[u+1]=l3;
                                        l3="  ";i=12;checkempty=1;
                                        arrsize[cols]=arrsize[cols]+1;
                                        array[cols]=temporary_destination;
                                        
                                        temporary_destination=NULL;
                                        x=false;
                                        break;
                                    }
                                }
                                
                            }
                            
                            else  if (fc==4 && l4!="  " && check_l4==num[i] && check_tempporarydest==num[i+1])
                            {
                                if (l4[2]=='S' || l4[1]=='C' || l4[2]=='C' || l4[1]=='S') {
                                    if (temporary_destination[u][2]=='H' || temporary_destination[u][2]=='D' || temporary_destination[u][1]=='H' || temporary_destination[u][1]=='D' ) {
                                        temporary_destination[u+1]=l4;
                                        l4="  ";i=12;checkempty=1;
                                        arrsize[cols]=arrsize[cols]+1;
                                        array[cols]=temporary_destination;
                                        
                                        temporary_destination=NULL;
                                        x=false;
                                        break;
                                    }
                                }
                                
                            }
                        }
                        if (checkempty==0) {
                            cout<<"the cell is empty. "<<endl;
                        }
                    }
                    
                number_of_cards_moving=number_of_cards_moving-1;
            }
            }
            else if (input==4)
            {
                int cols,home_cell;
                cout<<"Enter the column number: "; cin>>cols;
                cout<<"Enter the home cell: "; cin>>home_cell;
                
                cols=cols-1;
                home_cell=home_cell-1;
                
                string* temporary_home= new string[homesize[home_cell]+1];
                string* temporary_source=new string[arrsize[cols]-1];
                
                for (int i=0; i<arrsize[cols]-1; i++) {
                    temporary_source[i]=array[cols][i];
                }
                
                int u=0;
                for (int i=0; i<homesize[home_cell]; i++) {
                    temporary_home[u]=home[home_cell][i];
                    u++;
                }
                u=u-1;
                
                int check=0, first=0;
                for (int i=0; i<1;i++)
                {
                    if (array[cols][arrsize[cols]-1][0]=='A' && r1=="  " && home_cell==0)
                    {
                        r1=array[cols][arrsize[cols]-1];
                        temporary_home[u]=array[cols][arrsize[cols]-1];
                        check=1; first=1;
                        arrsize[cols]=arrsize[cols]-1;
                        homesize[home_cell]=homesize[home_cell]+1;
                        
                        array[cols]=temporary_source;
                        home[home_cell]=temporary_home;
                        temporary_home=NULL;
                        temporary_source=NULL;
                    }
                    else if (array[cols][arrsize[cols]-1][0]=='A' && r2=="  " && home_cell==1)
                    {
                        r2=array[cols][arrsize[cols]-1];
                        temporary_home[u]=array[cols][arrsize[cols]-1];
                        check=1;first=1;
                        arrsize[cols]=arrsize[cols]-1;
                        homesize[home_cell]=homesize[home_cell]+1;
                        
                        array[cols]=temporary_source;
                        home[home_cell]=temporary_home;
                        temporary_home=NULL;
                        temporary_source=NULL;
                    }
                    else if (array[cols][arrsize[cols]-1][0]=='A' && r3=="  " && home_cell==2)
                    {
                        r3=array[cols][arrsize[cols]-1];
                        temporary_home[u]=array[cols][arrsize[cols]-1];
                        check=1;first=1;
                        arrsize[cols]=arrsize[cols]-1;
                        homesize[home_cell]=homesize[home_cell]+1;
                        
                        array[cols]=temporary_source;
                        home[home_cell]=temporary_home;
                        temporary_home=NULL;
                        temporary_source=NULL;
                    }
                    else if (array[cols][arrsize[cols]-1][0]=='A' && r4=="  " && home_cell==3)
                    {
                        r4=array[cols][arrsize[cols]-1];
                        temporary_home[u]=array[cols][arrsize[cols]-1];
                        check=1;first=1;
                        arrsize[cols]=arrsize[cols]-1;
                        homesize[home_cell]=homesize[home_cell]+1;
                        
                        array[cols]=temporary_source;
                        home[home_cell]=temporary_home;
                        temporary_home=NULL;
                        temporary_source=NULL;
                    }
                    
                    
                    
                }
                
                
                int check_cards=0;
                if (check==0 && temporary_home[0][0]=='A') {
                    first=1;
                    for (int i=0; i<u+1; i++)
                    {
                        stringstream ca, ct;
                        string check_array, check_temph;
                        ca<< array[cols][arrsize[cols]-1][0];
                        ca>>check_array;
                        ct<<temporary_home[u-1][0];
                        ct>>check_temph;
                        
                        if ((check_temph==num[i]) && check_array==num[i+1]  && temporary_home[u-1][1]==array[cols][arrsize[cols]-1][1])
                        {
                            switch (home_cell)
                            {
                                case 0:
                                    r1=array[cols][arrsize[cols]-1];
                                    temporary_home[u]=array[cols][arrsize[cols]-1];
                                    check_cards=1;
                                    break;
                                case 1:
                                    r2=array[cols][arrsize[cols]-1];
                                    temporary_home[u]=array[cols][arrsize[cols]-1];
                                    check_cards=1;
                                    break;
                                case 2:
                                    r3=array[cols][arrsize[cols]-1];
                                    temporary_home[u]=array[cols][arrsize[cols]-1];
                                    check_cards=1;
                                    break;
                                case 3:
                                    r4=array[cols][arrsize[cols]-1];
                                    temporary_home[u]=array[cols][arrsize[cols]-1];
                                    check_cards=1;
                                    break;
                            }
                            arrsize[cols]=arrsize[cols]-1;
                            homesize[home_cell]=homesize[home_cell]+1;
                            
                            array[cols]=temporary_source;
                            home[home_cell]=temporary_home;
                            temporary_home=NULL;
                            temporary_source=NULL;
                            break;
                            
                        }
                        
                        else if ((check_array==num[i+1]) && check_temph==num[i] && temporary_home[0][1]!=array[cols][arrsize[cols]-1][1])
                        {
                            cout<<"Invalid move: the cards should be of the same shape."<<endl;
                            break;
                            
                        }
                    }
                    if (check_cards==0) {
                        cout<<"Invalid card movement."<<endl;
                    }
                }
                
                if (first==0) {
                    cout<<"Invalid card movement. "<<endl;
                }
                
                
            }
            
            else if (input==5)
            {
                int fc,hc;
                cout<<"Enter the free cell: "; cin>>fc;
                cout<<"Enter the home cell: "; cin>>hc;
                
                hc=hc-1;
                
                string* temph= new string[homesize[hc]+1];
                
                
                
                int u=0;
                for (int i=0; i<homesize[hc]; i++) {
                    temph[u]=home[hc][i];
                    u++;
                }
                u=u-1;
                
                int check=0, first=0;
                for (int i=0; i<1;i++)
                {
                    if (l1[0]=='A' && r1=="  " && hc==0)
                    {
                        r1=l1;
                        temph[u]=l1;
                        check=1; first=1;
                        homesize[hc]=homesize[hc]+1;
                        home[hc]=temph;
                        temph=NULL;
                        l1="  ";
                    }
                    else if (l2[0]=='A' && r2=="  " && hc==1)
                    {
                        r2=l2;
                        temph[u]=l2;
                        check=1; first=1;
                        homesize[hc]=homesize[hc]+1;
                        home[hc]=temph;
                        temph=NULL;
                        l2="  ";
                    }
                    else if (l3[0]=='A' && r3=="  " && hc==2)
                    {
                        r3=l3;
                        temph[u]=l3;
                        check=1; first=1;
                        homesize[hc]=homesize[hc]+1;
                        home[hc]=temph;
                        temph=NULL;
                        l3="  ";
                    }
                    else if (l4[0]=='A' && r4=="  " && hc==3)
                    {
                        r4=l4;
                        temph[u]=l4;
                        check=1; first=1;
                        homesize[hc]=homesize[hc]+1;
                        home[hc]=temph;
                        temph=NULL;
                        l4="  ";
                    }
                    
                    
                    
                }
                
                string left[4]={l1,l2,l3,l4};
                
                int check_cards=0;
                if (check==0 && temph[0][0]=='A') {
                    first=1;
                    for (int i=0; i<u; i++)
                    {
                        stringstream ca, ct;
                        string check_left, check_temph;
                        ca<< left[fc-1][0];
                        ca>>check_left;
                        ct<<temph[u-1][0];
                        ct>>check_temph;
                        
                        if ((check_temph==num[i]) && check_left==num[i+1]  && temph[u-1][1]==left[fc-1][1])
                        {
                            switch (hc)
                            {
                                case 0:
                                    r1=left[fc-1];
                                    temph[u]=left[fc-1];
                                    left[fc-1]="  ";
                                    check_cards=1;
                                    break;
                                case 1:
                                    r2=left[fc-1];
                                    temph[u]=left[fc-1];
                                    check_cards=1;
                                    left[fc-1]="  ";
                                    break;
                                case 2:
                                    r3=left[fc-1];
                                    temph[u]=left[fc-1];
                                    check_cards=1;
                                    left[fc-1]="  ";
                                    break;
                                case 3:
                                    r4=left[fc-1];
                                    temph[u]=left[fc-1];
                                    check_cards=1;
                                    left[fc-1]="  ";
                                    break;
                            }
                            homesize[hc]=homesize[hc]+1;
                            
                            home[hc]=temph;
                            temph=NULL;
                            break;
                            
                        }
                        
                        else if ((check_left==num[i+1]) && check_temph==num[i] && temph[0][1]!=left[fc-1][1])
                        {
                            cout<<"Invalid move: the cards should be of the same shape."<<endl;
                            break;
                            
                        }
                    }
                    if (check_cards==0) {
                        cout<<"Invalid card movement."<<endl;
                    }
                }
                
                if (first==0) {
                    cout<<"Invalid card movement. "<<endl;
                }
                
                number_of_cards_moving=number_of_cards_moving-1;
            }
            
            else if (input==6)
            {
                of.open("input.txt");
                
                for (int j=0; j<8; j++){
                    of<<arrsize[j]<<" ";
                }
                of<<endl;
                
                for (int j=0; j<8; j++) {
                    for (int i=0;i<arrsize[j];i++){
                        of<<array[j][i]<<" ";
                    }
                    of<<endl;
                }
                if (l1=="  ") {
                    l1="O";
                }
                if (l2=="  ") {
                    l2="O";
                }
                if (l3=="  ") {
                    l3="O";
                }
                if (l4=="  ") {
                    l4="O";
                }
                if (r1=="  ") {
                    r1="O";
                }
                if (r2=="  ") {
                    r2="O";
                }
                if (r3=="  ") {
                    r3="O";
                }
                if (r4=="  ") {
                    r4="O";
                }
                
                of<<l1<<endl;
                of<<l2<<endl;
                of<<l3<<endl;
                of<<l4<<endl;
                of<<r1<<endl;
                of<<r2<<endl;
                of<<r3<<endl;
                of<<r4<<endl;
                
                of.close();
                running=false;
                
            }
        }
    }
    
}

/******- - - - - - - - - - - -  - - funtions- - - - - - - - - - -  - -*****/

void draw(string l1,string l2,string l3,string l4,string r1,string r2,string r3,string r4){
    cout<<" ________    ________    ________    ________        ________    ________    ________    ________";
    cout<<endl;
    cout<<"|        | "<<" |        | "<<" |        | "<<" |        | "<<"     "<<"|        |  "<<"|        |  "<<"|        |  "<<"|        |  "<<endl;
    cout<<" "<<l1<<"      "<<"    "<<l2<<"      "<<"     "<<l3<<"      "<<"     "<<l4<<"      "<<"     "<<"      "<<r1<<"      "<<"    "<<r2<<"      "<<"   "<<r3<<"      "<<"     "<<r4<<"      "<<endl;
    cout<<"|        | "<<" |        | "<<" |        | "<<" |        | "<<"     "<<"|        |  "<<"|        |  "<<"|        |  "<<"|        |  "<<endl;
    cout<<"|________| "<<" |________| "<<" |________| "<<" |________| "<<"     "<<"|________|  "<<"|________|  "<<"|________|  "<<"|________|  "<<endl;
    
}
