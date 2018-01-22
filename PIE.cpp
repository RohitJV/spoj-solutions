#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>
using namespace std;


int t,n,f,cnt;
double r[10005],l,h,mid,pi=acos(-1.0);

int calc(double x)
{
	double temp;
	cnt=0;
	for(int i=0;i<n;i++)
	{
		temp=pi*r[i]*r[i];
		cnt=cnt+ (int)(temp/x);
	}
	return cnt;
}

int main()
{
	cin>>t;
	while(t--)
	{
		h=l=0;
		cin>>n>>f;
		for(int i=0;i<n;i++)
		{
			cin>>r[i];
			if( pi*r[i]*r[i] > h)
				h=pi*r[i]*r[i];
		}
		for(int i=0;i<100;i++)	
		{
			mid=(l+h)/2;
			if( calc(mid)>=f+1)
				l=mid;
			else
				h=mid;			
		}
		cout<<fixed<<setprecision(4)<<l<<"\n";
	}
}