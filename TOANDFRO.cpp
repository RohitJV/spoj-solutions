#include<stdio.h>


int main()
{
    int n,i;
    char str[100][200];
    char temp[200];
    for(i=0;;i++)
    {
                 scanf("%d",&n);
                 if(n==0)
                         break;
                 scanf("%s",temp);
                 int len,x=0;
                 for(len=0;temp[len]!='\0';len++);
                 
                 for(int k=0;k<n;k++)
                 {
                         for(int j=0;j<len/n;j++)
                         {
                                 if(j%2==0)
                                 {
                                           str[i][x]=temp[(n*j)+k];
                                 }
                                 else
                                 {
                                           str[i][x]=temp[(n*j)+n-1-k];
                                 }
                                 x++;
                         }
                 }        
                 str[i][x]=='\0';
    }
    for(int l=0;l<i;l++)
    {
            printf("%s\n",str[l]);
    }

}
                 

