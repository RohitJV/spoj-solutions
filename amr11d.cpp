#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define mp make_pair
#define pb push_back

int t,n;
string s,temp;

bool calc(int x)
{
    int i;
    if(x<temp.size()-1)
        return false;
    for(i=x;x-i+1<=temp.size();i--)
    {
        if(temp[x-i]!=s[i])
            return false;
    }
    return true;
}

int main()
{
    bool flag=true,tf;
    cin>>t;
    while(t--)
    {
        flag=true;
        cin>>s;
        n=s.size();
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                tf=false;
                temp=s.substr(j,i);
                //cout<<temp<<"\n";
                for(int k=n-1;k>=0;k--)
                {
                    if(s[k]==temp[0])
                         tf=calc(k);
                    if(tf)
                        break;
                }
                if(!tf)
                {
                    //cout<<i<<" "<<j<<"\n";
                    flag=false;
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
