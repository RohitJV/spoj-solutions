#include<stdio.h>


int main()
{
	int a,count=1;
	scanf("%d",&a);

	for(int i=2;i<=a;i++)
	{
		for(int j=1;;j++)
		{
			if(i%j==0)
			{
				if(j<=i/j)
					count++;
				else
					break;
			}
		}
	}
	
	printf("%d",count);
}
		

