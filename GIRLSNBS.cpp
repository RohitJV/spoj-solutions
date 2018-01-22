#include<iostream>
using namespace std;
int main()
{
	int i,j,x,y,a,b,s[1000000];
	for(i=0;;i++)
	{
		cin>>x>>y;
		if(x==-1 && y==-1)
			break;
		if(x==0)
		{
			s[i]=y;
			continue;
		}
		if(y==0)
		{
			s[i]=x;
			continue;
		}
		if(x==0 && y==0)
		{
			s[i]=0;
			continue;
		}
		else
		{
		if(x>y)
		{
			a=x;b=y;
		}
		else
		{
			a=y;b=x;
		}
		s[i] = a/(b+1);
		if(a%(b+1)!=0)
			s[i]=s[i]+1;
		}
	}
	for(j=0;j<i;j++)
		cout<<s[j]<<"\n";
}
	



