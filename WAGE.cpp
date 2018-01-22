#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>
#include <utility>
#include <fstream>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF -1
#define MAX 10000007
#define X first
#define Y second
#define all(x) x.begin(),x.end()
#define fi freopen("input.txt","r",stdin);
#define REP(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> pii;

int t,n,m,d;
char a[2][105][105];

int check(char x,char y) {
    if(x=='W') {
        if(y=='A')
            return 'W';
        if(y=='W')
            return 'W';
        if(y=='G')
            return 'G';
    }
    if(x=='A') {
        if(y=='A')
            return 'A';
        if(y=='W')
            return 'W';
        if(y=='G')
            return 'A';
    }
    if(x=='G') {
        if(y=='A')
            return 'A';
        if(y=='W')
            return 'G';
        if(y=='G')
            return 'G';
    }
}

int main()
{
 //   fi;
    cin>>t;
    while(t--) {
        cin>>n>>m>>d;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[0][i][j];
        for(int k=0;k<d;k++) {
            int cur=k%2;
            int nxt=(cur+1)%2;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    a[nxt][i][j]=a[cur][i][j];
                    bool mark=false;
                    if(!mark && j-1>=0) {
                        a[nxt][i][j]=check(a[cur][i][j],a[cur][i][j-1]);
                        if(a[cur][i][j]!=a[nxt][i][j])
                            mark=true;
                    }
                    if(!mark && i-1>=0) {
                        a[nxt][i][j]=check(a[cur][i][j],a[cur][i-1][j]);
                        if(a[cur][i][j]!=a[nxt][i][j])
                            mark=true;
                    }
                    if(!mark && i+1<n) {
                        a[nxt][i][j]=check(a[cur][i][j],a[cur][i+1][j]);
                        if(a[cur][i][j]!=a[nxt][i][j])
                            mark=true;
                    }
                    if(!mark && j+1<m) {
                        a[nxt][i][j]=check(a[cur][i][j],a[cur][i][j+1]);
                        if(a[cur][i][j]!=a[nxt][i][j])
                            mark=true;
                    }
                    if(!mark && i-1<0 && j-1<0 && i+1>=n && j+1>=m) {
                        a[nxt][i][j]=a[cur][i][j];
                        if(a[cur][i][j]!=a[nxt][i][j])
                            mark=true;
                    }
                    //cout<<a[nxt][i][j];
                }
                //cout<<"\n";
            }
            //cout<<"\n";
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                cout<<a[d%2][i][j];
            cout<<"\n";
        }
    }
}
