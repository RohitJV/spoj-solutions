#include<iostream>
using namespace std;
int main()
{
	int n,i,a[1000],s[1000],j;
	for(i=0;;i++)
	{
		cin>>n;
		if(n==0)	
			break;
		for(j=0;j<n;j++)
			cin>>a[j];
		for(j=0;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[j]>a[k])
				{
					int temp;
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
			}
		}
		s[i]=0;
		for(j=0;j<n-1;j++)
		{
			if(a[n-1]<1322)
			{
				s[i]=1;
				break;
			}
			if(a[j+1]-a[j]>200)
			{
				s[i]=1;
				break;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		if(s[j]==1)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<"POSSIBLE\n";
	}
}



