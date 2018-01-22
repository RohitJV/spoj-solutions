#include<stdio.h>
int main()
{
	long long int s[10000],a,b,c;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		s[i] = a*a - 2*b;
	}
	for(int i=0;i<t;i++)
	{
		printf("%lld\n",s[i]);
	}
}



