#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    char a[5];
    long int n;
    int test1,test2,x,y;
    while(1)
    {
            x=1;
            y=0;
            test1=0;
            cin>>a;
            if(a[0]=='0' && a[1]=='0' && a[3]=='0')
                         break;
            n=(a[0]-48)*10 + (a[1]-48);
            n=n*pow(10,a[3]-48);
    
            while(n!=1)
            {
                       //cout<<"\n\n";
                       if(n%2==0)
                                 test2=1;
                       else
                                 test2=0;
                       //cout<<"\t"<<test1<<"\t"<<test2<<"\n\n";
                       if(test1==0)
                                   y=y+x;
                       x=x*2;
                       //cout<<"\t"<<x<<"\t"<<y<<"\n";
                       if(test2==0 && test1==0)
                                   n = n/2 +1;
                       else
                                   n=n/2;
                       //cout<<"\n"<<n<<"\n\n";
                       if( (test1+test2) %2 == 0)
                                         test1=1;
                       else
                                         test1=0;
            }
            
            cout<<x-y<<"\n";
    }
}
                                   
                       
                       
