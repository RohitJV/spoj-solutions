#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
# define f(i,a,b) for(int i=a;i<b;i++)
# define tt <<"\t"<<
# define Clear(x) memset(x,0,sizeof(x))
# define fill(x,a) memset(x,a,sizeof(x))
# define pb push_back
# define mp make_pair
# define X first
# define Y second
# define inf (~(1<<31))
# define linf (~(1LL<<63LL))
# define sqr(x) ((x)*(x))


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< vector <int > > vvi;
typedef pair <ll, ll > ill;


template <class T>
inline void ri(T &i){
bool minus=false;
char c;for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-'){minus=true;c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)i=(~i)+1;
}

int n,M,ht;

vector<pair< pair<int, int> , int > > ride;

int pre[1009][101];
int mh[1009][101];

#define cp(x) {for(int i=0;i<1009;i++)for(int j=0;j<101;j++)pre[i][j]=x[i][j]; }



int levels_he_can_complete(int H){
	fill(mh,-1);
	mh[M][0]=H;
	for(int ind=0;ind<n;ind++){
		//update hieght
		cp(mh);
		for(int i=0;i<1009;i++){
			for(int j=0;j<101;j++){
				int mhpos=pre[i][j];
				if(mhpos!=-1){
					if(mhpos>=ride[ind].X.X){
						if(i>=ride[ind].X.Y){
							mh[i-ride[ind].X.Y][j+1]=max(mh[i-ride[ind].X.Y][j+1],
							pre[i][j]+ ride[ind].Y );
						}
					}
				}
				
			}
			
			
		}
		
	}
	
	int ans=0;
	for(int i=0;i<1009;i++){
		for(int j=0;j<101;j++){
			if(mh[i][j]!=-1){
				ans=max(ans, j);
			}
		}
	}
	
	return ans;
}



int main(){
	//input
	ri(n);ri(M);ri(ht);
	ride.resize(n);
	f(i,0,n){
		int x,y,z;
		ri(x);ri(y);ri(z);
		ride[i]=mp(mp(x,y),z );
	}
	
	sort(ride.begin(),ride.end());
	int max_levels = levels_he_can_complete(ht);
	/*
	int lo=0;int hi=ht;
	int mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		int lvl=levels_he_can_complete(mid);
		if(lvl<max_levels){
			lo=mid+1;
		}
		else{
			hi=mid;
		}
	}
	
	*/
	printf("%d\n",max_levels);
	
	
	return 0;
}













