#include<stdio.h>
using namespace std;
int main()
{
	int t,n,a[2001],i,j,x,max,pos,r;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		r=0;
		max=0;
		scanf("%d",&n);
		for(j=0;j<2001;j++)
			a[j]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			a[x+1000]++;
			//printf("\n%d %d",x,a[x+1000]);
			if(a[x+1000]>n/2)
			{
				pos=x;
				r=1;
			}		
		}
		if(r==1)
			printf("YES %d\n",pos);
		else 	
			printf("NO\n");
	}
}


