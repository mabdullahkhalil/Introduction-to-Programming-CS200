#include <iostream>
#include <ctime>
using namespace std;

int main()
{

    int input_1,input_2,input_3;
    int p_1,p_2,p_3;
    
    int b_f=180;
    int b_h=90;
    int b_q=45;
    int a_f=60;
    int a_h=30;
    int a_q=15;
    int j_f=120;
    int j_h=60;
    int j_q=30;
    int c_f=60;
    int c_h=30;
    int c_q=15;
    int d_f=60;
    int d_h=30;
    int d_q=15;
    int total=0;
    
    
    
    cout<<"***********************************************"<<endl;
    cout<<"                     MENU                      "<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"  ITEM              Portion               Price"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"1.Briyani            1.full               "<<b_f<<endl;
    cout<<"                     2.half               "<<b_h<<endl;
    cout<<"                     3.quarter            "<<b_q<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"2.Achari Baingan     1.full               "<<a_f<<endl;
    cout<<"                     2.half               "<<a_h<<endl;
    cout<<"                     3.quarter            "<<a_q<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"3.Jalfarezi          1.Full               "<<j_f<<endl;
    cout<<"                     2.Half               "<<j_h<<endl;
    cout<<"                     3.Quarter            "<<j_q<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"4.Chicken Haleem     1.Full               "<<c_f<<endl;
    cout<<"                     2.Half               "<<c_h<<endl;
    cout<<"                     3.Quarter            "<<c_q<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"5.Daal               1.Full               "<<d_f<<endl;
    cout<<"                     2.Half               "<<d_h<<endl;
    cout<<"                     3.Quarter            "<<d_q<<endl;
    cout<<"-----------------------------------------------"<<endl;

    
    
    int i=1;
    
    while(i==1){
    
        
    do {
        
        
  
        cout<<"enter -1 to exit"<<endl;
        cout<<"enter the first item [1.Biryani, 2.Achari Baingan, 3. Jalfarezi, 4. Chicken Haleem, 5. Daal]"<<endl;
        cin>>input_1;
        if (input_1==-1) {
            
            break;
        }
        cout<<"enter the portion of first item  [1.Full, 2.Half, 3.Quarter]"<<endl;
        cin>>p_1;
        
        
        cout<<"enter the second item [1.Biryani, 2.Achari Baingan, 3. Jalfarezi, 4. Chicken Haleem, 5. Daal]"<<endl;
        cin>>input_2;
        if (input_2==-1) {
            time_t t = time(0);   // get time now
            struct tm * now = localtime( & t );
            
            
            cout <<"            Date:"<< now->tm_mday<< '-'
            << (now->tm_mon + 1) << '-'
            <<  (now->tm_year + 1900)
            << endl;
            
            cout <<"            Time:"<< now->tm_hour<< ':'
            << (now->tm_min) << ':'
            <<  (now->tm_sec)
            << endl;
                       cout<<"*************************************************************"<<endl;
                       cout<<"Sr. No      Item                     Portion            Price"<<endl;
            {
                if (input_1==1 )
                {
                    if (p_1==1) {
                        cout<<"1          Briyani                  full                "<<b_f<<endl;
                        total=total+b_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Biryani                   half                "<<b_h<<endl;
                        total=total+b_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Biryani                   quarter             "<<b_q<<endl;
                        total=total+b_q;
                    }
                    
                }
                
                else if (input_1==2)
                {
                    if (p_1==1) {
                        cout<<"1          Achari Baingan            full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Achari Baingan             half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Achari Baingan             quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==3)
                {
                    if (p_1==1) {
                        cout<<"1          Jalfarezi                  full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Jalfarezi                  half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Jalfarezi                  quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==4)
                {
                    if (p_1==1) {
                        cout<<"1          Chicken Haleem              full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Chicken Haleem              half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Chicken Haleem              quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==5)
                {
                    if (p_1==1) {
                        cout<<"1           Daal                        full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1           Daal                        half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1           Daal                       quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                
            }
            
            cout<<""<<endl;
            cout<<""<<endl;

            cout<<"             Item:   1"<<endl;
            cout<<"             TOTAL:"<<total<<endl;
            total=0;
            break;
        }
        cout<<"enter the portion of second item [1.Full, 2.Half, 3.Quarter]"<<endl;
        cin>>p_2;
        
        
        cout<<"enter the third item [1.Biryani, 2.Achari Baingan, 3. Jalfarezi, 4. Chicken Haleem, 5. Daal]"<<endl;
        cin>>input_3;
        if (input_3==-1) {
            time_t t = time(0);   // get time now
            struct tm * now = localtime( & t );
            
            
            cout <<"            Date:"<< now->tm_mday<< '-'
            << (now->tm_mon + 1) << '-'
            <<  (now->tm_year + 1900)
            << endl;
            
            cout <<"            Time:"<< now->tm_hour<< ':'
            << (now->tm_min) << ':'
            <<  (now->tm_sec)
            << endl;
                        cout<<"*************************************************************"<<endl;
                        cout<<"Sr. No      Item                     Portion            Price"<<endl;
            {
                if (input_1==1 )
                {
                    if (p_1==1) {
                        cout<<"1          Briyani                  full                "<<b_f<<endl;
                        total=total+b_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Biryani                   half                "<<b_h<<endl;
                        total=total+b_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Biryani                   quarter             "<<b_q<<endl;
                        total=total+b_q;
                    }
                    
                }
                
                else if (input_1==2)
                {
                    if (p_1==1) {
                        cout<<"1          Achari Baingan             full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Achari Baingan             half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Achari Baingan             quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==3)
                {
                    if (p_1==1) {
                        cout<<"1          Jalfarezi                  full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Jalfarezi                  half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Jalfarezi                  quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==4)
                {
                    if (p_1==1) {
                        cout<<"1          Chicken Haleem              full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1          Chicken Haleem              half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1          Chicken Haleem              quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_1==5)
                {
                    if (p_1==1) {
                        cout<<"1           Daal                        full                "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_1==2){
                        cout<<"1           Daal                        half                "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_1==3){
                        cout<<"1           Daal                        quarter             "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                
            } // 1
            {
                
                if (input_2==1)
                {
                    if (p_2==1) {
                        cout<<"2          Briyani                    full                "<<b_f<<endl;
                        total=total+b_f;
                    }
                    else if (p_2==2){
                        cout<<"2          Biryani                    half                "<<b_h<<endl;
                        total=total+b_h;
                    }
                    else if (p_2==3){
                        cout<<"2          Biryani                    quarter             "<<b_q<<endl;
                        total=total+b_q;
                    }
                    
                }
                
                else if (input_2==2)
                {
                    if (p_2==1) {
                        cout<<"2           Achari Baingan             full               "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_2==2){
                        cout<<"2           Achari Baingan             half               "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_2==3){
                        cout<<"2           Achari Baingan             quarter            "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_2==3)
                {
                    if (p_2==1) {
                        cout<<"2           Jalfarezi                  full               "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_2==2){
                        cout<<"2           Jalfarezi                  half               "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_2==3){
                        cout<<"2           Jalfarezi                  quarter            "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_2==4)
                {
                    if (p_2==1) {
                        cout<<"2           Chicken Haleem              full              "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_2==2){
                        cout<<"2           Chicken Haleem              half              "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_2==3){
                        cout<<"2           Chicken Haleem              quarter           "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
                else if (input_2==5)
                {
                    if (p_2==1) {
                        cout<<"2            Daal                        full             "<<a_f<<endl;
                        total=total+a_f;
                    }
                    else if (p_2==2){
                        cout<<"2            Daal                        half             "<<a_h<<endl;
                        total=total+a_h;
                    }
                    else if (p_2==3){
                        cout<<"2            Daal                       quarter           "<<a_q<<endl;
                        total=total+a_q;
                    }
                    
                }
            } // 2
            cout<<""<<endl;
            cout<<""<<endl;

            cout<<"             Item:   2"<<endl;
            cout<<"             TOTAL:"<<total<<endl;
            total=0;
            break;
        }
        
        cout<<"enter the portion of third item [1.Full, 2.Half, 3.Quarter]"<<endl;
        cin>>p_3;
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        
        
        cout <<"            Date:"<< now->tm_mday<< '-'
        << (now->tm_mon + 1) << '-'
        <<  (now->tm_year + 1900)
        << endl;
        
        cout <<"            Time:"<< now->tm_hour<< ':'
        << (now->tm_min) << ':'
        <<  (now->tm_sec)
        << endl;
            cout<<"*************************************************************"<<endl;
            cout<<"Sr. No      Item                     Portion            Price"<<endl;
        
        {
            if (input_1==1 )
            {
                if (p_1==1) {
                    cout<<"1          Briyani                  full                "<<b_f<<endl;
                    total=total+b_f;
                }
                else if (p_1==2){
                    cout<<"1          Biryani                   half                "<<b_h<<endl;
                    total=total+b_h;
                }
                else if (p_1==3){
                    cout<<"1          Biryani                   quarter             "<<b_q<<endl;
                    total=total+b_q;
                }
                
            }
            
            else if (input_1==2)
            {
                if (p_1==1) {
                    cout<<"1          Achari Baingan            full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_1==2){
                    cout<<"1          Achari Baingan             half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_1==3){
                    cout<<"1          Achari Baingan             quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_1==3)
            {
                if (p_1==1) {
                    cout<<"1          Jalfarezi                  full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_1==2){
                    cout<<"1          Jalfarezi                  half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_1==3){
                    cout<<"1          Jalfarezi                  quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_1==4)
            {
                if (p_1==1) {
                    cout<<"1          Chicken Haleem              full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_1==2){
                    cout<<"1          Chicken Haleem              half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_1==3){
                    cout<<"1          Chicken Haleem              quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_1==5)
            {
                if (p_1==1) {
                    cout<<"1           Daal                        full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_1==2){
                    cout<<"1           Daal                        half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_1==3){
                    cout<<"1           Daal                       quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            
        } // 1
        {
            
            if (input_2==1)
            {
                if (p_2==1) {
                    cout<<"2           Briyani                    full                "<<b_f<<endl;
                    total=total+b_f;
                }
                else if (p_2==2){
                    cout<<"2           Biryani           half                "<<b_h<<endl;
                    total=total+b_h;
                }
                else if (p_2==3){
                    cout<<"2           Biryani                    quarter             "<<b_q<<endl;
                    total=total+b_q;
                }
                
            }
            
            else if (input_2==2)
            {
                if (p_2==1) {
                    cout<<"2       Achari Baingan           full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_2==2){
                    cout<<"2         Achari Baingan             half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_2==3){
                    cout<<"2         Achari Baingan             quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_2==3)
            {
                if (p_2==1) {
                    cout<<"2           Jalfarezi                  full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_2==2){
                    cout<<"2           Jalfarezi                  half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_2==3){
                    cout<<"2           Jalfarezi                  quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_2==4)
            {
                if (p_2==1) {
                    cout<<"2           Chicken Haleem              full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_2==2){
                    cout<<"2           Chicken Haleem              half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_2==3){
                    cout<<"2           Chicken Haleem              quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
            else if (input_2==5)
            {
                if (p_2==1) {
                    cout<<"2            Daal                        full                "<<a_f<<endl;
                    total=total+a_f;
                }
                else if (p_2==2){
                    cout<<"2            Daal                        half                "<<a_h<<endl;
                    total=total+a_h;
                }
                else if (p_2==3){
                    cout<<"2            Daal                       quarter             "<<a_q<<endl;
                    total=total+a_q;
                }
                
            }
        } // 2

        {
    
    if (input_3==1)
    {
        if (p_3==1) {
            cout<<"3            Briyani                    full                "<<b_f<<endl;
            total=total+b_f;
        }
        else if (p_3==2){
            cout<<"3            Biryani                    half                "<<b_h<<endl;
            total=total+b_h;
        }
        else if (p_3==3){
            cout<<"3            Biryani                    quarter             "<<b_q<<endl;
            total=total+b_q;
        }
        
    }
    
    else if (input_3==2)
    {
        if (p_3==1) {
            cout<<"3            Achari Baingan             full                "<<a_f<<endl;
            total=total+a_f;
        }
        else if (p_3==2){
            cout<<"3            Achari Baingan             half                "<<a_h<<endl;
            total=total+a_h;
        }
        else if (p_3==3){
            cout<<"3            Achari Baingan             quarter             "<<a_q<<endl;
            total=total+a_q;
        }
        
    }
    else if (input_3==3)
    {
        if (p_3==1) {
            cout<<"3            Jalfarezi                  full                "<<a_f<<endl;
            total=total+a_f;
        }
        else if (p_3==2){
            cout<<"3            Jalfarezi                  half                "<<a_h<<endl;
            total=total+a_h;
        }
        else if (p_3==3){
            cout<<"3            Jalfarezi                  quarter             "<<a_q<<endl;
            total=total+a_q;
        }
        
    }
    else if (input_3==4)
    {
        if (p_3==1) {
            cout<<"3            Chicken Haleem              full                "<<a_f<<endl;
            total=total+a_f;
        }
        else if (p_3==2){
            cout<<"3            Chicken Haleem              half                "<<a_h<<endl;
            total=total+a_h;
        }
        else if (p_3==3){
            cout<<"3            Chicken Haleem              quarter             "<<a_q<<endl;
            total=total+a_q;
        }
        
    }
    else if (input_3==5)
    {
        if (p_3==1) {
            cout<<"3            Daal                        full                "<<a_f<<endl;
            total=total+a_f;
        }
        else if (p_3==2){
            cout<<"3            Daal                        half                "<<a_h<<endl;
            total=total+a_h;
        }
        else if (p_3==3){
            cout<<"3            Daal                       quarter             "<<a_q<<endl;
            total=total+a_q;
        }
        
    }
    } //3
        
        cout<<""<<endl;
        cout<<""<<endl;

        cout<<"                    ITEM:   3"<<endl;
        cout<<"                    TOTAL:"<<total<<endl;
        total=0;
    
    } while ((input_1>-1 && input_2>-1 && input_3>-1) );
        
        if (input_1==-1) {
            break;
        }
        
    }
    
    if (input_1==-1 || input_2==-1 || input_3==-1) {
        cout<<endl;
        cout<<".........Exiting Program........"<<endl;
    }
    return 0;

}