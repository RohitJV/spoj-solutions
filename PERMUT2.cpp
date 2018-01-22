#include<iostream>
using namespace std;

int main()
{
	int i,n,a[100000],arr[100000];
	for(i=0;;i++)
	{
		arr[i]=1;
		cin>>n;
		if(n==0)
			break;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int j=0;j<n;j++)
		{
			if(a[a[j]-1]!=j+1)
			{
				arr[i]=0;
				break;
			}
		}
	}
	for(int k=0;k<i;k++)
	{
		if(arr[k]==0)
			cout<<"not ambiguous\n";
		else
			cout<<"ambiguous\n";
	}
}	
			
		
	


