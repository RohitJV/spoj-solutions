#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
//#include<conio.h>

#define pb push_back
#define INF 1000000

int n,k,m,x,y;
vector <int> v[105],ans,temp;
bool visited[105];
int out[105];

int main()
{
    memset(visited,false,sizeof(visited));
    memset(out,0,sizeof(out));
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
            cin>>x>>m;
            while(m--)
            {
                      cin>>y;
                      v[y].pb(x);
                      out[x]++;
            }
    }
    for(int i=1;i<=n;i++)
    {
                         for(int j=1;j<=n;j++)
                         {
                                 if(out[j]==0)
                                 {
                                              out[j]--;
                                              ans.pb(j);
                                              for(int k=0;k<v[j].size();k++)
                                                      out[v[j][k]]--;
                                              break;
                                 }
                         }
    }
    for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
  //  getch();
}
