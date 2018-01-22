#include<stdio.h>
int main()
{
	int t;
	long long int a[1000],n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%llu",&n);
		a[i] = n*(n+1) + ((n-1)*n)/2;
	}
	for(int i=0;i<t;i++)
		printf("%llu\n",a[i]%1000007);
}
