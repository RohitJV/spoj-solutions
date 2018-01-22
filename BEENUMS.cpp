#include<iostream>
using namespace std;
int main()
{
	int n,i;
	while(1)
	{
		i=1;
		cin>>n;
		if(n==-1)
			break;
		n=n-1;
		while(n>0)
		{
			n=n-(6*i);
			i++;
		}
		if(n==0)
			cout<<"Y\n";
		else
			cout<<"N\n";
	}
}
