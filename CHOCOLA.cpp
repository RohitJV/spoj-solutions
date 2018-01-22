#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
 
int s[1005][1005],t,m,n,x;
vector<int> a;
vector<int> b;
        
int f(int i,int j)
{
    if(s[i][j]!=-1)
        return(s[i][j]);
    if(i==0 && j==0)
    {
        s[0][0]=0;
        return(s[0][0]);
    }
    else if(i==0)
    {
        s[0][j]=(m-i)*b[j-1] + f(i,j-1);
        return(s[0][j]);
    }
    else if(j==0)
    {
        s[i][0]=(n-j)*a[i-1] + f(i-1,j);
        return(s[i][0]);
    }
    else
    {
        int p = (n-j)*a[i-1] + f(i-1,j);
        int q = (m-i)*b[j-1] + f(i,j-1);
        s[i][j]=min(p,q);
        return(s[i][j]);
    }
}
 
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                s[i][j]=-1;
        for(int i=0;i<m-1;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(),a.begin()+m-1);
        // for(int i=0;i<m-1;i++)
        //    cout<<a[i]<<" ";
        sort(b.begin(),b.begin()+n-1);
        cout<<f(m-1,n-1)<<"\n";
        a.clear();
        b.clear();
    }
}
