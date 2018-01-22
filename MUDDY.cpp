#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <utility>
#include <map>
#include <set>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 2505
#define NIL 0
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);

int n,m,t,x,y;
int matchL[MAX],matchR[MAX],G[MAX][MAX],seen[MAX],ans=0,h[100][100],v[100][100],v1,v2;
char s[100][100];

bool bpm(int u) {
	for(int v=0;v<v2;v++) {
		if(!G[u][v] || seen[v])
			continue;
		seen[v]=1;
		if(matchR[v]==-1 || bpm(matchR[v])) {
			matchR[v]=u;
			matchL[u]=v;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d",&t);
	while(t--) {
		ans=0;
		memset(G,0,sizeof(G));
		memset(matchL,-1,sizeof(matchL));
		memset(matchR,-1,sizeof(matchR));
		memset(h,-1,sizeof(h));
		memset(v,-1,sizeof(v));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>s[i][j];
		v1=-1,v2=-1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(s[i][j]=='*') {
					if(j==0 || h[i][j-1]==-1)
						h[i][j]=++v1;
					else
						h[i][j]=h[i][j-1];

					if(i==0 || v[i-1][j]==-1)
						v[i][j]=++v2;
					else
						v[i][j]=v[i-1][j];
				}
			}
		}
		if(v1==-1)
			cout<<"0\n";
		else {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(s[i][j]=='*') {
						//cout<<h[i][j]<<","<<v[i][j]<<"\n";;
						G[ h[i][j] ][ v[i][j] ]=1;
					}
				}
			}
			v1++;
			v2++;
			for(int i=0;i<v1;i++) {
				memset(seen,0,sizeof(seen));
				if(bpm(i))
					ans++;
			}
			cout<<ans<<"\n";
		}
	}
}