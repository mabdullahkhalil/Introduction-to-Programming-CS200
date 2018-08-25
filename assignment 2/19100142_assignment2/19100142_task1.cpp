#include <iostream>
using namespace std;

int instructions(); // function to print out instructions/menu
void seat_b(string array_b[][4]);    // for the business class
void seat_e(string array_e[][4]);   // for the economy class
void reserve(string array[][4],string name,string seat_row[],int seat_col[],int business);    // for reserving seat for input 1.
int check_name(string array[], string arrayy[], string name,int business,int economy); // check that the same name is not reported
int check_roll(int array[], int arrayy[], int roll_num,int business,int economy); // check that the same rollnumber is not reported again
void seating_plan(string people_b[][4], string people_e[][4]);   // view seating plan
void cancel_seat(string name,string name_b[], string name_e[],int roll_num,int roll_b[], int roll_e[],int seat_b_col[],string seat_b_row[], int seat_e_col[], string seat_e_row[], string people_b[][4],string people_e[][4]);
void change_seat(string name,string name_b[], string name_e[],int roll_num,int roll_b[], int roll_e[],int seat_b_col[],string seat_b_row[], int seat_e_col[], string seat_e_row[], string people_b[][4],string people_e[][4],int a, int business);

int main()
{
    
    string people_b[3][4]={{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"}};                                                                         //seats in business class
    string people_e[7][4]={{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"}}; // seats in economy class
    string clas,name;
    string name_b[12]={"x","x","x","x","x","x","x","x","x","x","x","x"};                                                               // names of people in business class.
    int roll_b[12]={0,0,0,0,0,0,0,0,0,0,0,0};                                                                                          // roll numbers of people in business class.
    string name_e[28]={"x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x"};/* names of people in economy class */
    int roll_e[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};                                                        // roll numbers of poeple in economy class
    string seat_b_row[12];              // storing the rows against each entry in business class
    int seat_b_col[12];                // storing the cols against each entry in business class
    string seat_e_row[28];            // storing the rows against each entry in economy class
    int seat_e_col[28];              // storing the cols against each entry in economy class
    
    int input;
    int roll_num;
    int business=0;
    int economy=0;
    int n_out=0;
    
    input=instructions();
    
    while (input!=-1)
    {
        if (input==1)
        {
            
            int ch=0;
            for (int i=0; i<7; i++)
            {
                for (int j=0; j<4; j++)
                {
                    if (people_e[i][j]!="*")
                    {
                        ch++;
                    }
                }
            }
            for (int i=0; i<7; i++)
            {
                for (int j=0; j<4; j++)
                {
                    if (people_e[i][j]!="*")
                    {
                        ch++;
                    }
                }
            }
            
            
            if (ch!=40)
            {
                cout<<"Enter B for Business class or E for economy class : ";
                cin>>clas;
                
                if (clas=="b" || clas=="B")
                {
                    int ch=0;
                    for (int i=0; i<3; i++)
                    {
                        for (int j=0; j<4; j++) {
                            if (people_b[i][j]!="*") {
                                ch++;
                            }
                        }
                    }
                    if (ch!=12)
                    {
                        
                        cout<<"Please enter your Name : ";
                        cin>>name;
                        name_b[business]=name;
                        n_out=check_name(name_b, name_e, name,business,economy);
                        while (n_out==0)
                        {
                            cout<<"Please enter your Name again : ";
                            cin>>name;
                            n_out=check_name(name_b, name_e, name,business,economy);
                            
                        }
                        
                        n_out=0;
                        cout<<"Please enter your roll number : ";
                        cin>>roll_num;
                        roll_b[business]=roll_num;
                        n_out=check_roll(roll_b, roll_e, roll_num,business,economy);
                        while (n_out==0)
                        {
                            cout<<"Please enter your roll number again : ";
                            cin>>roll_num;
                            n_out=check_roll(roll_b, roll_e, roll_num,business,economy);
                            
                        }
                        
                        
                        seat_b(people_b);
                        reserve(people_b,name,seat_b_row,seat_b_col,business);
                        business++;
                    }
                    else if (ch==12)
                    {
                        cout<<"the business class is full. Next flight Leaves Tomorrow. "<<endl;
                    }
                    
                    
                }
                else if (clas=="e" || clas=="E")
                {
                    int ch=0;
                    for (int i=0; i<7; i++)
                    {
                        for (int j=0; j<4; j++)
                        {
                            if (people_e[i][j]!="*")
                            {
                                ch++;
                            }
                        }
                    }
                    
                    if (ch!=28)
                    {
                        cout<<"Please enter your Name : ";
                        cin>>name;
                        name_e[economy]=name;
                        n_out=check_name(name_b, name_e, name,business,economy);
                        while (n_out==0)
                        {
                            cout<<"Please enter your Name again : ";
                            cin>>name;
                            n_out=check_name(name_b, name_e, name,business,economy);
                            
                        }
                        
                        n_out=0;
                        cout<<"Please enter your roll number : ";
                        cin>>roll_num;
                        roll_e[economy]=roll_num;
                        n_out=check_roll(roll_b, roll_e, roll_num,business,economy);
                        while (n_out==0)
                        {
                            cout<<"Please enter your roll number again : ";
                            cin>>roll_num;
                            n_out=check_roll(roll_b, roll_e, roll_num,business,economy);
                            
                        }
                        
                        seat_e(people_e);
                        reserve(people_e,name,seat_e_row,seat_e_col,economy);
                        economy++;
                    }
                    
                    else if (ch==28)
                    {
                        cout<<"Economy class is Full. next flight leaves Tomorrow. "<<endl;
                    }
                    
                }
                
                
            }
            else if (ch==40)
            {
                cout<<"Next FLight Leaves Tomorrow. Byeee Byeee. "<<endl;
            }
        }
        
        else if (input==2)
        {
            
            int a;
            cout<<"1. press 1 if you want to change seat within business class. "<<endl;
            cout<<"2. press 2 if u want to change from economy to business class. "<<endl;
            cin>>a;
            
            cout<<"Enter your name: ";
            cin>>name;
            
            cout<<"enter your roll number: ";
            cin>>roll_num;
            
            change_seat(name, name_b,name_e,roll_num,roll_b,roll_e, seat_b_col, seat_b_row,seat_e_col,seat_e_row,people_b,people_e,a,business);
        }
        
        else if (input==3)
        {
            cout<<"Enter your name : ";
            cin>>name;
            
            cout<<"Enter your roll number : ";
            cin>>roll_num;
            
            cancel_seat(name, name_b,name_e,roll_num,roll_b,roll_e, seat_b_col, seat_b_row,seat_e_col,seat_e_row,people_b,people_e);
        }
        
        else if (input==4)                                      //input 4
        {
            seating_plan(people_b, people_e);
            
        }
        
        else if (input==5)
        {
            cout<<"Enter your name : ";
            cin>>name;
            
            cout<<"Enter your roll number : ";
            cin>>roll_num;
            
            // checking for business people
            for (int i=0; i<12; i++)
            {
                
                if (name==name_b[i] && roll_num==roll_b[i]) {
                    cout<<"Your seat number is "<<seat_b_row[i]<<"."<<seat_b_col[i]+1<<" in business class. "<<endl;
                }
            }
            
            //checking for economy people
            for (int j=0; j<28; j++)
            {
                if (name==name_e[j] && roll_num==roll_e[j]) {
                    cout<<"Your seat number is "<<seat_e_row[j]<<"."<<seat_e_col[j]+1<<" in economy class. "<<endl;
                }
            }
            
            
        }
        
        input=instructions();
    }
    
    if (input==-1) {
        cout<<"****** exiting program ******"<<endl;
    }
}


// function to print out the instructions
int instructions()
{
    cout<<"-------------------------------------------"<<endl;
    cout<<"*********** [instructions] ****************"<<endl;
    cout<<"*   1.Reserve a seat.                     *"<<endl;
    cout<<"*   2.Change already reserved seat.       *"<<endl;
    cout<<"*   3.Cancel already reserved seat.       *"<<endl;
    cout<<"*   4.View seating plan.                  *"<<endl;
    cout<<"*   5.Seek Help.                          *"<<endl;
    cout<<"*   Press -1 to exit                      *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"Enter your choice : ";
    int input;
    cin>>input;
    return input;
    
}

// function to print the plan for economy class

void seat_e(string array_e[][4])
{
    cout<<endl;
    cout<<"::::: Current Seating Plan of Economy Class ::::::"<<endl;
    cout<<endl;
    cout<<"        [1]    [2]    [3]     [4]"<<endl;
    cout<<endl;
    for (int i=0; i<7; i++)
    {
        cout<<"[B"<<i+1<<"]"<<"     ";
        for (int j=0; j<4; j++)
        {
            cout<<array_e[i][j]<<"      ";
        }
        cout<<endl;
    }
}



// for the business class
void seat_b(string array_b[][4])
{
    cout<<endl;
    cout<<"::::: Current Seating Plan of Business Class ::::::"<<endl;
    cout<<endl;
    cout<<"        [1]    [2]    [3]     [4]"<<endl;
    cout<<endl;
    for (int i=0; i<3; i++)
    {
        cout<<"[A"<<i+1<<"]"<<"     ";
        for (int j=0; j<4; j++)
        {
            cout<<array_b[i][j]<<"      ";
        }
        cout<<endl;
    }
}


//function for the reservation
void reserve(string array[][4],string name,string seat_row[],int seat_col[],int business)
{
    
    string roww;
    int col;
    
    cout<<"Enter row: ";
    cin>>roww;
    
    int row=roww[0]-49;
    
    cout<<"Enter col: ";
    cin>>col;
    col=col-1;
    
    while (array[row][col]=="o")
    {
        cout<<"Sorry "<<name<<", Seat number "<<roww<<"."<<col+1<<" is already reserved."<<endl;
        
        cout<<"Enter row: ";
        cin>>roww;
        
        row=roww[0]-49;
        
        cout<<"Enter col: ";
        cin>>col;
        col=col-1;
        
    }
    
    
    while (array[row][col]=="*")
    {
        array[row][col]="o";
        cout<<"Dear "<<name<<", Seat number "<<roww<<"."<<col+1<<" has been successfully reserved for you."<<endl;
        
    }
    
    seat_row[business]=roww;
    seat_col[business]=col;
    
}

// function for checking name that one person has only one reervation
int check_name(string array[], string arrayy[], string name,int business,int economy)
{
    // checking for business people
    int m=1;
    for (int i=0; i<12; i++)
    {
        if (name==array[i] && i!= business)
        {
            cout<<"ERROR!! there is already a reservation against this name"<<endl;
            m=0;
            return m;
        }
    }
    
    //checking for economy people
    for (int j=0; j<28; j++)
    {
        if (name==arrayy[j] && j!=economy)
        {
            cout<<"ERROR!! there is already a reservation against this name"<<endl;
            m=0;
            return m;
        }
    }
    return m;
}

// function for checking roll number that one person has only one reervation
int check_roll(int array[], int arrayy[], int roll_num,int business,int economy)
{
    // checking for business people
    int m=1;
    for (int i=0; i<12; i++)
    {
        if (roll_num==array[i] && i!= business)
        {
            cout<<"ERROR!! there is already a reservation against this name"<<endl;
            m=0;
            return m;
        }
    }
    
    //checking for economy people
    for (int j=0; j<28; j++)
    {
        if (roll_num==arrayy[j] && j!=economy)
        {
            cout<<"ERROR!! there is already a reservation against this name"<<endl;
            m=0;
            return m;
        }
    }
    return m;
}

// function to shoe all the seating plan of the plane
void seating_plan(string people_b[][4], string people_e[][4])
{
    cout<<endl;
    cout<<endl;
    cout<<"        [1]    [2]    [3]     [4]"<<endl;
    cout<<endl;
    for (int i=0; i<3; i++)
    {
        cout<<"[A"<<i+1<<"]"<<"     ";
        for (int j=0; j<4; j++)
        {
            cout<<people_b[i][j]<<"      ";
        }
        cout<<endl;
    }
    
    
    cout<<endl;
    for (int i=0; i<7; i++)
    {
        cout<<"[B"<<i+1<<"]"<<"     ";
        for (int j=0; j<4; j++)
        {
            cout<<people_e[i][j]<<"      ";
        }
        cout<<endl;
    }
}

//function to cancel the seat
void cancel_seat(string name,string name_b[], string name_e[],int roll_num,int roll_b[], int roll_e[],int seat_b_col[],string seat_b_row[], int seat_e_col[], string seat_e_row[], string people_b[][4],string people_e[][4])
{
    
    // checking for business people
    for (int i=0; i<12; i++)
    {
        
        if (name==name_b[i] && roll_num==roll_b[i]) {
            name_b[i]="x";
            roll_b[i]=0;
            string m=seat_b_row[i];
            int q=m[0]-49;
            people_b[q][seat_b_col[i]]="*";
            cout<<"Your seat number "<<seat_b_row[i]<<"."<<seat_b_col[i]+1<<" is cancelled. "<<endl;
        }
    }
    
    //checking for economy people
    for (int j=0; j<28; j++)
    {
        if (name==name_e[j] && roll_num==roll_e[j]) {
            name_e[j]="x";
            roll_e[j]=0;
            string m=seat_e_row[j];
            int q=m[0]-49;
            people_e[q][seat_e_col[j]]="*";
            cout<<"Your seat number "<<seat_e_row[j]<<"."<<seat_e_col[j]+1<<" is cancelled. "<<endl;
        }
    }
    
}

//function to change the seat
void change_seat(string name,string name_b[], string name_e[],int roll_num,int roll_b[], int roll_e[],int seat_b_col[],string seat_b_row[], int seat_e_col[], string seat_e_row[], string people_b[][4],string people_e[][4],int a,int business)
{
    if (a==1)
    {
        
        int v=0;
        int h=0;
        
        for (int i=0; i<12; i++)
        {
            
            if (name==name_b[i] && roll_num==roll_b[i])
            {
                h=i;
                v=1;
                string m=seat_b_row[i];
                int q=m[0]-49;
                people_b[q][seat_b_col[i]]="*";
                cout<<"Your seat number "<<seat_b_row[i]<<"."<<seat_b_col[i]+1<<" is cancelled. "<<endl;
                break;
            }
        }
        
        seat_b(people_b);
        
        if (v==1)
        {
            
            string roww;
            int col;
            
            cout<<"Enter row: ";
            cin>>roww;
            
            int row=roww[0]-49;
            
            cout<<"Enter col: ";
            cin>>col;
            col=col-1;
            
            while (people_b[row][col]=="o")
            {
                cout<<"Sorry "<<name<<", Seat number "<<roww<<"."<<col+1<<" is already reserved."<<endl;
                
                cout<<"Enter row: ";
                cin>>roww;
                
                row=roww[0]-49;
                
                cout<<"Enter col: ";
                cin>>col;
                col=col-1;
                
            }
            
            while (people_b[row][col]=="*")
            {
                people_b[row][col]="o";
                cout<<"Dear "<<name<<", Seat number "<<roww<<"."<<col+1<<" has been successfully reserved for you."<<endl;
                
            }
            
            seat_b_row[h]=roww;
            seat_b_col[h]=col;
            
        }
        
        
        
    }
    
    else if (a==2)
    {
        
        int v=0;
        int h=0;
        
        
        for (int j=0; j<28; j++)
        {
            if (name==name_e[j] && roll_num==roll_e[j]) {
                h=j;
                v=1;
                name_e[j]="x";
                roll_e[j]=0;
                name_b[business]=name;
                roll_b[business]=roll_num;
                string m=seat_e_row[j];
                int q=m[0]-49;
                people_e[q][seat_e_col[j]]="*";
                
                cout<<"Your seat number "<<seat_e_row[j]<<"."<<seat_e_col[j]+1<<" is cancelled. "<<endl;
            }
        }
        
        seat_b(people_b);
        
        if (v==1)
        {
            int ch=0;
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<4; j++) {
                    if (people_b[i][j]!="*") {
                        ch++;
                    }
                }
            }
            
            if (ch!=12)
            {
                
                string roww;
                int col;
                
                cout<<"Enter row: ";
                cin>>roww;
                
                int row=roww[0]-49;
                
                cout<<"Enter col: ";
                cin>>col;
                col=col-1;
                
                while (people_b[row][col]=="o")
                {
                    cout<<"Sorry "<<name<<", Seat number "<<roww<<"."<<col+1<<" is already reserved."<<endl;
                    
                    cout<<"Enter row: ";
                    cin>>roww;
                    
                    row=roww[0]-49;
                    
                    cout<<"Enter col: ";
                    cin>>col;
                    col=col-1;
                    
                }
                
                while (people_b[row][col]=="*")
                {
                    people_b[row][col]="o";
                    cout<<"Dear "<<name<<", Seat number "<<roww<<"."<<col+1<<" has been successfully reserved for you."<<endl;
                    
                }
                
                seat_b_row[h]=roww;
                seat_b_col[h]=col;
            }
            
            else if (ch==12)
            {
                cout<<"Business Class is fully booked."<<endl;
            }
            
        }
        
    }
}
