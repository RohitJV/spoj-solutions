#include<stdio.h>

int main()
{
    long int a[4],l,x=1;
    while(scanf("%ld",&a[0])!=EOF)
    {
                                  scanf("%ld%ld%ld",&a[1],&a[2],&a[3]);
                                  for(int i=0;i<3;i++)
                                  {
                                          for(int j=i+1;j<4;j++)
                                          {
                                                  if(a[i]<a[j])
                                                  {
                                                               int temp;
                                                               temp=a[i];
                                                               a[i]=a[j];
                                                               a[j]=temp;
                                                  }
                                          }
                                  }
                                  l=a[0]+a[1];
                                  printf("Case %ld: %ld\n",x++,l);
    }
}
                                                  
