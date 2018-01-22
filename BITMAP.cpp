#include<iostream>
using namespace std;
int main()
{
	int t,m,n,r,x,y,d,min;
	char s[190][190];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
				cin>>s[j][k];
		}
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				min=1000;
				r=0;
				if(s[j][k]=='1')
					cout<<0;
				else
				{
					for(x=0;x<m;x++)
					{
					for(y=0;y<n;y++)
					{
						d=0;
						if(s[x][y]=='1')
						{
						if(x-j<0)
						d=d+j-x;
						else
						d=d+x-j;
						if(y-k<0)
						d=d+k-y;
						else
						d=d+y-k;
						}
						if(d<min)
							min=d;
					}
					}
					cout<<min;
				}
				cout<<" ";
			}
			cout<<"\n";
		}
	}
}
							
			




