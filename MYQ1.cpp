#include<stdio.h>
int main()
{
    int t,temp;
    long int a[100000],b[100000],c[100000];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    scanf("%ld",&a[i]);
    for(int i=0;i<t;i++)
    {
            a[i]=a[i]-1;
            temp=a[i]%5;
            if(temp==0)
                       b[i]=a[i]/5;
            else
                       b[i]=a[i]/5 + 1;
            if(b[i]%2==0)
            {
                     c[i]=a[i]%5;
                     switch(c[i])
                     {
                                 case 0 : c[i]=1;
                                          break;
                                 case 4 : c[i]=2;
                                          break;
                                 case 3 : c[i]=3;
                                          break;
                                 case 2 : c[i]=4;
                                          break;
                                 case 1 : c[i]=5;
                                          break;
                     }
            }
            else 
            {    
                     c[i]=a[i]%5;
            }                                 
    }
    for(int i=0;i<t;i++)
    {
            if(b[i]==0)
                       printf("poor conductor\n");
            else
            {
                       printf("%ld",b[i]);
                       if(c[i]==1)
                       printf(" W L\n");
                       else if(c[i]==2)
                       printf(" A L\n");
                       else if(c[i]==3)
                       printf(" A R\n");
                       else if(c[i]==4)
                       printf(" M R\n");
                       else
                       printf(" W R\n");
            }
    }
}                
