#include <stdio.h>
 
inline int min (int a, int b)
{
        return a < b? a:b;
}
 
int main()
{
        int T, R, C, I, J, tmp;
        scanf("%d",&T);
        while (T--){
                int arr[502][502];
                scanf("%d %d",&R, &C);
                int i, j;
                for(i=1;i<=R;i++)
                        for (j=1;j<=C;j++)
                                scanf("%d",&arr[i][j]);
 
                arr[R][C]=1;
                for (i=C-1;i>=1;i--){
                        arr[R][i]=arr[R][i+1]-arr[R][i];
                        if (arr[R][i]<=0)arr[R][i]=1;
                }
 
                for (i=R-1;i>=1;i--){
                        arr[i][C] = arr[i+1][C]-arr[i][C];
                        if (arr[i][C]<=0)arr[i][C]=1;
                }
 
                for (i=R-1;i>=1;i--)
                        for (j=C-1;j>=1;j--){
                                arr[i][j] = min (arr[i+1][j]-arr[i][j], arr[i][j+1]-arr[i][j]);
                                if (arr[i][j]<=0)arr[i][j]=1;
                        }
                printf("%d\n",arr[1][1]);
        }
        return 0;
}
