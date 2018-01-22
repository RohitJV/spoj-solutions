#include<iostream>
using namespace std;
int main()
{
	int t,s[30],a;
	long int b;
	char a1[1000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int j;
		cin>>a1>>b;
		for(j=0;a1[j]!='\0';j++);
		a=a1[j-1]-48;
		
		if(a==0 && b==0)
			s[i]=0;			
		else if(b==0)
			s[i]=1;
		else
		{
			b=b%4;
			if(b==0)
				s[i]=(a*a*a*a)%10;
			else if(b==1)
				s[i]=a%10;
			else if(b==2)
				s[i]=(a*a)%10;
			else
				s[i]=(a*a*a)%10;
		}
	}
	for(int i=0;i<t;i++)
		cout<<s[i]<<"\n";
}	






