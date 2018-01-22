#include<iostream>
using namespace std;
int main()
{
	int i,t,n,r,a[10000][2],j,x,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		x=0;
		cin>>n>>r;
		for(j=0;j<r;j++)
			cin>>a[j][0]>>a[j][1];
		for(j=0;j<r;j++)
		{
			for(k=0;k<r;k++)
			{
				if(k==j)
					continue;
				if(a[j][0]==a[k][1])
				{
					x=1;
					break;
				}
			}
			if(x==1)
				break;
		}		
		if(x==1)
			cout<<"Scenario #"<<i+1<<": spied\n";
		else
			cout<<"Scenario #"<<i+1<<": spying\n";
	}
}

