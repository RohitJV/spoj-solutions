#include<stdio.h>
int main()
{
	int n,m,r,i,j,k,l,count1,count2,q;
	char s[300000];
	for(i=0;i<10;i++)
	{
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			q=0;
			scanf("%d",&r);
			if(r!=0)
			{
				if(s[r-1]==')')
					s[r-1]='(';
				else
					s[r-1]=')';
			}
			else
			{
				for(k=0;k<n;k++)
				{
					if(k!='(')
						continue;
					count1=0;
					count2=0;
					for(l=k+1;l<n;l++)
					{
						if(s[l]=='(')
							count1++;
						else
						{
							if(count1==count2)
							{
								q=1;
								break;
							}
							count2++;
						}
					}
					if(q==1)
						break;
				}
			}
			if(q==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
}


