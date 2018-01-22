#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[150];
	int i,l,r;
	while( scanf("%s",s)!=EOF )
	{
		r=0;
		for(i=0;s[i]!='\0';i++);
		l=i;
		if(s[0]=='_' || s[0]<=91 ||s[l-1]=='_')
			printf("Error!");
		else
		{
			for(i=0;i<l;i++)
			{
				if(s[i]=='_')
				{
					r=1;
					break;
				}
			}
			if(r!=1)
			{
				for(i=0;i<l;i++)
				{
					if(s[i]<=91)
					{
					printf("_%c",tolower(s[i]));
					}
					else
						printf("%c",s[i]);
				}
			}
			else
			{
				for(i=0;i<l;i++)
				{
					if(s[i]<=91 || (s[i]=='_' && s[i+1]<=95) )
					{
					r=-1;
					printf("Error!");
					break;
					}
				}
				if(r!=-1)
				{
					for(i=0;i<l;i++)
					{
					if(s[i]=='_')
					printf("%c",toupper(s[++i]));
					else
					printf("%c",s[i]);
					}
				}
			}
		}
		printf("\n");	
	}
}
							
					



