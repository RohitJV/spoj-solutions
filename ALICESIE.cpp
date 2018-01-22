#include<stdio.h>
int main()
{
	int t,a[1000],n,s[1000];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		a[i]=0;
		scanf("%d",&n);
		s[0]=0;
		for(int j=1;j<=n;j++)
		{
			s[j]=j;
		}
		for(int j=n;j>=2;j--)
		{
			for(int k=2;k<j;k++)
			{
				if(s[j]%s[k]==0)
					s[k]=-1;
			}
		}
		for(int j=2;j<=n;j++)
		{
			if(s[j]!=-1)
				a[i]=a[i]+1;
		}
	}
	for(int i=0;i<t;i++)
		printf("%d\n",a[i]);
}



