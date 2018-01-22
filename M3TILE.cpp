#include<iostream>
using namespace std;
long int ans=0;

void total(int num,long int sum,long int temp)
{
     for(int i=2;;i+=2)
     {
             if(sum+i==num)
             {
                           if(i==2)
                                   temp=temp*3;
                           else
                               temp=temp*2;
                          break;
             }
             if(i==2)
                     total(num,sum+i,temp*3);
             else
                     total(num,sum+i,temp*2);
     }
     ans=ans+temp;
     //cout<<ans<<" ";
}

int main()
{
    int i;
    while(1)
    {
            cin>>i;
            if(i==-1)
                     break;
            if(i==0)
                    ans=1;
            else if(i%2!=0)
            		ans=0;
            else
                    total(i,0,1);
            cout<<ans<<"\n";
            ans=0;
    }
}

