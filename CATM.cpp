#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t,n,m,a[101][101],flag,a1,a2,b1,b2,c1,c2;;
	cin>>m>>n;
	cin>>t;
	while(t--)
	{
		cin>>a1>>a2>>b1>>b2>>c1>>c2;
		if( (a1<=b1 && a1<=c1) || (a1>=b1 && a1>=c1) || (a2>=b2 && a2>=c2) || (a2<=b2 && a2<=c2) )
			cout<<"YES\n";
		else
		{
			flag=0;
			if(a1<min(b1+abs(b2-a2),c1+abs(c2-a2)))
				flag=1;
			if(a2<min(b2+abs(b1-a1),c2+abs(c1-a1)))
				flag=1;
			if(m-a1<min(m-b1+abs(b2-a2),m-c1+abs(c2-a2)))
				flag=1;
			if(n-a2<min(n-b2+abs(b1-a1),n-c2+abs(c1-a1)))
				flag=1;
			if(flag==1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
} 
