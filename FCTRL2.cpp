#include<stdio.h>
#define MAX 10000
 
int len = 0;
int fact[MAX];
 
void factorial(int);
void multiply(int);
 
int main()
{
int t,n,i;
 
scanf("%d",&t);
 
for(int j=0;j<t;j++)
{
scanf("%d",&n);
fact[0]=1;
factorial(n);
for(i=len;i>=0;i--)
{
printf("%d",fact[i]);
}
len=0;
printf("\n");
}
}
 
void factorial(int n)
{
int i;
for(i=2;i<=n;i++){
multiply(i);
}
}
 
void multiply(int n)
{
long i,r=0;
int arr[MAX];
for(i=0;i<=len;i++)
{
arr[i]=fact[i];
}
 
for(i=0;i<=len;i++)
{
fact[i] = (arr[i]*n + r)%10;
r = (arr[i]*n + r)/10;
}
if(r!=0)
while(r!=0)
{
fact[i]=r%10;
r= r/10;
i++;
}
len = i-1;
}
 
