
#include <iostream>
#include <fstream>
#include "lms.h"
#include <vector>

using namespace std;

int main(){
    
    ifstream user;
    user.open("userlist.txt");

    users *totalstu=new users[15];
    users *totalteachers=new users[5];
    
    
    string s,d,f,l,e,p;
    
    //--------------- userlist ----------------------------//
    
    int i=0; int j=0;
    while(!user.eof())
    {
        user>>s>>d>>f>>l>>e>>p;
        if (d=="Phd")
        {
            totalteachers[i]=*new teachers(s,d,f,l,e,p);
            i++;
        }
        else if (d=="freshman")
        {
            totalstu[j]=*new students(s,d,f,l,e,p);
           	j++;
        }
    }
    
    user.close();
    
    
    
    
    //--------------------------course 1------------------//
    
    ifstream course1;
    course1.open("Course1.txt");
    
    // doing works for the course details.
    
    string cn,c,de,ca;
    
    course1>>cn>>c>>de>>ca;
    
    course c1(cn,c,de,ca);
    
    
    
    // checking out the enrolled students and the professor of the course 1.
    users* course1students=new users[20];
    users course1prof;
    
    int c1_students=0;
    while(!course1.eof())
    {
        course1>>s>>d>>f>>l>>e>>p;
        
        if (d=="freshman")
        {
            course1students[c1_students]=*new students(s,d,f,l,e,p);
            c1_students++;
        }
        else if (d=="Phd")
        {
            course1prof=* new teachers(s,d,f,l,e,p);
        }
    }
    course1.close();
    
    
    
    //--------------------------course 2------------------//
    ifstream course2;
    course2.open("Course2.txt");
    
    // doing works for the course details.
    
    course2>>cn>>c>>de>>ca;
    
    course c2(cn,c,de,ca);
    
    
    
    // checking out the enrolled students and the professor of the course 1.
    users* course2students= new users[20];
    users course2prof;
    
    int c2_students=0;
    while(!course2.eof())
    {
        course2>>s>>d>>f>>l>>e>>p;
        
        if (d=="freshman")
        {
            course2students[c2_students]=*new students(s,d,f,l,e,p);
            c2_students++;
        }
        else if (d=="Phd")
        {
            course2prof=* new teachers(s,d,f,l,e,p);
        }
    }
    course2.close();
    
    
    
    
    //--------------------------course 3------------------//
    
    ifstream course3;
    course3.open("Course3.txt");
    
    // doing works for the course details.
    
    course3>>cn>>c>>de>>ca;
    
    course c3(cn,c,de,ca);
    
    
    
    // checking out the enrolled students and the professor of the course 1.
    users* course3students=new users[20];
    users course3prof;
    
    int c3_students=0;
    while(!course3.eof())
    {
        course3>>s>>d>>f>>l>>e>>p;
        
        if (d=="freshman")
        {
            course3students[c3_students]=*new students(s,d,f,l,e,p);
            c3_students++;
        }
        else if (d=="Phd")
        {
            course3prof=* new teachers(s,d,f,l,e,p);
        }
    }
    course3.close();
    
    
    
    //--------------------------course 4------------------//
    
    ifstream course4;
    course4.open("Course4.txt");
    
    // doing works for the course details.
    
    course4>>cn>>c>>de>>ca;
    
    course c4(cn,c,de,ca);
    
    
    
    // checking out the enrolled students and the professor of the course 1.
    users* course4students=new users[20];
    users course4prof;
    
    int c4_students=0;
    while(!course4.eof())
    {
        course4>>s>>d>>f>>l>>e>>p;
        
        if (d=="freshman")
        {
            course4students[c4_students]=*new students(s,d,f,l,e,p);
            c4_students++;
        }
        else if (d=="Phd")
        {
            course4prof=* new teachers(s,d,f,l,e,p);
        }
    }
    course4.close();
    
    
    //--------------------------course 5------------------//
    ifstream course5;
    course5.open("Course5.txt");
    
    // doing works for the course details.
    
    course5>>cn>>c>>de>>ca;
    
    course c5(cn,c,de,ca);
    
    
    
    // checking out the enrolled students and the professor of the course 1.
    users* course5students=new users[20];
    users course5prof;
    
    int c5_students=0;
    while(!course5.eof())
    {
        course5>>s>>d>>f>>l>>e>>p;
        
        if (d=="freshman")
        {
            course5students[c5_students]=*new students(s,d,f,l,e,p);
            c5_students++;
        }
        else if (d=="Phd")
        {
            course5prof=* new teachers(s,d,f,l,e,p);
        }
    }
    course5.close();
    
    
    //---------------- creating the vectors for functions ----------------//
    
    vector<int> course1_marks;
    vector<int> course2_marks;
    vector<int> course3_marks;
    vector<int> course4_marks;
    vector<int> course5_marks;
    vector<string> course1_resources;
    vector<string> course2_resources;
    vector<string> course3_resources;
    vector<string> course4_resources;
    vector<string> course5_resources;
    vector<string> course1_assignments;
    vector<string> course2_assignments;
    vector<string> course3_assignments;
    vector<string> course4_assignments;
    vector<string> course5_assignments;
    
    
    vector< vector<string>> assignments{course1_assignments,course2_assignments,course3_assignments,course4_assignments,course5_assignments};
    vector< vector<int>> marks{course1_marks,course2_marks,course3_marks,course4_marks,course5_marks};
    vector< vector<string>> resources{course1_resources,course2_resources,course3_resources,course4_resources,course5_resources};

    
    
    while (true) {
        int logging;
        cout<<"1. login as a student. "<<endl;
        cout<<"2. login as a teacher. "<<endl;
        cin>>logging;
        
        string roll,pass,fname,passw;
        bool student,teacher = false;
        switch (logging) {
            case 1:
                cout<<"roll number: "; cin>>roll;
                cout<<"Password: "; cin>>pass;
                for (int i=0; i<15; i++) {
                    //cout<<"stu des"<<totalstu[i].getstatus();
                    if (totalstu[i].getstatus()==roll && totalstu[i].getpassword()==pass)
                    {
                        cout<<totalstu[i].getfname()<<" "<<totalstu[i].getlname()<<", logged in."<<endl;
                        student=true;
                        teacher=false;
                        break;
                    }
                    if (totalstu[i].getstatus()==roll){
                        while (totalstu[i].getpassword()!=pass) {
                            cout<<"username and password doesnot match. "<<endl;
                            cout<<"Roll number: "; cin>>roll;
                            cout<<"Password: "; cin>>pass;
                            i=-1;
                            break;
                        }
                    }
                    if(totalstu[i].getstatus()!=roll && i==14){
                        cout<<"roll number not in the directory."<<endl;
                        cout<<"roll number: "; cin>>roll;
                        cout<<"Password: "; cin>>pass;
                        i=-1;
                    }
                }
                
                
                break;
                
            case 2:
                cout<<"First name: "; cin>>fname;
                cout<<"Password: "; cin>>passw;
                for (int i=0; i<5; i++) {
                    if (totalteachers[i].getfname()==fname && totalteachers[i].getpassword()==passw)
                    {
                        cout<<totalteachers[i].getfname()<<" "<<totalteachers[i].getlname()<<", logged in."<<endl;
                        student=false;
                        teacher=true;
                        break;
                    }

                    if (totalteachers[i].getfname()==fname){
                        while (totalteachers[i].getpassword()!=passw) {
                            cout<<"username and password doesnot match. "<<endl;
                            cout<<"First name: "; cin>>fname;
                            cout<<"Password: "; cin>>passw;
                            i=-1;
                            break;
                        }
                    }
                    if(totalteachers[i].getfname()!=fname && i==4){
                        cout<<"such professor does not exist in the directory"<<endl;
                        cout<<"First name: "; cin>>fname;
                        cout<<"Password: "; cin>>passw;
                        i=-1;
                    }
                }
        }
        
    
        while(student && logging==1){
            //-------------checking enrolled courses--------------//
           
            
            vector<string> enrol_c;
            vector<int> stu_num;
            
            
            for (int i=0; i<c1_students; i++) {
                if (roll==course1students[i].getstatus()) {
                    enrol_c.push_back(c1.getcname());
                    stu_num.push_back(i);
                }
            }
            
            for (int i=0; i<c2_students; i++) {
                if (roll==course2students[i].getstatus()) {
                    enrol_c.push_back(c2.getcname());
                    stu_num.push_back(i);
                }
            }
            
            for (int i=0; i<c3_students; i++) {
                if (roll==course3students[i].getstatus()) {
                    enrol_c.push_back(c3.getcname());
                    stu_num.push_back(i);
                }
            }
            
            for (int i=0; i<c4_students; i++) {
                if (roll==course4students[i].getstatus()) {
                    enrol_c.push_back(c4.getcname());
                    stu_num.push_back(i);
                }
            }
            
            for (int i=0; i<c5_students; i++) {
                if (roll==course5students[i].getstatus()) {
                    enrol_c.push_back(c5.getcname());
                    stu_num.push_back(i);
                }
            }
            
            
            
            
            while (true)
            {
                int initializtion=0;
                
                for (int i=0; i<enrol_c.size(); i++) {
                    cout<<i+1<<". "<<enrol_c.at(i)<<endl;
                }
                cout<<"enter -1 to log out. "<<endl;
                int c_num;
                cout<<"Enter the course: "; cin>>c_num;
                if (c_num==-1) {
                    student=false;
                    teacher=true;
                    break;
                }
                
                
                students stu;
                users* stud=&stu;
                

                // activating course....
                int roster=0;
                if (enrol_c.at(c_num-1)==c1.getcname()) {
                    stu.setmarks(course1_marks);
                    stu.setrandom(stu_num.at(c_num-1));
                    stu.setresources(course1_resources);
                    stud->setstatus(course1students[stu_num.at(c_num-1)].getstatus());
                    stud->setfname(course1students[stu_num.at(c_num-1)].getfname());
                    stud->setlname(course1students[stu_num.at(c_num-1)].getlname());
                    roster=1;
                    
                }
                 if (enrol_c.at(c_num-1)==c2.getcname()) {
                    stu.setmarks(course2_marks);
                    stu.setrandom(stu_num.at(c_num-1));
                    stu.setresources(course2_resources);
                    stud->setstatus(course2students[stu_num.at(c_num-1)].getstatus());
                    stud->setfname(course2students[stu_num.at(c_num-1)].getfname());
                    stud->setlname(course2students[stu_num.at(c_num-1)].getlname());
                    roster=2;
                }
                else if (enrol_c.at(c_num-1)==c3.getcname()) {
                    stu.setmarks(course3_marks);
                    stu.setrandom(stu_num.at(c_num-1));
                    stu.setresources(course3_resources);
                    stud->setstatus(course3students[stu_num.at(c_num-1)].getstatus());
                    stud->setfname(course3students[stu_num.at(c_num-1)].getfname());
                    stud->setlname(course3students[stu_num.at(c_num-1)].getlname());
                    roster=3;
                }
                else if (enrol_c.at(c_num-1)==c4.getcname()) {
                    stu.setmarks(course4_marks);
                    stu.setrandom(stu_num.at(c_num-1));
                    stu.setresources(course4_resources);
                    stud->setstatus(course4students[stu_num.at(c_num-1)].getstatus());
                    stud->setfname(course4students[stu_num.at(c_num-1)].getfname());
                    stud->setlname(course4students[stu_num.at(c_num-1)].getlname());
                    roster=4;
                }
                
                else if (enrol_c.at(c_num-1)==c5.getcname()) {
                    stu.setmarks(course5_marks);
                    stu.setrandom(stu_num.at(c_num-1));
                    stu.setresources(course5_resources);
                    stud->setstatus(course5students[stu_num.at(c_num-1)].getstatus());
                    stud->setfname(course5students[stu_num.at(c_num-1)].getfname());
                    stud->setlname(course5students[stu_num.at(c_num-1)].getlname());
                    roster=5;
                }
                
                
                while (initializtion!=-1)
                {
                    cout<<"1. Resources. "<<endl;
                    cout<<"2. Assignments."<<endl;
                    cout<<"3. Roster. "<<endl;
                    cout<<"4. Marks."<<endl;
                    cout<<"enter -1 to go to the back menu. "<<endl;
                    
                    cin>>initializtion;
                    switch (initializtion)
                    {
                        case 1:
                            stud->viewresources(resources.at(roster-1));
                            break;
                            
                            
                        case 2:
                            stud->viewassignments(assignments.at(roster-1));
                            break;

                            
                            
                        case 3:
                            switch (roster) {
                                case 1:
                                    stu.roster(course1students,course1prof,c1_students);
                                    break;
                                case 2:
                                    stu.roster(course2students,course2prof,c2_students);
                                    break;
                                case 3:
                                    stu.roster(course3students,course3prof,c3_students);
                                    break;
                                case 4:
                                    stu.roster(course4students,course4prof,c4_students);
                                    break;
                                case 5:
                                    stu.roster(course5students,course5prof,c5_students);
                                    break;
                                    
                            }
                            break;
                            
                            
                        case 4:
                                    stud->viewmarkstab(marks.at(roster-1));
                            
                    }
                    
                    
                }
                
            }
        }
        
        
        while (teacher && logging ==2){
            
            int instructor;
            if (fname==course1prof.getfname()){instructor=0;}
            else if (fname==course2prof.getfname()){instructor=1;}
            else if (fname==course3prof.getfname()){instructor=2;}
            else if (fname==course4prof.getfname()){instructor=3;}
            else if (fname==course5prof.getfname()){instructor=4;}
            
            teachers tea;
            users* teach=&tea;
            
            switch (instructor) {
                case 0:
                    for (int i=0; i<c1_students; i++) {
                        tea.setfname(course1students[i].getfname());
                        tea.setlname(course1students[i].getlname());
                    }
                    break;
                    
                case 1:
                    for (int i=0; i<c2_students; i++) {
                        tea.setfname(course2students[i].getfname());
                        tea.setlname(course2students[i].getlname());
                    }
                    break;
                    
                case 2:
                    for (int i=0; i<c3_students; i++) {
                        tea.setfname(course3students[i].getfname());
                        tea.setlname(course3students[i].getlname());
                    }
                    break;
                    
                case 3:
                    for (int i=0; i<c4_students; i++) {
                        tea.setfname(course4students[i].getfname());
                        tea.setlname(course4students[i].getlname());
                    }
                    break;
                    
                case 4:
                    for (int i=0; i<c5_students; i++) {
                        tea.setfname(course5students[i].getfname());
                        tea.setlname(course5students[i].getlname());
                    }
                    break;
            }
            
            
            vector<string>* ass=&assignments.at(instructor);
            vector<int>* mar=&marks.at(instructor);
            vector<string>* res=&resources.at(instructor);
            
            
                int initialize;
                cout<<"1. Resources. "<<endl;
                cout<<"2. Assignments."<<endl;
                cout<<"3. Roster. "<<endl;
                cout<<"4. Marks."<<endl;
                cout<<"enter -1 to log out. "<<endl;
                
                cin>>initialize;
                
                
                switch (initialize) {
                        
                    case 1:
                        tea.viewresources(*res);
                        break;
                        
                        
                    case 2:
                        tea.viewassignments(*ass);
                        break;
                        
                        
                    case 3:
                        if (instructor==0) {
                            tea.roster(course1students,course1prof,c1_students);
                        }
                        else if (instructor==1) {
                            tea.roster(course2students,course2prof,c2_students);
                        }
                        else if (instructor==2) {
                            tea.roster(course3students,course3prof,c3_students);
                        }
                        else if (instructor==3) {
                            tea.roster(course4students,course4prof,c4_students);
                        }
                        else if (instructor==4) {
                            tea.roster(course5students,course5prof,c5_students);
                        }
 
                        break;
                        
                    case 4:
                        tea.viewmarkstab(*mar);
                        break;
                        
                        
                     case -1:
                        teacher=false;
                        student=true;
                        break;
                }
                
            }
    }
   

    }

