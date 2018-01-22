#include<iostream>
using namespace std;
#define INF 1000000
 
int main()
{
    int n,m;
    while(1)
    {
        char dir;
        int a[500][500],val,pos,visited[500],path[500];
        for(int i=0;i<500;i++)
        {
            path[i]=INF;
            visited[i]=0;
            for(int j=0;j<500;j++)
                a[i][j]=INF;
        }
        pos=0;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(int i=0;i<2*n+1;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<m;j++)
                {
                    cin>>val>>dir;
                    if(val!=0)
                        val=2520/val;
                    else 
                        val=INF;
                    if(dir=='*')
                        a[pos][pos+1]=a[pos+1][pos]=val;
                    else if(dir=='>')
                        a[pos][pos+1]=val;
                    else
                        a[pos+1][pos]=val;
                    pos++;
                }
                pos++;
            }
            else
            {
                for(int j=0;j<=m;j++)
                {
                    cin>>val>>dir;
                    if(val!=0)
                        val=2520/val;
                    else 
                        val=INF;
                    if(dir=='*')
                        a[pos][pos-m-1]=a[pos-m-1][pos]=val;
                    else if(dir=='v')
                        a[pos-m-1][pos]=val;
                    else
                        a[pos][pos-m-1]=val;
                    pos++;
                }
                pos=pos-m-1;
            }
        }
        /*for(int i=0;i<(n+1)*(m+1);i++)
        {
            for(int j=0;j<(n+1)*(m+1);j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n------------------------------\n";*/
        n=(n+1)*(m+1);
        int min,store=0,src=0;
        for(int i=0;i<n;i++)
        {
            visited[src]=1;
            //cout<<src<<" : ";
            min=-1;
            for(int j=0;j<n;j++)
            {
                if(visited[j])
                    continue;
                if(min==-1)
                        min=j;
                if(store+a[src][j]<path[j])
                    path[j]=store+a[src][j];
                if(path[j]<path[min])
                        min=j;
              //  cout<<min<<" ";
            }
            //cout<<"\n";
            src=min;
            store=path[min];
            /*for(int j=0;j<n;j++)
                cout<<path[j]<<" ";
            cout<<"\n\n";*/
        }
        if(path[n-1]==INF)
            cout<<"Holiday\n";
        else
            cout<<path[n-1]<<" blips\n";
    }
}

