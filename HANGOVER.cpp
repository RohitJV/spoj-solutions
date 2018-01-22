#include<stdio.h>

int main()
{
	float n;
	int i,j,a[1000];
	for(i=0;;i++)
	{
		scanf("%f",&n);
		if(n==0)
			break;
		float sum=0;
		for(j=2;sum<n;j++)
		{
			sum=sum+(1/(float)(j));
		}
		a[i]=j-2;
	}

	for(int k=0;k<i;k++)
	{
		printf("%d card(s)\n",a[k]);
	}
}
					

