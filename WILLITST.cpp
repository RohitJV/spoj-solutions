#include<iostream>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	for(int i=0;;i++)
	{
		if(n==1 || n==0)
		{
			cout<<"TAK";
			break;
		}
		else if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			cout<<"NIE";
			break;
		}
	}
}

