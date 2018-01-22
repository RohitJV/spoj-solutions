#include<iostream>
using namespace std;
 
int a[4],b[4],c[4];
int max(int i,int j)
{
    if(c[i]>c[j])
         return i;
    else
        return j;
}
int main()
{
    int x,y;
        while(1)
        {
                for(int i=0;i<4;i++)
                        cin>>a[i];
                for(int i=0;i<4;i++)
                        cin>>b[i];
                if(a[0]==-1)
                        break;
                for(int i=0;i<4;i++)
                {
                        c[i]=a[i]/b[i];
                        if(a[i]%b[i]!=0)
                                c[i]++;
                }
                x=max(max(0,1),max(2,3));
        y=c[x];
        cout<<b[0]*y-a[0]<<" "<<b[1]*y-a[1]<<" "<<b[2]*y-a[2]<<" "<<b[3]*y-a[3]<<" ";
        cout<<"\n";
  }
}
   
