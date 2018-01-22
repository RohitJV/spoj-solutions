#include<iostream>
using namespace std;
#include<algorithm>
#define MIN -1
int a[500][500],b[500][500],c,s[500][500];
int q,w;
 
int calc(int n,int m)
{
    if(n==0 && m==0)
    {
        s[0][0]=max(a[0][0],b[0][0]);
        return(s[0][0]);
    }
    if(n==0)
    {
        if(s[n][m-1]==MIN)
            s[n][m-1]=calc(n,m-1);
        return(max(b[n][m]+s[n][m-1],a[n][m]));
    }
    else if(m==0)
    {
        if(s[n-1][m]==MIN)
            s[n-1][m]=calc(n-1,m);
        return(max(a[n][m]+s[n-1][m],b[n][m]));
    }
    else
    {
        if(s[n-1][m]==MIN)
            s[n-1][m]=calc(n-1,m);
        if(s[n][m-1]==MIN)
            s[n][m-1]=calc(n,m-1);
        return(max(a[n][m]+s[n-1][m],b[n][m]+s[n][m-1]));
    }
}
 
int main()
{
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                s[i][j]=MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>c;
                a[i][j]=c;
                if(j>0)
                    a[i][j]+=a[i][j-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>c;
                b[i][j]=c;
                if(i>0)
                    b[i][j]+=b[i-1][j];
            }
        }
        cout<<calc(n-1,m-1)<<"\n";;
    }
}