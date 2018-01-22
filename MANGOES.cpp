#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
	long long int n,m,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		m=n;
		n=n-2;
		if(n%2==0)
			n--;
		n=n/2+1;
        n=n*n;
        //cout<<n<<" ";
        if(n >= m)
        {
            x=n/m;
            x=x*m;
            n=n-x;
        }
		cout<<n<<"\n";
	}
}

