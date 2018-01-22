#include<stdio.h>
 
main()
{
        int t,i;
        int n,a[100000],b[100000],j,k,temp,max;
        long long int total,c[100000];
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                max=-1000000000;
                total=0;
                scanf("%d",&n);
                for(j=0;j<n;j++)
                        scanf("%d",&a[j]);
                       if(n==1){
			printf("%d %d\n",a[0],1);
			continue;
		}
                b[0]=a[0];
                c[0]=1;
                for(j=1;j<n;j++)
                {
                        temp=a[j]+b[j-1];
                        if(temp==a[j])
                        {
                                b[j]=temp;
                                c[j]=c[j-1]+1;
                        }
                        else if(a[j]>temp)
                        {
                                c[j]=1;
                                b[j]=a[j];
                        }
                        else
                        {
                                c[j]=c[j-1];
                                b[j]=temp;
                        }
                        if(b[j]>max)
                                max=b[j];
                }
                for(j=0;j<n;j++)
                {
                        if(b[j]==max)
                                total=total+c[j];
                }
                printf("%d %lld\n",max,total);
        }
        return 0;
}








