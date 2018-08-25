#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   //decimal number
    
    
    cout<<"press 1 for decimal. "<<endl;
    cout<<"press 2 for binary. "<<endl;
    cout<<"press 3 for hexadecimal. "<<endl;
    
    int input,rand,random,decimal, hex_length;
    string hex;
    
    cout<<"Enter -1 to exit. "<<endl;
    cout<<"Input: ";
    cin>>input;
    
    while(input!=-1)
    {
    
    
        if (input==1)
        {
        cout<<"enter the decimal number. ";
        cin>>decimal;
        rand=decimal;
        random=decimal;
        
      
        int b=0;
            
     // *********************  converting decimal to binary *************************** \\
        
            /*
             logic used.
             Divide. Write the integer answer (quotient) under the long division symbol, and write the remainder (0 or 1) .
             Continue to divide until you reach 0.
             Write out the new, binary number. Starting with the bottom remainder, read the sequence of remainders upwards to the top.
             
             */
        
        cout<<"BINARY: ";
        int remain=0;
        while (rand>0) {
            b=b+1;
            rand=rand/2;
        }
        
        int bin[b];
        for (int j=0; j<b; j++)
        {
            remain=random%2;
            bin[j]=remain;
            random=random/2;
        }
        
        for (int f=b; f>0; f--) {
            cout<<bin[(f-1)];
        }

        cout<<endl;
        
        
        // **********************   converting decimal to hexadecimal   ****************\\
            
            /*
             logic used.
             Find the largest power of 16 that fits in your decimal number. Write down the decimal number you're about to convert. 
             
             Divide the decimal number by this power of 16.
             
             Find the remainder.
             
             Divide the remainder by the next highers power of 16.
             
             Find the remainder again.
             Repeat until you get a remainder below 16.
             
             */
            
        cout<<"HEXADECIMAL: ";
      
        while (decimal>=16)
        {
            
            int d=16;
            int e=16;
            while (d<=decimal)
            {
                d=d*e;
                
                if (d>decimal) {
                    d=d/16;
                    
                    break;
                }
            }
        
            int remain;
            remain=decimal/d;
            if (remain>9)
            {
                switch (remain)
                {
                    case 10:
                        cout<<"A";
                        break;
                    case 11:
                        cout<<"B";
                        break;
                    case 12:
                        cout<<"C";
                        break;
                    case 13:
                        cout<<"D";
                        break;
                    case 14:
                        cout<<"E";
                        break;
                    case 15:
                        cout<<"F";
                        break;
                        
                }
            }
            if (remain<=9)
            {
                switch (remain)
                {
                    case 0:
                        cout<<"0";
                        break;
                    case 1:
                        cout<<"1";
                        break;
                    case 2:
                        cout<<"2";
                        break;
                    case 3:
                        cout<<"3";
                        break;
                    case 4:
                        cout<<"4";
                        break;
                    case 5:
                        cout<<"5";
                        break;
                    case 6:
                        cout<<"6";
                        break;
                    case 7:
                        cout<<"7";
                        break;
                    case 8:
                        cout<<"8";
                        break;
                    case 9:
                        cout<<"9";
                        break;
                        
                }
            }
            
            decimal=decimal-(d*remain);
        }
        if (decimal<16) {
            if (decimal>9)
            {
                switch (decimal)
                {
                    case 10:
                        cout<<"A";
                        break;
                    case 11:
                        cout<<"B";
                        break;
                    case 12:
                        cout<<"C";
                        break;
                    case 13:
                        cout<<"D";
                        break;
                    case 14:
                        cout<<"E";
                        break;
                    case 15:
                        cout<<"F";
                        break;
                        
                }
            }
            if (decimal<=9)
            {
                switch (decimal)
                {
                    case 0:
                        cout<<"0";
                        break;
                    case 1:
                        cout<<"1";
                        break;
                    case 2:
                        cout<<"2";
                        break;
                    case 3:
                        cout<<"3";
                        break;
                    case 4:
                        cout<<"4";
                        break;
                    case 5:
                        cout<<"5";
                        break;
                    case 6:
                        cout<<"6";
                        break;
                    case 7:
                        cout<<"7";
                        break;
                    case 8:
                        cout<<"8";
                        break;
                    case 9:
                        cout<<"9";
                        break;
                        
                }
            }
            
            
        }
        cout<<endl;
        
        
        
            decimal=0;
        
    
        }
    
    
        else if (input==2)
        {
        // *********************  converting binary to decimal.  *************************** \\
    
        
        string in_b;
        cout<<"enter the binary number. ";  // entering the binary number in form of string.
        cin>>in_b;
        
        int l=in_b.length();  // measuring the length of the string
            int f=l-1;
        for (int i=0; i<l; i++)
        {
            int c=in_b[i]-48;       // getting the value of the binary digit by subtracting 48.
            if (c==1) {
                decimal=(decimal)+pow(2,f);
                
            }
            
            f--;
        }
        cout<<"DECIMAL: "<<decimal<<endl; // printing out the value of decimal
        
        
           
        
        //// *********************  converting hexadecimal to decimal.  *************************** \\
        
        
        cout<<"HEXADECIMAL: ";
        
        while (decimal>=16)
        {
            
            int d=16;
            int e=16;
            while (d<=decimal)
            {
                d=d*e;
                
                if (d>decimal) {
                    d=d/16;
                    
                    break;
                }
            }
            
            int remain;
            remain=decimal/d;
            if (remain>9)
            {
                switch (remain)
                {
                    case 10:
                        cout<<"A";
                        break;
                    case 11:
                        cout<<"B";
                        break;
                    case 12:
                        cout<<"C";
                        break;
                    case 13:
                        cout<<"D";
                        break;
                    case 14:
                        cout<<"E";
                        break;
                    case 15:
                        cout<<"F";
                        break;
                        
                }
            }
            if (remain<=9)
            {
                switch (remain)
                {
                    case 0:
                        cout<<"0";
                        break;
                    case 1:
                        cout<<"1";
                        break;
                    case 2:
                        cout<<"2";
                        break;
                    case 3:
                        cout<<"3";
                        break;
                    case 4:
                        cout<<"4";
                        break;
                    case 5:
                        cout<<"5";
                        break;
                    case 6:
                        cout<<"6";
                        break;
                    case 7:
                        cout<<"7";
                        break;
                    case 8:
                        cout<<"8";
                        break;
                    case 9:
                        cout<<"9";
                        break;
                        
                }
            }
            
            decimal=decimal-(d*remain);
        }
        if (decimal<16)
        {
            if (decimal>9)
            {
                switch (decimal)
                {
                    case 10:
                        cout<<"A";
                        break;
                    case 11:
                        cout<<"B";
                        break;
                    case 12:
                        cout<<"C";
                        break;
                    case 13:
                        cout<<"D";
                        break;
                    case 14:
                        cout<<"E";
                        break;
                    case 15:
                        cout<<"F";
                        break;
                        
                }
            }
            if (decimal<=9)
            {
                switch (decimal)
                {
                    case 0:
                        cout<<"0";
                        break;
                    case 1:
                        cout<<"1";
                        break;
                    case 2:
                        cout<<"2";
                        break;
                    case 3:
                        cout<<"3";
                        break;
                    case 4:
                        cout<<"4";
                        break;
                    case 5:
                        cout<<"5";
                        break;
                    case 6:
                        cout<<"6";
                        break;
                    case 7:
                        cout<<"7";
                        break;
                    case 8:
                        cout<<"8";
                        break;
                    case 9:
                        cout<<"9";
                        break;
                        
                }
            }
            
            decimal=0;
        }
        cout<<endl;
        
        

    }
    
        else if (input==3)
        {
        
        // ******************************** converting hexadecimal to decimal ********************** \\
            
            
            /*
             
             Hex is a base 16 number and decimal is a base 10 number. We need to know the decimal equivalent of every hex number digit.
             Here are the steps to convert hex to decimal:
             
             Get the decimal equivalent of hex from table.
             Multiply every digit with 16 power of digit location.
             (zero based, 7DE: E location is 0, D location is 1 and the 7 location is 2)
             Sum all the multipliers.
             */
        
        cout<<"Enter the hexadecimal number: ";
        cin>>hex;
        hex_length=hex.length();
        int c;
        int arr[hex_length];
        for (int y=0; y<hex_length; y++)
        {
            c=hex[y];
            switch (c)
            {
                case 48:
                    arr[y]=0;
                    break;
                case 49:
                    arr[y]=1;
                    break;
                case 50:
                    arr[y]=2;
                    break;
                case 51:
                    arr[y]=3;
                    break;
                case 52:
                    arr[y]=4;
                    break;
                case 53:
                    arr[y]=5;
                    break;
                case 54:
                    arr[y]=6;
                    break;
                case 55:
                    arr[y]=7;
                    break;
                case 56:
                    arr[y]=8;
                    break;
                case 57:
                    arr[y]=9;
                    break;
                case 97:
                    arr[y]=10;
                    break;
                case 98:
                    arr[y]=11;
                    break;
                case 99:
                    arr[y]=12;
                    break;
                case 100:
                    arr[y]=13;
                    break;
                case 101:
                    arr[y]=14;
                    break;
                case 102:
                    arr[y]=15;
                    break;
                case 65:
                    arr[y]=10;
                    break;
                case 66:
                    arr[y]=11;
                    break;
                case 67:
                    arr[y]=12;
                    break;
                case 68:
                    arr[y]=13;
                    break;
                case 69:
                    arr[y]=14;
                    break;
                case 70:
                    arr[y]=15;
                    break;
                    
            }
        }
        
        int r=hex_length-1;
        int dec=0;
        
        
        for (int u=0; u<hex_length; u++)
        {
            dec=dec+(arr[u]*pow(16, r));
            r--;
        }
        cout<<"DECIMAL: "<<dec<<endl;
        
        
        //***************** converting hexadecimal to binary *******************\\
        
            rand=dec;
            random=dec;
            
            
            int b=0;
            
            
            cout<<"BINARY: ";
            int remain=0;
            while (rand>0) {
                b=b+1;
                rand=rand/2;
            }
            
            int bin[b];
            for (int j=0; j<b; j++)
            {
                remain=random%2;
                bin[j]=remain;
                random=random/2;
            }
            
            for (int f=b; f>0; f--) {
                cout<<bin[(f-1)];
            }
            
            cout<<endl;
        
        
        
            
    }
        
        
        cout<<endl;
        cout<<"Enter -1 to exit."<<endl;
        cout<<"Input: ";
        cin>>input;
        
    }
    
    if (input==-1) {
        cout<<endl;
        cout<<".........EXITING PROGRAM........."<<endl;
    }
    
    return 0;
}
    







