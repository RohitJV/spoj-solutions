#include<iostream>
#include<stdio.h>
using namespace std;
int t,m,n,r=1,x,pos,temp[2002],src[2002];
bool a[2002][2002];
 
void bfs(int src[2002],int num,bool a[2002][2002],char sex[2002],int gender)
{   
    pos=0;
    x=0;
    //cout<<"inside bfs, "<<r<<" "<<num<<"\n";
    //for(int i=0;i<num;i++)
    //    cout<<src[i]<<" ";
    //cout<<"\n";
    //for(int i=0;i<n;i++)
    //{
    //    for(int j=0;j<n;j++)
    //        cout<<a[i][j]<<" ";
    //    cout<<"\n";
    //}
    for(int i=0;i<num;i++)
    {
        
        for(int j=0;j<n;j++)
            a[j][src[i]]=0;
        //for(int k=0;k<n;k++)
        //{
        //for(int j=0;j<n;j++)
        //    cout<<a[k][j]<<" ";
        //cout<<"\n";
        //}
        for(int j=0;j<n;j++)
        {
            //cout<<i<<" "<<src[i]<<","<<j<<"\n"; 
            if(a[src[i]][j]==1)
            {
                //cout<<"appl : "<<j<<"\n";
                if((gender==0 && sex[j]=='M') || (gender==1 && sex[j]=='F'))
                    r=0;
                else
                {
                    x=1;
                    if(gender==0)
                        sex[j]='F';
                    else
                        sex[j]='M';
                    //cout<<"\nsrc"<<src[i]<<"\n";
                    temp[pos++]=j;
                }
                //cout<<"\nsrc"<<src[i]<<"\n";
            }
        }
    }
    num=pos;
    for(int i=0;i<num;i++)
        src[i]=temp[i];
    if(r==1 && x==1)
        bfs(src,num,a,sex,(gender+1)%2);
}
 
int main()
{
    int z=1;
    scanf("%d",&t);
    while(t--)
    {
            printf("Scenario #%d:\n",z++); 
            int q=1;
            r=1;
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    a[i][j]=0;
            for(int i=0;i<m;i++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x--;
                y--;
                a[x][y]=a[y][x]=1;
            }
            char sex[2002];
            for(int i=0;i<n;i++)
                sex[i]='X';
            for(int i=0;i<n;i++)
            {
                if(sex[i]=='X')
                {
                    sex[i]='M';
                    src[0]=i;
                    bfs(src,1,a,sex,0);
                }
                if(r==0)
                {
                    q=0;
                    break;
                }
            }
            if(q==0)
                printf("Suspicious bugs found!\n");
            else
                printf("No suspicious bugs found!\n");
    }
}

