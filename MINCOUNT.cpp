#include<stdio.h>

int main()
{
	int t,i;
	unsigned long long int n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lli",&n);
		printf("%lli\n",n*(n+1)/6);
	}
}

