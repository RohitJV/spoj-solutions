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
#define MAX 1000005
#define NIL 0
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);

vector <int> G[MAX];
int n,m,p,match[MAX],dist[MAX];

bool bfs() {
	queue <int> q;
	for(int i=1;i<=n;i++) {
		if(match[i]==NIL) {
			dist[i]=0;
			q.push(i);
		}
		else
			dist[i]=INF;
	}
	dist[NIL]=INF;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(u!=NIL) {
			int sz=G[u].size();
			for(int i=0;i<sz;i++) {
				int v=G[u][i];
				if(dist[match[v]]==INF) {
					dist[match[v]]=dist[u]+1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

int dfs(int u) {
	if(u!=NIL) {
		int sz=G[u].size();
		for(int i=0;i<sz;i++) {
			int v=G[u][i];
			if(dist[match[v]]==dist[u]+1) {
				if(dfs(match[v])) {
					match[u]=v;
					match[v]=u;
					return true;
				}
			}
		}
		dist[u]=INF;
		return false;
	}
	return true;
}

int hopcroft_karp() {
	int matching=0;
	while(bfs()) {
		for(int i=1;i<=n;i++) 
			if(match[i]==NIL && dfs(i))
				matching++;
	}
	return matching;
}

int main() {
	int x,y;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<p;i++) {
		scanf("%d%d",&x,&y);
		y=y+n;
		G[x].pb(y);
		G[y].pb(x);
	}
	cout<<hopcroft_karp();
}