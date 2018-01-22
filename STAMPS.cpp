#include<iostream>
using namespace std;

int main()
{
	int t,arr[10000];
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int s,n,a[1000],sum=0;
		cin>>s>>n;
		for(int h=0;h<n;h++)
			cin>>a[h];			
		for(int j=0;j<n;j++)
		{
			for(int k=j;k<n;k++)
			{
				if(a[k]>a[j])
				{
					int temp;
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
			}
			sum+=a[j];
			if(sum>=s)
			{
				arr[i]=j+1;
				break;
			}
		}
		if(sum<s)
			arr[i]=-1;
	}
	for(int i=0;i<t;i++)
	{
		cout<<"Scenario #"<<i+1<<":\n";
		if(arr[i]==-1)
			cout<<"impossible\n\n";
		else
			cout<<arr[i]<<"\n\n";
	}
}








