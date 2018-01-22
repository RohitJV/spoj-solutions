#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
 
#define pb push_back
 
int n,inp,cnt;
vector <int> v;
 
int find(int num,int x,int y)
{
    int mid;
    while(x < y)
    {
        mid=(x+y)/2;
        if(v[mid]>num)
            y=mid;
        else
            x=mid+1;
    }
    return x;
}
 
int main()
{
    while(1)
    {
        cnt=0;
        v.clear();
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>inp;
            v.pb(inp);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int res=find(v[i]+v[j],j+1,n-1);
                if(v[res]>v[i]+v[j])
                    cnt=cnt+n-res;    
            }
        }
        cout<<cnt<<"\n";
    }
}