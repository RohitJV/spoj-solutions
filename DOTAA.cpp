#include<iostream>
using namespace std;
int main()
{
	int t,s[500],n,m,d,a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		s[i]=0;
		cin>>n>>m>>d;
		for(int j=0;j<n;j++)
		{
			cin>>a;
			s[i]=s[i]+(a/d);
			if(a%d==0)
				s[i]--;
		}
		if(s[i]>=m)
			s[i]=1;
		else
			s[i]=0;	
	}
	for(int i=0;i<t;i++)
	{
		if(s[i]==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
