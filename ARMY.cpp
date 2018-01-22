#include<stdio.h>
int main()
{
	long int t,n,m,i,j,x,y,a;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		x=0;
		y=0;
		scanf("%d%d",&n,&m);;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			if(a>x)
				x=a;
		}
		for(j=0;j<m;j++)
		{
			scanf("%d",&a);
			if(a>y)
				y=a;
		}
		if(x>=y)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
}
