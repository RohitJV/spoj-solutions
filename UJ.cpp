#include<iostream>
using namespace std;

struct uj
{
	int a,b,n,r,pro;
};

int main()
{
	int t,i;
	uj s[1000];
	for(i=0;;i++)
	{
		cin>>s[i].a>>s[i].b;
		if(s[i].a==0 && s[i].b==0)
			break;
		s[i].n=s[i].a+s[i].b-1;
		s[i].r=s[i].b;
		for(int j=1;j<=s[i].r;j++)
			s[i].pro=s[i].pro*(s[i].n-s[i].r+j)/j;
	}
	for(int j=0;j<i;j++)
		cout<<s[i].pro;
}