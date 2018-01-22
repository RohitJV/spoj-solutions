#include<stdio.h>
#include<math.h>

int main()
{
	long int a,b,sum=0,temp,count;
	scanf("%ld%ld",&a,&b);
	for(int i=a;i<=b;i++)
	{
		count=0;
		temp=i;
		while(temp%10!=1)
		{
			temp=temp/10;
			count++;
		}
		sum=sum+pow(2,count);
	}
	printf("%ld",sum);
}



