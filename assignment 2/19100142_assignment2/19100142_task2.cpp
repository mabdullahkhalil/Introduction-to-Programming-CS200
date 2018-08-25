#include <iostream>
using namespace std;

int instructions_student(); // print out the student instructions
int instructions_admin(); // print out the admin instructions
bool check_rollnum(int students[], int rollnum); // check the student is correct
void seating_plan(string comps[][8]);
void logout(int alotted_comp[], string comps[][8],int computer[][8],int students[],int logged[]);
void trace_student(int rollnum, int students[], int alotted_comp[], int computer[][8]);
void  login(int rollnum,int students[],string password,string passwords[],string comps[][8],int computer[][8],bool check, int alotted_comp[],int logged[],int log);



int main()
{
    int students[10]={19100001,19100002,19100003,19100004,19100005,19100006,19100007,19100008,19100009,1910010};
    string passwords[10]={"abc123","abc456","abc789","def123","def456","def789","xyz123","xyz456","xyz789","xyz123"};
    int computer[4][8]={{1,2,3,4,5,6,7,8},{9,10,11,12,13,14,15,16},{17,18,19,20,21,22,23,24},{25,26,27,28,29,30,31,32}};
    string comps[4][8]={{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"}};
    int alotted_comp[10]={0,0,0,0,0,0,0,0,0,0};
    int change_pswd[10]={0,0,0,0,0,0,0,0,0,0};
    string msgs[10]={"[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]","[You have no new message]",};
    int msg[10]={0,0,0,0,0,0,0,0,0,0};
    int rollnum;
    string password;
    bool check;
    int logged[10]={0,0,0,0,0,0,0,0,0,0};
    int log=0;
    
    int mode=0;
    int input=0;
    cout<<"Press 1 for student mode. "<<endl;
    cout<<"Press 2 for administrator mode. "<<endl;
    cin>>mode;
  
    while (input!=-1)
    {
        
        while ( mode==1)
        {
            input=instructions_student();
            
            if (input==1)
            {
                cout<<"Enter your roll number : ";
                cin>>rollnum;
                check=check_rollnum(students,rollnum);
                while (check==false)
                {
                    cout<<"...Roll number not found....."<<endl;
                    cout<<"Enter your roll number again : ";
                    cin>>rollnum;
                    check=check_rollnum(students,rollnum);
                }
                
                logged[log]=rollnum;
                
                for (int i=0; i<10; i++) {
                    while (rollnum==logged[i] && log!=i) {
                        cout<<"Your are already logged in.";
                        cout<<"Enter your roll number : ";
                        cin>>rollnum;
                    }
                }
                
                logged[log]=rollnum;
                
                cout<<"enter you password : ";
                cin>>password;
                
                login(rollnum,students,password,passwords,comps,computer,check,alotted_comp,logged,log);
                
                log++;
                
            }
            
            else if (input==2)
            {
                logout(alotted_comp,comps,computer,students,logged);
                
            }
            
            else if (input==3)
            {
                
                cout<<"Enter your roll number : ";
                cin>>rollnum;
                
                int g=0;
                
                for (int i=0; i<10; i++)
                {
                    if (rollnum!=logged[i])
                    {
                        if (rollnum==students[i] && change_pswd[i]!=0)
                        {
                            cout<<"You have already a pending password change request."<<endl;
                        }
                        else if (rollnum==students[i] && change_pswd[i]==0)
                        {
                            change_pswd[i]=rollnum;
                            cout<<"You have requested for password change successfully."<<endl;
                            msg[i]=1;
                            
                        }
                    }
                    else if (rollnum==logged[i])
                    {
                        g=1;
                    }
                   
                    
                    
                }
                
                if (g==1) {
                    cout<<"You can't request password change while looged in. "<<endl;
                }
                
            }
            
            else if (input==4)
            {
                cout<<"Enter your roll number : ";
                cin>>rollnum;
                
                for (int i=0; i<10; i++)
                {
                    if (msg[i]==0 && rollnum==students[i])
                    {
                        cout<<msgs[i]<<endl;
                        
                    }
                    else if (msg[i]==1 && rollnum==students[i])
                    {
                        cout<<"Dear "<<rollnum<<",Thank you for contacting IST Helpdesk. It is our top priority to resolve your issue in the most timely manner."<<endl;
                        msg[i]=0;
                        
                    }
                    else if (msg[i]==2 && rollnum==students[i])
                    {
                        cout<<"Dear "<<rollnum<<", your password has been reset. your new password is "<<passwords[i]<<endl;
                        msg[i]=0;
                        
                    }
                }
                
                
                
                
            }
            
            else if (input==5)
            {
                seating_plan(comps);
            }
            else if (input==6)
            {
                mode=2;
                break;
            }
            
            else if (input==-1)
            {
                break;
            }
           
        }
        
    
        while (mode==2)
        {
        input=instructions_admin();
            
            if (input==1)
            {
                
                cout<<"Enter roll number : ";
                cin>>rollnum;
                trace_student(rollnum,students,alotted_comp,computer);
               
            }
            
            else if (input==2)
            {
                int m=0;
                for (int i=0; i<10; i++)
                {
                    if (change_pswd[i]==0) {
                        m++;
                    }
                }
                
                if (m!=10)
                {
                    cout<<"The following students have requested for a password change. "<<endl;
                    for (int i=0; i<10; i++)
                    {
                        if (change_pswd[i]!=0)
                        {
                            cout<<change_pswd[i]<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"No requests for password change. "<<endl;
                }
               
                
            }
            
            
            else if (input==3)
            {
                cout<<"Enter roll number of the student: ";
                cin>>rollnum;
                
                for (int i=0; i<10; i++)
                {
                    if (rollnum==students[i] && rollnum==change_pswd[i])
                    {
                        cout<<"Enter the new password for "<<rollnum<<" : ";
                        cin>>passwords[i];
                        change_pswd[i]=0;
                        msg[i]=2;
                    }
                    else if (rollnum==students[i] && rollnum!=change_pswd[i])
                    {
                        cout<<"This student has not requested for the password change. "<<endl;
                    }
                }
            }
            
            else if (input==4)
            {
                seating_plan(comps);
            }
            
            else if (input==5)
            {
                mode=1;
            }
            
            else if (input==-1)
            {
                break;
            }
        }


    }
    
    if (input==-1) {
        cout<<"***** exiting program ******"<<endl;
    }
}

// function to print out the student instructions
int instructions_student()
{
    cout<<"-------------------------------------------"<<endl;
    cout<<"*********** [instructions] ****************"<<endl;
    cout<<"             student mode                  "<<endl;
    cout<<"*   1.Log into a computer.                *"<<endl;
    cout<<"*   2.log off from a computer             *"<<endl;
    cout<<"*   3.request for password reset          *"<<endl;
    cout<<"*   4. view message from Helpdesk         *"<<endl;
    cout<<"*   5.view Lab seating arrangement        *"<<endl;
    cout<<"*   6.switch mode                         *"<<endl;
    cout<<"*   Press -1 to exit                      *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"Enter your choice : ";
    int input;
    cin>>input;
    return input;
    
}

// function to print out the teacher instructions
int instructions_admin()
{
    cout<<"-------------------------------------------"<<endl;
    cout<<"*********** [instructions] ****************"<<endl;
    cout<<"          Administrator mode               "<<endl;
    cout<<"*   1.trace a student                     *"<<endl;
    cout<<"*   2.view change password requests       *"<<endl;
    cout<<"*   3.change password for a student       *"<<endl;
    cout<<"*   4.view seating arrangement of Lab     *"<<endl;
    cout<<"*   5.switch mode                         *"<<endl;
    cout<<"*   Press -1 to exit                      *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"Enter your choice : ";
    int input;
    cin>>input;
    return input;
    
}

// function to check the roll num.
bool check_rollnum(int students[], int rollnum)
{
    bool check=true;
    int ch=0;
    for (int i=0; i<10; i++) {
        if (rollnum!=students[i]) {
            ch++;
        }
    }
    if (ch==10) {
        check=false;
    }
    
    return check;
}

// function to display seating plan.
void seating_plan(string comps[][8])
{
    cout<<endl;
    cout<<":::::                      Lab 3                        ::::::"<<endl;
    cout<<endl;
    cout<<"         [1]    [2]    [3]    [4]    [5]    [6]    [7]     [8]"<<endl;
    cout<<endl;
    for (int i=0; i<4; i++)
    {
        cout<<"[ "<<i+1<<" ]"<<"     ";
        for (int j=0; j<8; j++)
        {
            cout<<comps[i][j]<<"      ";
        }
        cout<<endl;
    }
    
}

//function to log out.
void logout(int alotted_comp[], string comps[][8],int computer[][8],int students[],int logged[])
{
    int rollnum;
    cout<<"Enter your roll number  : ";
    cin>>rollnum;
    int comp;
    
    for (int i=0; i<10; i++) {
        if (rollnum==students[i]) {
            comp=alotted_comp[i];
            alotted_comp[i]=0;
            logged[i]=0;
        }
    }
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (comp==computer[i][j]) {
                cout<<"**********LOGGED OUT*********"<<endl;
                comps[i][j]="*";
            }
        }
    }
}

//function for logging in
void login(int rollnum,int students[],string password,string passwords[],string comps[][8],int computer[][8],bool check, int alotted_comp[],int logged[], int log)
{
    int row,col;
    int ch=10;
    do{
        ch=0;
        for (int i=0; i<10; i++)
        {
            if (rollnum==students[i] && password==passwords[i])
            {
                cout<<"Enter row number : ";
                cin>>row;
                
                cout<<"Enter Column number : ";
                cin>>col;
                
                
                
                while (comps[row-1][col-1]=="O")
                {
                    cout<<"Sorry "<<rollnum<<", computer is already reserved."<<endl;
                    
                    cout<<"Enter row: ";
                    cin>>row;
                    
                    cout<<"Enter col: ";
                    cin>>col;
                    
                    
                    }
                    
                    while (comps[row-1][col-1]=="*")
                    {
                        cout<<endl;
                        comps[row-1][col-1]="O";
                        alotted_comp[i]=computer[row-1][col-1];
                        cout<<"You have been logged into computer # "<<computer[row-1][col-1]<<" successfully!"<<endl;
                        
                    }
                    
                    
                    }
                    else
                    {
                        ch++;
                    }
                    }
                    if (ch==10) {
                        cout<<"The roll number and password doesnot match."<<endl;
                        cout<<endl;
                        cout<<"Enter your roll number : ";
                        cin>>rollnum;
                        check=check_rollnum(students,rollnum);
                        while (check==false) {
                            cout<<"...Roll number not found....."<<endl;
                            cout<<"Enter your roll number again : ";
                            cin>>rollnum;
                            check=check_rollnum(students,rollnum);
                        }
                        
                        
                        for (int i=0; i<10; i++) {
                            while (rollnum==logged[i] && log!=i) {
                                cout<<"Your are already logged in.";
                                cout<<"Enter your roll number : ";
                                cin>>rollnum;
                            }
                        }

                        cout<<"enter you password : ";
                        cin>>password;
                        
                        
                    }
                    }while(ch==10);
                    
}

// function to trace student.
void trace_student(int rollnum, int students[], int alotted_comp[], int computer[][8])
{
    for (int i=0; i<10; i++)
    {
        if (rollnum==students[i])
        {
            cout<<"Alotted computer : "<<alotted_comp[i]<<endl;
            for (int r=0; r<4; r++)
            {
                for (int j=0; j<8; j++)
                {
                    if (alotted_comp[i]==computer[r][j])
                    {
                        cout<<"Row    : "<<r+1<<endl;
                        cout<<"Column : "<<j+1<<endl;
                    }
                }
            }
        
        }
    }
}
