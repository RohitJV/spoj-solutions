#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 10000

int n,m,x;
string s[20];
int res;

int getconfig(int row)
{
	int ret=0,cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[row][i]=='.')
			ret=ret|(1<<cnt);
		cnt++;
	}
	return ret;
}

void calc(int row,int config,int setbits,int total)
{
	if(row==m)
	{
	    if(config==(int)((1<<n)-1))
            res=min(res,total);
        return;
	}
	int cur=getconfig(row)^setbits;
	int temp=config,cnt=0,nextset=0;
	for(int i=0;i<n;i++)
	{
		if(!(config&(1<<i)))
		{
		    if(i==0)
                cur=cur^(3<<i);
            else if(i==n-1)
                cur=cur^(3<<(n-2));
            else
                cur=cur^(7<<(i-1));
			cnt++;
			nextset=nextset|(1<<i);
		}
	}
	cur=cur&((1<<n)-1);
	calc(row+1,cur,nextset,total+cnt);
}

void build()
{
	int config=getconfig(0);
	calc(1,config,0,0);
	for(int i=1;i<(1<<n);i++)
	{
		int store=config,temp=i,cnt=0;
		for(int j=0;j<n;j++)
		{
			if(temp&(1<<j))
			{
				cnt++;
				if(j==0)
					store=store^3;
				else if(j==n-1)
					store=store^(3<<(n-2));
				else
					store=store^(7<<(j-1));
			}
		}
		store=store&((1<<n)-1);
		calc(1,store,i,cnt);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	while(1)
	{
	    res=INF;
		cin>>m>>n;
		x=n+1;
		if(n==0 && m==0)
			break;
		for(int i=0;i<m;i++)
			cin>>s[i];
		build();
		if(res==INF)
            cout<<"Damaged billboard.\n";
        else
            cout<<"You have to tap "<<res<<" tiles.\n";
	}
}

