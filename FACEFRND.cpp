#include<stdio.h>
int main()
{
	int n,a[100][102],count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		count=count+a[i][1];
		for(int j=0;j<a[i][1];j++)
			scanf("%d",&a[i][j+2]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i][1];j++)
		{
			for(int k=i+1;k<n;k++)
			{
				for(int l=0;l<a[k][1];l++)
				{
					if(a[i][j+2]!=-1)
					{
						if(a[i][j+2]==a[k][l+2])
						{
							a[k][l+2]=-1;
							count--;
						}
					}
				}
			}
		}
	}
			
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<a[j][1];k++)
			{
				if(a[i][0]==a[j][k+2])
					count--;
			}
		}
	}
	printf("%d",count);
}
		
			

