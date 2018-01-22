#include<iostream>
#include<algorithm>
using namespace std;
 
int op(int a,char x,int b)
{
    if(x=='+')
        return(a+b);
    else if(x=='*')
        return(a*b);
}
 
int main()
{
    int t,m1,m2,a1,b1;
    char s[105];
    char a[100];
    int b[100][100];
    cin>>t;
    while(t--)
    {
        a1=b1=0;
        cin>>s;
        for(int i=0;s[i]!='\0';i++)
        {
            if(i%2==0)
            {
                b[b1][b1]=s[i]-48;
                b1++;
            }
            else
                a[a1++]=s[i];
        }
        for(int i=1;i<b1;i++)
        {
            for(int j=0;j<b1-i;j++)
            {
                m1=-1;
                for(int k=0;k<i;k++)
                {
                    //cout<<b[j][j+k]<<" "<<a[j+k]<<" "<<b[j+k+1][j+i]<<"\n";
                    m1=max(m1,op(b[j][j+k],a[j+k],b[j+k+1][j+i]));
                }
                b[j][j+i]=m1;
                //cout<<m1<<"\n";
            }
            //cout<<"\n--------------------------------\n";
        }
        cout<<b[0][b1-1]<<" ";
        for(int i=1;i<b1;i++)
        {
            for(int j=0;j<b1-i;j++)
            {
                m1=10000000;
                for(int k=0;k<i;k++)
                {
                    //cout<<b[j][j+k]<<" "<<a[j+k]<<" "<<b[j+k+1][j+i]<<"\n";
                    m1=min(m1,op(b[j][j+k],a[j+k],b[j+k+1][j+i]));
                }
                b[j][j+i]=m1;
                //cout<<m1<<"\n";
            }
            //cout<<"\n--------------------------------\n";
        }
        cout<<b[0][b1-1]<<"\n";
        
    }
}