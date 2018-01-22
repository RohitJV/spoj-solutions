#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
//#include<conio.h>
 
#define pb push_back
 
typedef pair<long,int> li;
typedef vector<li> vli;
 
vector < pair<long,int> > v[10010];
 
int n,t,k,x;
string s;
bool visited[10010];
long sum=0,y;
 
int main()
{
    cin>>t;
    while(t--)
    {
              sum=0;
              memset(visited,false,sizeof(visited));
              for(int i=0;i<10010;i++)
                      v[i].clear();
              li temp;
              priority_queue <li,vector<li>,greater<li> > pq;
              cin>>n;
              for(int i=1;i<=n;i++)
              {
                      cin>>s;
                      cin>>k;
                      while(k--)
                      {
                                cin>>x>>y;
                                temp=li(y,x);
                                v[i].pb(temp);                  
                      }
              }
              visited[1]=true;
              int pos=1;
              for(int i=1;i<n;i++)
              {
                      for(int j=0;j<v[pos].size();j++)
                              pq.push(v[pos][j]);
                      while(1)
                      {
                              temp=pq.top();
                              pq.pop();
                              if(!visited[temp.second])
                              {
                                   sum=sum+temp.first;
                                   visited[temp.second]=true;
                                   pos=temp.second;
                                   break;
                              }
                      }
              }
              cout<<sum<<"\n";
    }
    //getch();
}
 