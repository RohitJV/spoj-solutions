#include<iostream>
using namespace std;
int main()
{
	int t,i,j,k,n,p,a[100],max,num,pos,count,x;
	cin>>t;
	for(i=0;i<t;i++)
	{
		count=0;
		max=-1;
		cin>>n>>p;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]>max)
				max=a[j];
		}
		num=a[p];
		pos=0;
		for(j=max;j>num;j--)
		{
			x=pos;
			for(k=x;k<x+n;k++)
			{
				if(a[k%n]==j)
				{
					count++;
					pos=k%n;	
				}
			}
		}				
		for(j=pos;j%n!=p;j++)
		{
			if(a[j%n]==num)
				count++;
		}
		cout<<count+1<<"\n";
	}
}
