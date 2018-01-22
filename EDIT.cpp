#include<stdio.h>

int main()
{
    char a[100000];
    int i,j,count1,count2;
    
    while(scanf("%s",a) != EOF)
    {
                    count1=0;
                    count2=0;
                    for(j=0;a[j]!='\0';j++)
                    {
                                           if(j%2==0)
                                           {
                                                     if(a[j]<=91)
                                                                 count1++;
                                                     else        
                                                                 count2++;
                                           }
                                           if(j%2!=0)
                                           {
                                                     if(a[j]<=91)
                                                                 count2++;
                                                     else
                                                                 count1++;
                                           }
                    }
                    if(count1<count2)
                                     printf("%d\n",count1);
                    else
                                     printf("%d\n",count2);
    }
}
