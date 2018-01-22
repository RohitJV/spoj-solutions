#include<iostream>
using namespace std;
struct ap
{
	long long int x,y,z;
	long long int a,d,n;
};
int main()
{
	int t;
	ap s[100];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>s[i].x>>s[i].y>>s[i].z;
		s[i].n = s[i].z / (s[i].x + s[i].y) * 2;
		if(s[i].z % (s[i].x+s[i].y) != 0)
		{
			s[i].n = s[i].n + 1;
		}
		s[i].d = (s[i].y-s[i].x) / (s[i].n - 5);
		s[i].a = s[i].x - 2*s[i].d; 	
	} 
	for(int i=0;i<t;i++)
	{
		cout<<s[i].n<<"\n";
		for(int j=0;j<s[i].n;j++)
			cout<<s[i].a + j*s[i].d<<" ";
		cout<<"\n";
	}
}
