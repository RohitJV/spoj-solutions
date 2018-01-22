#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
 
int main()
{
    int t,n,m,s[200000];
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        vector<int> a (s,s+n);
        sort(a.begin(),a.begin()+n);
        //for(int i=0;i<n;i++)
        //    cout<<a[i]<<" ";
        int i=0,j=n-1;
        while(1)
        {
            if(i==j)
                break;
            else
            {
                if(a[i]+a[j]==m)
                {
                    count++;
                    i++;
                    if(i==j)
                        break;
                    j--;
                }
                else if(a[i]+a[j]<m)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
        printf("%d\n",count);
    }
}
