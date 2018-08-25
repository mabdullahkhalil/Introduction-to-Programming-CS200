#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class users
{
private:
    string designation;
    string status;
    string fname;
    string lname;
    string email;
    string password;
    
public:
    users(){
        status=" ";
        designation=" ";
        fname=" ";
        lname=" ";
        email=" ";
        password=" ";
    }
     users(string& s,string& d,string& f,string& l, string& e,string& p)
     {
     status=s;
     designation=d;
     fname=f;
     lname=l;
     email=e;
     password=p;
     }
    
    
    ~users(){};
    string getdesignation(){return designation;}
    string getstatus(){return status;}
    string getfname(){return fname;}
    string getlname(){return lname;}
    string getemail(){return email;}
    string getpassword(){return password;}
    void setstatus(string s){status=s;}
    void setdesignation(string d){designation=d;}
    void setfname(string f){fname=f;}
    void setlname(string l){lname=l;}
    void setemail(string e){email=e;}
    void setpassword(string p){password=p;}
    
    virtual void viewmarkstab(vector<int> marks){}
    virtual void viewresources(vector<string> resources){}
    virtual void viewassignments(vector<string> assignments){}
    
    
};



//----------------- students -------------------//

class students:public users
{
private:
    vector<string> assignments;
    vector<string> resources;
    vector<int> marks;
    int random;
    
public:
    void setass(vector<string> a){assignments=a;}
    void setmarks(vector<int> m){marks=m;}
    void setresources(vector<string> x){resources=x;}
    void setrandom(int r){random=r;}
    
    students(){};
    students(string& s,string& d,string& f,string& l, string& e,string& p):users(s,d,f,l,e,p){};
    students(string& s,string& f,string& l,string& e){
        setstatus(s);
        setfname(f);
        setlname(l);
        setemail(e);
    }
    ~students(){};
    virtual void viewmarkstab(vector<int> a){
        
        if (a.empty()) {
            cout<<"no marks yet. Lazy professor. Lol."<<endl<<endl<<endl<<endl;
        }
        else
            cout<<"your marks : "<<a.at(random)<<endl<<endl<<endl<<endl;
        
        
    }
    
    virtual void viewresources(vector<string> a){
        if (a.empty()) {
            cout<<"no  resources. khud parho chalo."<<endl<<endl<<endl<<endl;
        }
        else{
            cout<<"%%%%%%%%%% resources %%%%%%%%%%%"<<endl;
            
            for (int i=0; i<a.size(); i++) {
                cout<<i+1<<". "<<a.at(i)<<endl;
            }
            cout<<endl<<endl<<endl;
            
        }
        
    }

    
    virtual void viewassignments(vector<string> a){
        if (a.empty()) {
            cout<<"no  Assignments. chill mahol tay mithay chol. ;]"<<endl<<endl<<endl<<endl;
        }
        else{
            cout<<"%%%%%%%%%%% assignments %%%%%%%%%%%%%%"<<endl;
            for (int i=0; i<a.size(); i++) {
                cout<<i+1<<". "<<a.at(i)<<endl;
            }
            cout<<endl<<endl<<endl;
        }
    }
    
    
    void roster(users stu[], users& tea, int i){
        cout<<endl<<endl<<"%%%%%%%%%%%%%% Roster %%%%%%%%%%%%%%%%%%"<<endl;
        for (int j=0; j<i; j++) {
            cout<<j+1<<".  "<<stu[j].getstatus()<<"  "<<stu[j].getfname()<<"   "<<stu[j].getlname()<<endl;
        }
        cout<<i+1<<".  "<<tea.getstatus()<<"  "<<tea.getfname()<<"   "<<tea.getlname()<<endl<<endl<<endl<<endl;
    }
    
    
};


//----------------- teachers -------------------//

class teachers: public users
{
private:
    vector<int> marks;
    vector<string> sfname;
    vector<string> slname;

public:
    void setmarks(int m){marks.push_back(m);
    cout<<"in: "<<marks.at(0)<<endl;}
    void setfname(string m){sfname.push_back(m);}
    void setlname(string x){slname.push_back(x);}

    teachers(){};
    teachers(string& s,string& d,string& f,string& l, string& e,string& p):users(s,d,f,l,e,p){};
    ~ teachers(){};
    
    
    
    
    void roster(users stu[], users& tea, int i){
        cout<<endl<<endl<<"%%%%%%%%%%%%%%%%%% Roster %%%%%%%%%%%%%%%%%%"<<endl;
        for (int j=0; j<i; j++) {
            cout<<j+1<<".  "<<stu[j].getstatus()<<"  "<<stu[j].getfname()<<"   "<<stu[j].getlname()<<endl;
        }
        cout<<i+1<<".  "<<tea.getstatus()<<"  "<<tea.getfname()<<"   "<<tea.getlname()<<endl<<endl<<endl<<endl;
    }
    
    
    
    
    
    
    
    virtual void viewmarkstab(vector<int>& marks){

        int d;
        cout<<"1. Add marks."<<endl;
        cout<<"2. View marks."<<endl;
        cin>>d;
        
        if (d==1) {
            cout<<"\n \n \n ADD MARKS: \n";

            int ma;
            for (int i=0; i<sfname.size(); i++) {
                cout<<sfname.at(i)<<"  "<<slname.at(i)<<"    ";cin>>ma;
                marks.push_back(ma);
            }
        }
        
        else if(d==2){
        
           if (marks.empty()) {
                cout<<"no marks yet. Lazy professor. Lol."<<endl<<endl<<endl<<endl;
            }
            else{
                cout<<"%%%%%%%%%%% marks %%%%%%%%%%%"<<endl;
                cout<<endl<<endl;;
                for (int i=0; i<marks.size(); i++) {
                    cout<<sfname.at(i)<<"  "<<slname.at(i)<<"  "<<marks.at(i)<<endl;
                }
                cout<<endl<<endl<<endl;
            }
    }
    }
    
    virtual void viewassignments(vector<string>& assignments){
        
        int d2;
        cout<<"1. Add assignments."<<endl;
        cout<<"2. View assignments."<<endl;
        cin>>d2;
        
        if (d2==1) {
            cout<<"\n \n \n ADD ASSIGNMENT: ";
            string ma;
            cin.ignore();
            getline(cin,ma);
            assignments.push_back(ma);
        }
        
        else if(d2==2){
        
        if (assignments.empty()) {
            cout<<"no assignment. don't burden children plz."<<endl;
            cout<<endl<<endl<<endl;
        }
        else{
            cout<<"%%%%%%%%%%% assignments %%%%%%%%%%%%%%"<<endl;
            cout<<endl<<endl;;
            for (int i=0; i<assignments.size(); i++) {
                cout<<i+1<<".  "<<assignments.at(i)<<endl;
            }
            cout<<endl<<endl<<endl;
        }
        }
    }

    
    virtual void viewresources(vector<string>& resources){
        
        int d3;
        cout<<"1. Add resources."<<endl;
        cout<<"2. View resources."<<endl;
        cin>>d3;
        
        if (d3==1) {
            cout<<"\n \n \n ADD RESOURCES: ";
            string ma;
            cin.ignore();
            getline(cin,ma);
            resources.push_back(ma);

        }
        
        else if(d3==2){
            
        if (resources.empty()) {
            cout<<"no resources. plz bachon ka bhala krain"<<endl;
            cout<<endl<<endl<<endl;
        }
        else{
            cout<<"%%%%%%%%%%%%%% resources %%%%%%%%%%%%%%%"<<endl;
            cout<<endl<<endl;;
            for (int i=0; i<resources.size(); i++) {
                cout<<i+1<<".  "<<resources.at(i)<<endl;
            }
            cout<<endl<<endl<<endl;
        }
        }
    }
    
};



//----------------- course -------------------//


class course:public users
{
private:
    string cname;
    string code;
    string dept;
    string cap;
    
public:
    course(){};
    course(string& s,string& d,string& f,string& l, string& e,string& p):users(s,d,f,l,e,p){};
    course(string& cn,string& c,string& de,string& ca){
        cname=cn;
        code=c;
        dept=de;
        cap=ca;
    }
    ~course(){};

    string getcname(){return cname;}
    
    
    
    
};
