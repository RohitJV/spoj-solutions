#include<stdio.h>
int main()
{
	int t,x,y,a[100000],z;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&x,&y);
		z=y+2;
		if(x==y || x==z)
			if(x%2==0)
				a[i]=x+y;
			else
				a[i]=x+y-1;
		else
			a[i]=-1;
	}
	for(int i=0;i<t;i++)
	{
		if(a[i]==-1)
			printf("No Number\n");
		else
			printf("%d\n",a[i]);
	}
}	


