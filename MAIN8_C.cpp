#include<iostream>
using namespace std;

long a[50005],k,l,h,mid,cnt;
int t,n;

long calc(long x)
{
    cnt=0;
	for(int i=0;i<n;i++)
		cnt=cnt+a[i]/x;
	return cnt;
}

int main()
{
	cin>>t;
	while(t--)
	{
		l=h=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			h=max(h,a[i]);
		}
        //cout<<h<<" ";
		while(l<h)
		{
			mid=l + (h-l+1)/2;
			if( calc(mid)>=k )
				l=mid;
			else
				h=mid-1;
		}
		cout<<l<<"\n";
	}
}
