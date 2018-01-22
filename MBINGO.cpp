#include<iostream.h>

int main()
{
	int a[100]={0},x[100],count,i,j;
	int n,b;
	while(1)
	{
		count=0;
		cin>>n>>b;
		if(n==0 && b==0)
			break;
		
		for(i=0;i<=b;i++)
		{
			cin>>x[i];
			if(i==0)
			{
				a[x[i]]=1;
				count=1;
			}
			else
			{
				if(a[x[i]]==0)
				{
					a[x[i]]=1;
					count++;
				}
				for(j=0;j<i;j++)
				{
					if(x[i]>x[j])
					{
						if(a[x[i]-x[j]]==0)
						{
							a[x[i]-x[j]]=1;
							count++;
						}
					}
					else
					{
						if(a[x[j]-x[i]]==0)
						{
							a[x[j]-x[i]]=1;
							count++;
						}
					}
				}
			}
		}
		if(count==n)
			cout<<"Y\n";
		else
			cout<<"N\n";
	}
}
