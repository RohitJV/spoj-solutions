#include<stdio.h>
int main()
{
	int a[1000000],n,k,max=0,p=0,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	for(int i=0;i<n-k+1;i++)
	{
		if(p>=i)
			x=p;
		else
		{
			x=i;
			max=a[i];
		}
		for(int j=x;j<k+i;j++)
		{
			if(a[j]>=max)
			{
				max=a[j];
				p=j;
			}
		}
		printf("%d ",max);
	}
}







