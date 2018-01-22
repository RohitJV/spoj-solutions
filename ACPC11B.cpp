#include<iostream>
using namespace std;
int main()
{
	long int t,a[100],x[1000],y[1000],p,q,min;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p;
		for(int j=0;j<p;j++)
		{
			cin>>x[j];
		}
		cin>>q;
		for(int j=0;j<q;j++)
		{
			cin>>y[j];
		}
		if(x[0]>y[0])
			min=x[0]-y[0];
		else
			min=y[0]-x[0];
		for(int j=0;j<p;j++)
		{
			for(int k=0;k<q;k++)
			{
				if(x[j]>y[k])
				{
					if(x[j]-y[k]<min)
						min=x[j]-y[k];
				}
				else
				{
					if(y[k]-x[j]<min)
						min=y[k]-x[j];
				}
			}
		}
		a[i]=min;
	}
	for(int i=0;i<t;i++)
		cout<<a[i]<<"\n";
}


