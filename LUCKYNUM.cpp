#include<iostream>
using namespace std;
 
int main()
{
        int t,n,k,a[2][1000],pos,i;
        cin>>t;
        while(t--)
        {
                int flag=-1;
                cin>>k;
                int r=0;
                n=2;
                pos=0;
                a[0][0]=6;
                a[0][1]=8;
                if(a[0][0]%k==0)
                     flag=0;
                else if(a[0][1]%k==0)
                     flag=1;
                for(i=0;flag==-1 && n!=201;i++)
                {
                        n+=1;
                        a[(pos+1)%2][0]=(a[pos][0]%k)*10+6;
                        if(a[(pos+1)%2][0]%k==0)
                        {
                                flag=0;
                        }
                        if(flag==-1)
                           for(int j=n-1;j>1;j--)
                           {
                                a[(pos+1)%2][j]=(a[pos][j-1]%k)*10+6;
                                if(a[(pos+1)%2][j]%k==0)
                                        flag=j;
                           }
                        if(flag==-1)
                        {
                              a[(pos+1)%2][1]=(a[pos][1]%k)*10+8;
                              if(a[(pos+1)%2][1]%k==0)
                                  flag=1;
                        }
                        pos=(pos+1)%2;
                }       
                flag++;
                if(n==201)
                        cout<<-1<<"\n";
                else
                {
                        if(flag==1)
                        {
                                for(int j=0;j<n-1;j++)
                                        cout<<6;
                        }
                        else
                        {
                                for(int j=flag-2;j<n-1;j++)
                                        cout<<8;
                                for(int j=0;j<flag-2;j++)
                                        cout<<6;
                        }
                        cout<<"\n";
                }
        }
}
 