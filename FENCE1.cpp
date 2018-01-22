#include<iostream>
using namespace std;
#include<iomanip>
#include<math.h>

int main()
{
	float l,pi=acos(-1.0);
	while(1)
	{
		cin>>l;
		if(l==0)
			break;
		l=(l*l)/(pi*2);
		cout<<fixed<<setprecision(2)<<l<<"\n";
	}
}
