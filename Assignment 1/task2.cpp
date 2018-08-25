#include <iostream>
using namespace std;

int main()
{
    int input=0;
    int num1, num2;
    int den1=0;
    int den2=0;
    int num,den;
    int minimum;
    int hcf;
    cout<<"INSTRUCTIONS"<<endl;
    cout<<"Press 1 for addition"<<endl;
    cout<<"Press 2 for subtraction"<<endl;
    cout<<"Press 3 for multiplication"<<endl;
    cout<<"Press 4 for division"<<endl;
    cout<<"Press 5 for inverse"<<endl;
    cout<<"Press -1 to exit"<<endl;
    
    cout<<"Enter your choice : ";
    cin>>input;
    
    while (input!=-1)
    {
        
        switch (input)
        {
            case 1:              //addition
                cout<<"enter numerator of first fraction : ";
                cin>>num1;
                while (den1==0) {
                    cout<<"enter denominator of first fraction : ";
                    cin>>den1;
                    if (den1==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                cout<<"enter numerator of second fraction : ";
                cin>>num2;
                
                while (den2==0) {
                    cout<<"enter denominator of second fraction : ";
                    cin>>den2;
                    if (den2==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                num=(den2*num1)+(den1*num2);                // multiplying one deno with othe num. and then adding both.
                den=den1*den2;
                cout<<"RESULT **** "<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<"=";
                break;
                
            case 2:             //subtraction
                cout<<"enter numerator of first fraction : ";
                cin>>num1;
                while (den1==0) {
                    cout<<"enter denominator of first fraction : ";
                    cin>>den1;
                    if (den1==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                cout<<"enter numerator of second fraction : ";
                cin>>num2;
                
                while (den2==0) {
                    cout<<"enter denominator of second fraction : ";
                    cin>>den2;
                    if (den2==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                num=(den2*num1)-(den1*num2);
                den=den1*den2;
                cout<<"RESULT **** "<<num1<<"/"<<den1<<" - "<<num2<<"/"<<den2<<"=";
                break;
                
            case 3:             //multiplication
                cout<<"enter numerator of first fraction : ";
                cin>>num1;
                while (den1==0) {
                    cout<<"enter denominator of first fraction : ";
                    cin>>den1;
                    if (den1==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                cout<<"enter numerator of second fraction : ";
                cin>>num2;
                
                while (den2==0) {
                    cout<<"enter denominator of second fraction : ";
                    cin>>den2;
                    if (den2==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                num=(num1)*(num2);
                den=den1*den2;
                cout<<"RESULT **** "<<num1<<"/"<<den1<<" * "<<num2<<"/"<<den2<<"=";
                break;
                
            case 4:             //division
                cout<<"enter numerator of first fraction : ";
                cin>>num1;
                while (den1==0) {
                    cout<<"enter denominator of first fraction : ";
                    cin>>den1;
                    if (den1==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                cout<<"enter numerator of second fraction : ";
                cin>>num2;
                
                while (den2==0) {
                    cout<<"enter denominator of second fraction : ";
                    cin>>den2;
                    if (den2==0) {
                        cout<<"value of denominator cannot be zero."<<endl;
                    }
                }
                
                while (num2==0) {
                    cout<<"re-enter numerator of second fraction : ";
                    cin>>num2;
                    if (num2==0) {
                        cout<<"value of numerator cannot be zero."<<endl;
                    }
                }
                num=(num1)*(den2);
                den=den1*num2;
                cout<<"RESULT **** "<<num1<<"/"<<den1<<" ÷ "<<num2<<"/"<<den2<<"=";
                break;
            case 5:
                cout<<"enter the numerator: ";
                cin>>num1;
                cout<<"Enter the denominator: ";
                cin>>den1;
                cout<<"Inverse: "<<den1<<"/"<<num1<<endl;
                
                num=den1;
                den=num1;
                
        }
        if (num==0) {
            cout<<"0 ****";
        } else {
            
            //reducing the fraction
            //finding the highest common factor and then dividing numerator and denominator both.
            if (num<den) {
                minimum=num;
            }
            else if (den<num)
            {
                minimum=den;
            }
            for (int i=minimum; i>0; i--) {    // found minimum value. then the max number which divides both and that is the hcf.
                int x=num%i;
                int y=den%i;
                if (x==0 && y==0) {
                    hcf=i;
                    break;
                }
            }
            if (num!=den) {
                num=num/hcf;
                den=den/hcf;
                cout<<num<<"/"<<den<<" ****"<<endl;
            }
            if (num==den) {
                cout<<"1 ****"<<endl;
            }
            
        }
        num1=0;
        num2=0;
        num=0;
        den=0;
        den1=0;
        den2=0;
        cout<<"Enter your choice : ";
        cin>>input;
    }
    
    
    
    if (input==-1) {
        cout<<endl;
        cout<<"........EXITING PROGRAM........"<<endl;
    }
    
    
    return 0;
    
}