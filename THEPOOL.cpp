#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
 
int n;
long long x,y,a[100005],b[100005],m,t,res;
vector <int> v;
 
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    cin>>m>>t;
    m--;
    for(int i=0;i<n;i++)
    {
        res=a[i]+b[i]*t;
        if(res<=0)
            res=0;
        if(res>=100000)
            res=100000;
        v.push_back(res);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(i==m)
        {
            cout<<v[i];
            break;
        }
    }
}
