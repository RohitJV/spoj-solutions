#include <cstdio>
#include <cmath> 
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
 
using namespace std; 
 
#define SI(n) scanf("%d",&(n))
#define SS(n) scanf("%s",(n))
#define PIN(n) printf("%d\n",(n))
#define F(i,s,e) for(i=(s);i<(e);i++)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define LL long long int
#define ULL unsigned long long int
#define UL unsigned long  int
 
#define TYPE UL
#define N 10001
 
vector <int> a[N];
stack <int> st;
 
int d[N];
int v[N];
int vt;
 
int main()
{
  int i,j,tc,t,x,y,k;
	int n,m;
	SI(n);SI(m);
	F(i,0,m) {
	SI(x);SI(y);
	d[x]++;
	a[x].push_back(y);
 
	d[y]++;
	a[y].push_back(x);
	}
	if( n != m+1)
	printf("NO\n");
	else
	{
		F(i,1,n+1) if( d[i] == 1 ) { st.push(i); v[i]=1; }
		while( st.empty() != 1)
		{
			k = st.top(); st.pop();
			//printf(" PROCESS %d \n", k);
			vt++;
			y=a[k].size();
			for(j=0;j<y;j++) {
				if( a[k][j] )
				{
					x = a[k][j];
					if(v[x] ) continue;
					//printf("ADDING %d \n", x);
					d[x]--;
					if( d[x] == 1 ) { st.push(x); v[x] = 1;}
				}
			}
		}
		if( vt == n )
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}