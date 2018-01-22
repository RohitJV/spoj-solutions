#include<iostream>
using namespace std;
int main()
{
	int a[10],sum=0,c;
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<10;i++)
	{
		if(sum+a[i]==100)
		{
			c=100;
			break;
		}
		else if(sum+a[i]>100)
		{
			if(sum+a[i]-100 > 100-sum)
			{
				c=sum;
				break;
			}
			else
			{
				c=sum+a[i];
				break;
			}
		}
		else
		{
			sum=sum+a[i];
			c=sum;
		}
	}	
	cout<<c;
}
		
			









