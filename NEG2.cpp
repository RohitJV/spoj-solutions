#include<stdio.h>
int main()
{
	long int n,x[1000],i=0;
	scanf("%ld",&n);
	do
	{
		if(n<0)
		{
			n=n*-1;
			x[i]=n%2;
			if(n%2==0)
				n=n/2;
			else
				n=(n+1)/2;
		}
		else
		{
			x[i]=n%2;
			n=(n/2)*-1;
		}
		i++;
	}while(n!=0);
	for(int j=0;j<i;j++)
		printf("%ld",x[i-j-1]);
}













