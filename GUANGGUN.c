#include<stdio.h>

int main()
{
	long long int n,x;
	while(scanf("%lld",&n)!=EOF)
	{
		int i;
		x=(n/9)*81;
		if(x==0)
			x=n*n;
		else
		{
			for(i=0;i<n%9;i++)
				x=x+(2*i)+1;
		}
		printf("%lld\n",x);
	}
}
