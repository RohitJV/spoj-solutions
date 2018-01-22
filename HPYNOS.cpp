#include<iostream>
using namespace std;
int main()
{
        long int n,num,count=0,i;
        cin>>n;
        while(1)
        {
                num=0;
                for(i=0;n!=0;i++)
                {
                        num=num+((n%10)*(n%10));
                        n=n/10;
                }
                n=num;
                count++;
                if(n==1)
                {
                        cout<<count<<"\n";
                        break;
                }
                else if(n==4)
                {
                        cout<<-1<<"\n";
                        break;
                }
         }
}
  
