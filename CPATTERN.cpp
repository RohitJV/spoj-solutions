#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;

#define pb push_back
#define mp make_pair

int n,q,s,count=0;
int pattern[25001],text[100001];
int F[100001];
int pos[30];
bool visited[25001];
int v[3][25001];
vector <int> ans;
int lo,mid,hi;

void failure_func()
{
     int i,j;
     F[0]=0;
     j=0;
     i=1;

     pos[pattern[0]]=0;

     while(i<q)
     {

                for(int k=0;k<pattern[i];k++)
                    if(pos[k]!=-1)
                        v[0][i]=i-pos[k];
                for(int k=26;k>pattern[i];k--)
                    if(pos[k]!=-1)
                        v[2][i]=i-pos[k];
                if(pos[pattern[i]]!=-1)
                    v[1][i]=i-pos[pattern[i]];
                pos[pattern[i]]=i;

            lo=v[0][j];
            mid=v[1][j];
            hi=v[2][j];
            if( (mid==-1 || pattern[i-mid]==pattern[i]) && (lo==-1 || pattern[i-lo]<pattern[i]) && (hi==-1 || pattern[i-hi]>pattern[i]) )
            {
                F[i]=j+1;
                i++;
                j++;
            }
            else if(j>1)
                j=F[j-1];
            else
                F[i++]=1;
     }
}

void KMP()
{
    failure_func();
    int i=0,j=0;

    while(i<n)
    {
        lo=v[0][j];
        mid=v[1][j];
        hi=v[2][j];
        if( (mid==-1 || text[i-mid]==text[i]) && (lo==-1 || text[i-lo]<text[i]) && (hi==-1 || text[i-hi]>text[i]) )
        {
            if(j==q-1)
            {
                ans.pb(i-q+2);
                j=F[j];
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else if(j>1)
            j=F[j-1];
        else
            i++;
    }
}

int main()
{
    scanf("%d%d%d",&n,&q,&s);
    for(int i=0;i<n;i++)
        scanf("%d",&text[i]);
    for(int i=0;i<q;i++)
        scanf("%d",&pattern[i]);
    memset(pos,-1,sizeof(pos));
    memset(v,-1,sizeof(v));
    KMP();
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
}




