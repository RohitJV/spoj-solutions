#include<iostream>
using namespace std;
int a[105][105],b[105][105];
int t,m,n,pos[2],z,x,y,p,q,r;
 
struct node
{
    int x,y;
}cord[2][1<<20];
 
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                b[i][j]=-1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        cin>>p>>q>>r;
        b[0][0]=a[0][0];
        z=0;
        cord[0][0].x=cord[0][0].y=0;
        pos[0]=1;
        while(pos[z]!=0)
        {
            //cout<<"\n";
            int nxt=(z+1)%2;
            pos[nxt]=0;
            for(int i=0;i<pos[z];i++)
            {
                x=cord[z][i].x;
                y=cord[z][i].y;
                //cout<<x<<","<<y<<"\n";
                if(x-1>=0)
                {
                    if(b[x-1][y]!=-1)
                    {
                        if(a[x-1][y]+b[x][y]<b[x-1][y])
                        {
                            b[x-1][y]=b[x][y]+a[x-1][y];
                            cord[nxt][pos[nxt]].x=x-1;
                            cord[nxt][pos[nxt]++].y=y;
                        }
                    }
                    else
                    {
                        b[x-1][y]=b[x][y]+a[x-1][y];
                        cord[nxt][pos[nxt]].x=x-1;
                        cord[nxt][pos[nxt]++].y=y;
                    }
                }
                
                if(y-1>=0)
                {
                    if(b[x][y-1]!=-1)
                    {
                        if(a[x][y-1]+b[x][y]<b[x][y-1])
                        {
                            b[x][y-1]=b[x][y]+a[x][y-1];
                            cord[nxt][pos[nxt]].x=x;
                            cord[nxt][pos[nxt]++].y=y-1;
                        }
                    }
                    else
                    {
                        b[x][y-1]=b[x][y]+a[x][y-1];
                        cord[nxt][pos[nxt]].x=x;
                        cord[nxt][pos[nxt]++].y=y-1;
                    }
                }
                
                if(x+1<m)
                {
                    //cout<<"X+1\n";
                    if(b[x+1][y]!=-1)
                    {
                        if(a[x+1][y]+b[x][y]<b[x+1][y])
                        {
                            b[x+1][y]=b[x][y]+a[x+1][y];
                            cord[nxt][pos[nxt]].x=x+1;
                            cord[nxt][pos[nxt]++].y=y;
                        }
                    }
                    else
                    {
                        b[x+1][y]=b[x][y]+a[x+1][y];
                        cord[nxt][pos[nxt]].x=x+1;
                        cord[nxt][pos[nxt]++].y=y;
                    }
                }
                
                if(y+1<n)
                {
                    if(b[x][y+1]!=-1)
                    {
                        if(a[x][y+1]+b[x][y]<b[x][y+1])
                        {
                            b[x][y+1]=b[x][y]+a[x][y+1];
                            cord[nxt][pos[nxt]].x=x;
                            cord[nxt][pos[nxt]++].y=y+1;
                        }
                    }
                    else
                    {
                        b[x][y+1]=b[x][y]+a[x][y+1];
                        cord[nxt][pos[nxt]].x=x;
                        cord[nxt][pos[nxt]++].y=y+1;
                    }
                }
            }
            z=nxt;
            //for(int i=0;i<m;i++)
            //    for(int j=0;j<n;j++)
            //        cout<<b[i][j]<<" ";
            //cout<<"\n";
        }
        //cout<<"ANS   :   "<<b[p-1][q-1]<<"\n";
        if(b[p-1][q-1]>r)
            cout<<"NO\n";
        else
            cout<<"YES\n"<<r-b[p-1][q-1]<<"\n";
    }
}