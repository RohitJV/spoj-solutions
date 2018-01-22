#include<iostream>

using namespace std;
int main()
{
	int t,s[30],a;
	long int b;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		if(b==0)
			s[i]=1;
		else
		{
			b=b%4;
			if(b==0)
				s[i]=((a%10)*(a%10)*(a%10)*(a%10))%10;
			else if(b==1)
				s[i]=((a%10))%10;
			else if(b==2)
				s[i]=((a%10)*(a%10))%10;
			else
				s[i]=((a%10)*(a%10)*(a%10))%10;
		}
	}
	for(int i=0;i<t;i++)
		cout<<s[i]<<"\n";
}	



