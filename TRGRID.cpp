#include<stdio.h>
int main()
{
	int t,n,m;
	char a[10000];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{	
		scanf("%d%d",&n,&m);
		if(n%2==0&&m%2==0)
		{
			if(n>m)
				a[i]='U';
			else 
				a[i]='L';
		}
		else if(n%2!=0&&m%2!=0)
		{
			if(n<=m)
				a[i]='R';
			else
				a[i]='D';
		}
		else if(n%2==0&&m%2!=0)
		{
			if(n>m)
				a[i]='D';
			else
				a[i]='L';
		}
		else
		{	
			if(n>m)
				a[i]='U';
			else
				a[i]='R';
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("%c\n",a[i]);
	}
}
