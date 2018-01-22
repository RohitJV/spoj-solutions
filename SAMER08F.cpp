#include<stdio.h>


int main()
{
    int a[1000];
    int i,n;
    for(i=0;;i++)
    {
                 scanf("%d",&n);
                 if(n==0)
                         break;
                 int sum=0;
                 for(int j=1;j<=n;j++)
                 {
                         sum=sum+(j*j);
                 }
                 a[i]=sum;
    }
    for(int k=0;k<i;k++)
    {
            printf("%d\n",a[k]);
    }

}

