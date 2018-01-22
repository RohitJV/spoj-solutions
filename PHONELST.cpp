#include<iostream>
using namespace std;
#include<string.h>

struct num
{
	char a[11];
	int l;
};

int main()
{
	num s[20000],temp;
	int t,n,i,j,k,r,x,q;
	cin>>t;
	for(i=0;i<t;i++)
	{
		q=0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>s[j].a;
			s[j].l=strlen(s[j].a);
		}
		for(j=0;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(s[j].l>s[k].l)
				{
					temp=s[j];
					s[j]=s[k];
					s[k]=temp;
				}
			}
		}
		for(j=0;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				r=1;
				for(x=0;s[j].a[x]!='\0';x++)
				{
					if(s[j].a[x]!=s[k].a[x])
					{
						r=0;
						break;
					}
				}
				if(r==1)
				{
					q=1;
					cout<<"NO\n";
					break;
				}
			}
			if(q==1)
				break;
		}
		if(q==0)
		{
			cout<<"YES\n";
		}
	}
}
	
	
	
			