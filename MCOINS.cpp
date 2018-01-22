#include<iostream>
using namespace std;
 
int main()
{
        int k,l,m,a,i,j,b[1000005];
        cin>>k>>l>>m;
                b[0]=0;
                for(j=1;j<1000005;j++)
                {
                        b[j]=0;
                        if(j-1>=0 && b[j-1]==0)
                                b[j]=1;
                        else if(j-k>=0 && b[j-k]==0)
                                b[j]=1;
                        else if(j-l>=0 && b[j-l]==0)
                                b[j]=1;
                }
        for(i=0;i<m;i++)
        {
                cin>>a;
                if(b[a]==1)
                        cout<<"A";
                else
                        cout<<"B";
        }
        cout<<"\n";
        
} 


