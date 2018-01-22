#include<iostream>
using namespace std;
int main()
{
	int a,d,x[20],y[20],a1,temp,i,j;
	while(1)
	{
		a1=20000;
		cin>>a>>d;
		if(a==0 & d==0)
			break;
		for(i=0;i<a;i++)
		{
			cin>>x[i];
			if(x[i]<a1)
				a1=x[i];
		}
		for(i=0;i<d;i++)
		{
			cin>>y[i];
		}
		for(i=0;i<2;i++)
		{
			for(j=i+1;j<d;j++)
			{
				if(y[i]>y[j])
				{
					temp=y[i];
					y[i]=y[j];
					y[j]=temp;	
				}
			}
		}
		if(a1>=y[1] || (a1>=y[0] && a1>=y[1]))
		{
			cout<<"N\n";
		}
		else
			cout<<"Y\n";
	}
}

