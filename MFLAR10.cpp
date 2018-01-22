#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
	int i,j,r;
	char s[10000],x;
	while(1)
	{
		r=1;
		i=0;
		do
		{
			gets(s);
		}while(s[0]=='\0');
		if(s[0]=='*')
			break;
		if(s[0]==' ')
			i++;
		x=tolower(s[i]);
		for(j=i;s[j]!='\0';j++)
		{
			if(s[j]==' ')
			{
				if(x!=tolower(s[j+1]))
				{
					r=0;
					break;
				}
			}
		}
		if(r==0)
			cout<<"N\n";
		else
			cout<<"Y\n";
	}
}


