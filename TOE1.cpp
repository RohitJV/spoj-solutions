#include<iostream>
using namespace std;
int main()
{
	int t,x,o,count;
	char a[3][3];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		x=0;
		o=0;
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				cin>>a[j][k];
				if(a[j][k]=='X')
					x++;
				else if(a[j][k]=='O')
					o++;
			}
		}
		if(x-o==0 || x-o==1)
		{
			count=0;
			for(int j=0;j<3;j++)
			{
				if(a[j][0]==a[j][1] && a[j][0]==a[j][2] && (a[j][0]=='X' || a[j][0]=='O'))
		 			count++;
			}
			if(count>2)
			{
				cout<<"no\n";
				continue;
			}	
			count=0;
			for(int j=0;j<3;j++)
			{
				if(a[0][j]==a[1][j] && a[0][j]==a[2][j] && (a[0][j]=='X' || a[0][j]=='O'))
					count++;
			}
			if(count>2)
			{
				cout<<"no\n";
				continue;
			}
			cout<<"yes\n";
		}
		else
			cout<<"no\n";	
	}
}
		
			





