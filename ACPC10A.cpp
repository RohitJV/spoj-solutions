#include<stdio.h>
int main()
{
	int a[10000],b[10000],x,y,z,i,m1,m2;
	for(i=0;;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==0 &&y ==0 && z==0)
			break;
		if((x+z)==(2*y))
		{
			a[i]=1;
			b[i]=z+y-x;
		}
		else
		{
			a[i]=2;
			b[i]=z*y/x;
		}
	}
	for(int k=0;k<i;k++)
	{
		if(a[k]==1)
			printf("AP %d\n",b[k]);
		else
			printf("GP %d\n",b[k]);
	}
}
	
	








