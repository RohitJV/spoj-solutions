#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{ 
        int a[2][3],pos,n,t=1,x,y,z;
        while(1)
        {
                cin>>n;
                if(n==0)
                        break;
                cin>>x>>y>>z;
                a[0][0]=1000005;
                a[0][1]=y;
                a[0][2]=a[0][1]+z;
                pos=0;
                for(int i=1;i<n;i++)
                {
                        int temp=(pos+1)%2;
                        cin>>x>>y>>z;
                        a[temp][0]=min(a[pos][0]+x,a[pos][1]+x);
                        a[temp][1]=min(min(a[temp][0]+y,a[pos][0]+y),min(a[pos][1]+y,a[pos][2]+y));
                        a[temp][2]=min(a[temp][1]+z,min(a[pos][1]+z,a[pos][2]+z));
                        pos=temp;
                }
                cout<<t++<<". "<<a[pos][1]<<"\n";
        }
}

