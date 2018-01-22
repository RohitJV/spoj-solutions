#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
 
#define pb push_back
#define mp make_pair
 
int n1,n2,m1,m2,cnt=1;
vector < pair<int,int> > v;
vector <int> pattern;
vector <int> text[2005];

void failure_func(int F[])
{
     int i,j;
     F[0]=0;
     j=0;
     i=1;
     
     while(i<n1)
     {
               if(pattern[i]==pattern[j])
               {
                    F[i]=j+1;
                    i++;
                    j++;
               }
               else if(j>0)
                    j=F[j-1];
               else
               {
                    F[i]=0;
                    i++;
               }
     }
}
 
void KMP()
{    
    int F[n1];
    failure_func(F);
    int i,j;
 
    for(int k=0;k<m2-n2+1;k++)
    {
      i=0,j=0;
      while(i<m1)
      {
              if(text[i][k]==pattern[j])
              {
                     if(j==n1-1)
                     {
                              //cout<<i-n2+2<<","<<k+1<<"\n";
                              v.pb(mp(i-n1+2,k+1));
                              j=F[j];
                              i++;
                     }
                     else
                     {
                         i++;
                         j++;
                     }
              }
              else if(j>0)
                   j=F[j-1];
              else
                   i++;
      }
    }
}
 
int main()
{
    string p[400],q[2005],temp;
    //vector <int> pattern;
    //vector <int> text[2005];
    map <string,int> m;
    scanf("%d%d",&n1,&n2);
    for(int i=0;i<n1;i++)
    {
      cin>>p[i];
      if(m.find(p[i])==m.end())
      {
          m[p[i]]=cnt;
          pattern.pb(cnt++);
      }
      else
          pattern.pb(m[p[i]]);
    }
    scanf("%d%d",&m1,&m2);
    for(int i=0;i<m1;i++)
      cin>>q[i];
    /*for(int i=0;i<n1;i++)
      cout<<pattern[i]<" ";
    cout<<"\n\n";*/
    for(int i=0;i<m1;i++)
    {
      for(int j=0;j<m2-n2+1;j++)
      {
        string temp=q[i].substr(j,n2);
        if(m.find(temp)!=m.end())
          text[i].pb(m[temp]);
        else
          text[i].pb(0);
      }
    }
    /*
    for(int i=0;i<m1;i++)
    {
      for(int j=0;j<m2-n2+1;j++)
        cout<<text[i][j]<<" ";
      cout<<"\n";
    }
    cout<<"\n\n";
    */
    KMP();
    if(v.size()==0)
        cout<<"NO MATCH FOUND...";
    else
    {
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout<<"("<<v[i].first<<","<<v[i].second<<")\n";
    }
}

