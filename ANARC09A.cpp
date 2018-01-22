#include<iostream>
using namespace std;

int main()
{
	int i,n,count,x,y,z=0;
	char s[3000];
	while(1)
	{
		z++;
		x=0;
		y=0;
		count=0;
		cin>>s;
		if(s[0]=='-')
			break;
		if(s[0]=='}')
			count++;
		x++;
		for(i=1;s[i]!='\0';i++)
		{
			if(s[i]=='{')
				x++;
			else
				y++;
			if(y>x)
			{
				y--;
				x++;
				count++;
			}
		}
		if(y>x)
			count=count+(y-x)/2;
		else 
			count=count+(x-y)/2;
		cout<<z<<". "<<count<<"\n";
	}
}
			
			
