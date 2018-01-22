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
#define MAX 500
#define NIL 0
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);

typedef pair<int,int> pii;

int k,t,p,G[MAX][MAX],matchL[MAX],matchR[MAX],seen[MAX];
vector <pii> T,P;
long long s,c;

bool bpm(int u) {
	for(int v=0;v<t;v++) {
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
	int x,y;
	scanf("%d",&k);
	while(k--) {
		int ans=0;
		memset(G,0,sizeof(G));
		memset(matchL,-1,sizeof(matchL));
		memset(matchR,-1,sizeof(matchR));
		P.clear();
		T.clear();
		scanf("%d%d",&p,&t);
		//scanf("%lld%lld",&s,&c);
		cin>>s>>c;
		s=s*c;
		for(int i=0;i<p;i++) {
			scanf("%d%d",&x,&y);
			P.pb(pii(x,y));
		}
		for(int i=0;i<t;i++) {
			scanf("%d%d",&x,&y);
			T.pb(pii(x,y));
		}
		for(int i=0;i<p;i++) {
			for(int j=0;j<t;j++) {
				if( abs(P[i].X-T[j].X) + abs(P[i].Y-T[j].Y) <= s/200) {
					G[i][j]=1;
				}
			}
		}

		for(int i=0;i<p;i++) {
			memset(seen,0,sizeof(seen));
				if(bpm(i))
					ans++;
		}
		cout<<ans<<"\n";
	}
}