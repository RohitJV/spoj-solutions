#include<iostream>
using namespace std;

int main()
{
	int n;
	char a[60000];
	cin>>n;
	while(n--)
	{
		cin>>a;
		int r1=0,r2=0;
		for(int i=0;a[i]!='\0';i++)
		{
			r1=(r1*10+a[i]-48)%252;
			r2=(r2*10+a[i]-48)%525;
		}
		if(r1==0)
			cout<<"Yes ";
		else
			cout<<"No ";
		if(r2==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
			
			