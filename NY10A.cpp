#include<iostream>
using namespace std;
int main()
{
	int p,n,a[1000][20];
	char s[50];
	cin>>p;
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<8;j++)
			a[i][j]=0;
		cin>>n>>s;
		for(int j=0;j<=37;j++)
		{
			if(s[j]=='T')
			{
				if(s[j+1]=='T')
				{
					if(s[j+2]=='T')
						a[i][0]++;
					else
						a[i][1]++;
				}
				else
				{
					
					if(s[j+2]=='T')
						a[i][2]++;
					else
						a[i][3]++;
				}
			}
			else
			{
				if(s[j+1]=='T')
				{
					if(s[j+2]=='T')
						a[i][4]++;
					else
						a[i][5]++;
				}
				else
				{
					
					if(s[j+2]=='T')
						a[i][6]++;
					else
						a[i][7]++;
				}
			}
		}
	}
	for(int i=0;i<p;i++)
	{
		cout<<i+1;
		for(int j=0;j<8;j++)
			cout<<" "<<a[i][j];
		cout<<"\n";
	}
}
			