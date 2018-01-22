#include <stdio.h>
#include <stdlib.h>

int fi(int n) 
     { 
       int result = n,i; 
       for(i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) result -= result / i; 
         while (n % i == 0) n /= i; 
       } 
       if (n > 1) result -= result / n; 
       return result; 
     } 

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i=1;
        int H= 0;
        for(i=1;i<=n;i++)
        {
            H+= fi(i);
        }
        unsigned long long int h = H;
        unsigned long long int x = h*h;
        printf("%lld\n",x);
    }
}

