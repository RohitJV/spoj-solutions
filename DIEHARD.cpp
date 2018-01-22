#include<iostream>
using namespace std;

int main()
{
	int t,a,h,i,s[1000][1000],temp;
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			if(i-2<=0 || j-8<=0)
				temp=0;
			else
				temp=s[i-2][j-8]+1;
			if(i-17<=0)
				temp=max(temp,0);
			else
				temp=max(temp,s[i-17][j+7]+1);
			s[i][j]=temp;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>h>>a;
		cout<<(s[h][a]+1)*2-1<<"\n";
	}
}