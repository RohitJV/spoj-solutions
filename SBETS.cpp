#include<iostream>
#include<string.h>
using namespace std;
int main()
{
        char a[16][5],b[5],c[5];
        int t,x,y,count;
        cin>>t;
        for(int i=0;i<t;i++)
        {
                for(int j=0;j<16;j++)
                {
                        cin>>b>>c>>x>>y;
                        if(x>y)
                        {
                                strcpy(a[j],b);
                        }
                        else
                        {
                                strcpy(a[j],c);
                        }
                }
                for(int j=0;j<16;j++)
                {
                        count=0;
                        for(int k=j;k<16;k++)
                        {
                                if( strcmp(a[j],a[k])==0 )
                                        count++;
                                if(count==4)
                                {
                                        cout<<a[j]<<"\n";
                                        break;
                                }
                        }
                }
        }
}
