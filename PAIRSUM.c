#include<stdio.h>
 
int main()
{
        int a[100005],i,n,m,x,y;
        long long b[100005],p[100005];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
                if(i!=0)
                {
                        b[i]=b[i-1]+a[i];
                        p[i]=p[i-1]+b[i]*a[i];
                }
                else
                {
                        b[i]=a[i];
                        p[i]=b[i]*a[i];
                }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
                scanf("%d%d",&x,&y);
                printf("%llu\n",p[y]-p[x-1]-(b[y]-b[x-1])*b[x-1]);
        }
        return 0;
}



