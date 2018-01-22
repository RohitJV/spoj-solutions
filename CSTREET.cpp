#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
 
#define pb push_back
#define mp make_pair
 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
int t,p,n,m,x,y,z,sum;
bool visited[1005];
 
int main()
{
    cin>>t;
    while(t--)
    {
        sum=0;
        memset(visited,false,sizeof(visited));
        vector < pair<int,int> > v[1005];
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        cin>>p>>n>>m;
        while(m--)
        {
            cin>>x>>y>>z;
            v[x].pb(mp(z,y));
            v[y].pb(mp(z,x));
        }
        pq.push(mp(0,1));
        while(!pq.empty())
        {
            ii top=pq.top();
            pq.pop();
            if(visited[top.second])
                continue;
            else
            {
                int wt=top.first;
                int des=top.second;
                visited[des]=true;
                sum=sum+wt;
                for(int i=0;i<v[des].size();i++)
                {
                    int d1=v[des][i].second;
                    int v1=v[des][i].first;
                    pq.push(v[des][i]);
                }
            }
        }
        cout<<sum*p<<"\n";
    }
}
 