#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	long int n;
	long double a[20000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(n==1)
			a[i]=2.0/3;
		else
		{
			a[i]= (long double)(2.0)/3 + (long double)(0.25) -    (long double)(1.0)/2/(n+1)/(n+2) - (long double)(1.0)/6;
		}	
	}
	for(int i=0;i<t;i++)
	{
		cout<<fixed<<setprecision(11)<<a[i]<<"\n";
	}
}
		
	





